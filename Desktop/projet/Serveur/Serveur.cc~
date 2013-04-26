#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <pwd.h>
#include <unistd.h>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <errno.h>
//#include "mysql/mysql.h"
#include "/usr/local/mysql5/include/mysql/mysql.h"
#include "sock/sock.h"
#include "sock/sockdist.h"
#include "Serveur.h"
//export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/mysql5/lib/mysql/

//#include "Table.h"
#include "ClientVuServeur/Client.h"

#define PSEUDO 0
#define PASSWORD 1
#define MONEY 2
#define EMAIL 3
#define DOB 4
#define GENDER 5
#define LNAME 6
#define FNAME 7
#define ADRESS 8
#define CITY 9
#define ZIPCODE 10
#define COUNTRY 11

//#include <vector>
using namespace std;
const char separateur[2]="&";
char path[]="/auto_home/jlagniez/Desktop/projet/serveurTable/table";
int parcoursTableauNom=0;
const int maxNom=42;
int nbJoueurTable=2;
string nomTable[maxNom]={"New York", "Los Angeles","Istanbul" ,
		 "Texas", "Paris", "Londres", 
		 "Tokyo", "Pekin", "Barcelone",
		 "Amsterdam","Oslo","Moscou",
		 "Le Caire", "Dakar","Nairobi",
		 "Johannesburg","Rio De Janeiro","Lima",
		 "Buenos Aires","Mexico","La Havane",
		 "New Delhi","Sydney","Chicago",
		 "Washington","San Francisco","Sao Paulo",
		 "Nagoya","Djakarta","Lagos",
		 "Mumbai","Hong Kong","Taipei",
		 "Monaco","Montpellier","Lens",
		 "Séoul","Alaska","Lille",
		 "Narbonne","Tunis","Madrid"};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Constructeur/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Serveur::Serveur(char* env[]){
  //Creer la boite reseau public avec numero de port=21345
  cout<<nomTable[0]<<endl;
  descLectMax=0;
  this->env=env;
  for(int i=0;i<10;i++){
    creerTable();
  }
  brPub=Sock(SOCK_STREAM, (short)21345,0);
  //Creer le descripteur à surveiller en lecture
  if(brPub.good()) descBrPub=brPub.getsDesc();
  else
    {
      cout<<"Problème de l'init du descripteur de la boite reseau public"<<endl;
      exit(1);
    }
  if(descBrPub>descLectMax)
    descLectMax=descBrPub;
  //Longeur file d'attente
  if(listen(descBrPub,100)==-1)
    {
      cout<<"Liste d'attende mal crée"<<endl;
      exit(1);
    }
  
  tabClient=vector<Client*>();
  tailleVecteur=0;
  nbJ=0;
}
Serveur::~Serveur(){
  cout<<"Je détruis tous, je suis hulk"<<endl;
  for(int i=0;i<tabClient.size();i++){
    delete tabClient[i];
  }
  for(int i=0;i<tabTable.size();i++){
    close(tabTable[i].getDescEnvoie());
    close(tabTable[i].getDescRecu());
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////get,set et is///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//ICI!!!

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Methode tournant tous le temps/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
void Serveur::lanceServeur(){
  string sortieBoucle="";
  int cpt;
  cout<<"Bienvenu"<<endl;
  while(sortieBoucle != "sortie"){
    cout<<"Boucle du select"<<endl;
    //Initialise à faux l'ensemble de lecture à surveiller et positionne à vrai les descripteurs à surveiller
    if(nbJ>(30*(tabTable.size()/10))){
      for(int i=0;i<10;i++){
	creerTable();
      }
    }
    FD_ZERO(&desc_en_lect);
    FD_SET(descBrPub,&desc_en_lect);
    FD_SET(0,&desc_en_lect);
    for(cpt=0;cpt<tabClient.size();cpt++){
      FD_SET(tabClient[cpt]->getDescClient(),&desc_en_lect);
    }
    for(int i=0;i<tabTable.size();i++){
      FD_SET(tabTable[i].getDescRecu(),&desc_en_lect);
    }
    int retourSelect=select(descLectMax+1, &desc_en_lect,NULL,NULL,NULL);
    //Si erreur au select 
    if(retourSelect==-1){
      erreur();
    }
    else{
      //Si c'est le descripteur d'écriture qui à changé
      if(FD_ISSET(0,&desc_en_lect)){
	string msg;
	cin>>msg;
	if(msg=="sortie"){
	  while(!tabClient.empty()){
	    close(tabClient.back()->getDescClient());
	    delete tabClient.back();
	    tabClient.pop_back();
	  }
	  close(descBrPub);
	  sortieBoucle=msg;
	}
      }
 
      else{
	if(FD_ISSET(descBrPub,&desc_en_lect)){
	  accepterClient();
	}
	else{
	  int parcoursClient=0;
	  int parcoursTable=0;
	  bool sortieParcours=true;
	  while(sortieParcours && parcoursClient!=tailleVecteur)
	    {
	      if(FD_ISSET(tabClient[parcoursClient]->getDescClient(),&desc_en_lect))
		{
		  actionClient(parcoursClient);
		  sortieParcours=false;
		}
	      else
		{
		  parcoursClient++;
		}
	    }
	  //Regarde si y a eu une action d'une table
	  while(sortieParcours && parcoursTable!=tabTable.size())
	    {
	      if(FD_ISSET(tabTable[parcoursTable].getDescRecu(),&desc_en_lect)){
		actionTable(parcoursTable);
		sortieParcours=false;
	      }
	      else{
		parcoursTable++;
	      }
	    }
	}
      }
    }
  }
}
void Serveur::creerTable(){
  string nom="";
  if(parcoursTableauNom<maxNom){
    nom=nomTable[parcoursTableauNom];
  }
  else{
    nom=string("Table");
  }
  cout<<nom<<endl;
  parcoursTableauNom++;
  int nbJ=nbJoueurTable;
  nbJoueurTable++;
  if(nbJoueurTable==11){
    nbJoueurTable=2;
  }
  int miseD=100;
  int serveurTable[2];
  int tableServeur[2];


  if(pipe(serveurTable)!=0)
    exit(1);
  
  if(pipe(tableServeur)!=0)
    exit(1);

  if(fork()==0){
    close(serveurTable[1]);
    close(tableServeur[0]);
    char tabSer[10]="";
    sprintf(tabSer,"%d",tableServeur[1]);
    char serTab[10]="";
    sprintf(serTab,"%d",serveurTable[0]);
    char nbJChar[10]="";
    sprintf(nbJChar,"%d",nbJ);
    char miseChar[10]="";
    sprintf(miseChar,"%d",miseD);
    char *argument[6]={path,tabSer,serTab,nbJChar,miseChar,NULL};
    
     if(execve(path,argument,env)==-1){
      perror("execve");
      exit(1);
      }
  }
  else{
    close(serveurTable[0]);
    close(tableServeur[1]);
    if(tableServeur[0]>descLectMax){
      descLectMax=tableServeur[1];
    }
    char port[20]="";
    int erreur=read(tableServeur[0],port,20);
    if(erreur==0 || erreur==-1 ){
      perror("read");
    }
    else{
      cout<<"Le numero port est de : "<<port<<endl;
      tabTable.push_back(Table(atoi(port),serveurTable[1],tableServeur[0],nom,nbJ,miseD));
    }
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Methode//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Serveur::accepterClient(){
  //On accepte le nouveau client et on définie son descripteur de sa boite reseau de circuit virtuel
  struct sockaddr_in brCV;
  socklen_t lgbrCV=sizeof(struct sockaddr_in); 
  int descBrCv = accept(descBrPub,(struct sockaddr *)&brCV, &lgbrCV);
  if(descBrCv==-1){
    cout<<"N'a pas accepté le client"<<endl;
  }
  else{
    cout<<"Un client veut se connecter"<<endl;
    char pseudoMdp[52]="";
    int retourConexion=recv(descBrCv,pseudoMdp,52,0);
    if(retourConexion==0){
      cout<<"Probleme de l'envoie du client"<<endl;
      close(descBrPub);
    }
    else{
      string pseudo;
      string mdp;
      cout<<pseudoMdp<<endl;
      convertionPseudoMdpClient(pseudoMdp,pseudo,mdp);
      Client* cl=connexionClientBDD(descBrCv,pseudo,mdp);
      if(cl != NULL){
	cout<<"Nouveau client"<<endl;
	if(descLectMax<descBrCv){
	  descLectMax=descBrCv;
	}
	//Client* cl=new Client(descBrCv,"Azerty",100);
	tabClient.push_back(cl);
	tailleVecteur++;
	char buffer[2048]="";
	convertionClientChar(buffer,cl);
	//convertionTableChar(buffer);
	//cout<<buffer<<endl;
	int envoie=send(cl->getDescClient(),buffer,2048,0);

	if(envoie==-1){
	  cout<<"Erreur au send quand on a accepter un client"<<endl;
	  erreur();
	}
      }
      else{
	cout<<"oh le noob ce client, il a fait une erreur sur ces id ah ah!"<<endl;
	close(descBrCv);
      }
    }
  }
}


void Serveur::erreur(){
  cout<<"Erreur"<<endl;
  while(!tabClient.empty()){
    close(tabClient.back()->getDescClient());
    delete tabClient.back();
    tabClient.pop_back();
  }
  close(descBrPub);
  exit(1);  
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////Action d'un client/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Serveur::actionClient(int placeVecteur){
  char recuClient[256]="";
  int taille=recv(tabClient[placeVecteur]->getDescClient(),recuClient,256,0);
  if(taille==0)
    {
      ///////Modifier selon les tables//////
      decoClient(placeVecteur);
      
      //////////////////////////////////////
    
    }
  else{
    cout<<recuClient<<endl;
    
    if(recuClient[0]=='M' && recuClient[1]=='o' && recuClient[2]=='d' && recuClient[3]=='i' && recuClient[4]=='f'){
      modifClient(recuClient+6,tabClient[placeVecteur]);
      return;
    }
    else{
      if(recuClient[0]=='T' && recuClient[1]=='c' && recuClient[2]=='h' && recuClient[3]=='a' && recuClient[4]=='t'){
	msgClient(recuClient);
	return;
      }
      else{
	if(recuClient[0]=='R' && recuClient[1]=='a' && recuClient[2]=='f' && recuClient[3]=='r' && recuClient[4]=='T'){
	  envoieTable(tabClient[placeVecteur]->getDescClient());
	  //char buffer[300];
	  //convertionTableChar(buffer);
	  //send(tabClient[placeVecteur]->getDescClient(),buffer,300,0);
	  return;
	}
      }
    }
  }
  
  //1-Soit il veut juste voir son profil
  //2-Soit il veut rejoindre une table
  //3-Soit il parle dans le chan
  //4-Soit il quitte le jeu
  //5-Modif son profil
}

void Serveur::decoClient(int placeVecteur){
    ///////Modifier selon les tables//////
      cout<<tabClient[placeVecteur]->getNom()<<" est deconnecté"<<endl;
      close(tabClient[placeVecteur]->getDescClient());
      delete tabClient[placeVecteur];
      tabClient.erase(tabClient.begin()+placeVecteur);
      tailleVecteur--;
      //////////////////////////////////////
  }

void Serveur::msgClient(char* tchat){
   cout<<tchat<<endl;
   for(int i=0;i<tailleVecteur;i++){
     int envoi=send(tabClient[i]->getDescClient(),tchat,255,0);
   }
 }   
 

/**********************************************************************************************************************************************************************************************************************************************/

/////////////////////                 //////////////////////
////////////////////Action des tables///////////////////////
///////////////////                 ////////////////////////

void Serveur::actionTable(int place){
  char buf[255]="";
  int taille=read(tabTable[place].getDescRecu(),buf,255);
  cout<<"Le message est  "<<buf<<endl;
  int cpt=0;
  if(taille==0){
    cout<<"La table est suprimé"<<endl;
    close(tabTable[place].getDescRecu());
    close(tabTable[place].getDescEnvoie());
    tabTable.erase(tabTable.begin()+place);
    return;
  }
  if(buf[cpt]=='N' && buf[cpt+1]=='e' && buf[cpt+2]=='w' && buf[cpt+3]=='J' && buf[cpt+4]=='o'){
    cout<<"NewJo"<<endl;
    tabTable[place].augmenterNbJ();
    nbJ++;
    cpt+=6;
  }
  else{
    if(buf[cpt]=='Q' && buf[cpt+1]=='u' && buf[cpt+2]=='i' && buf[cpt+3]=='t' && buf[cpt+4]=='J'){
      cout<<"QuitJ"<<endl;
      tabTable[place].diminuerNbJ();
      nbJ--;
      cpt+=6;
    }
  }
}


/////////////////Action sur les bases de données////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Client* Serveur::connexionClientBDD(const int descCli,const string pseudo,const string mdp){
  Client* cl=NULL;
  bool joueurExiste=false;
  char test='a';
  MYSQL utilisateur;
  mysql_init(&utilisateur);
  const char* option="option";
  mysql_options(&utilisateur,MYSQL_READ_DEFAULT_GROUP,option);
  //Chez jm
  //if(mysql_real_connect(&utilisateur,"localhost","root","azertySQL","pokerL3",0,NULL,0)){ 
  //Chez la fac
  if(mysql_real_connect(&utilisateur,"venus","flucia","flucia","flucia",0,NULL,0)){
    mysql_query(&utilisateur,"LOCK TABLES infoclients WRITE");
    mysql_query(&utilisateur,"SELECT * FROM infoclients");
    
    MYSQL_RES * result =NULL;
    MYSQL_ROW row;

    unsigned int i=0;
    unsigned int nb_champs=0;

    result = mysql_store_result(&utilisateur);
    
    nb_champs=mysql_num_fields(result);

    while(!joueurExiste && (row = mysql_fetch_row(result))){

      if(row[PSEUDO] == pseudo && row[PASSWORD]==mdp){
	joueurExiste=true;
      }
    }
    if(joueurExiste){
      stringstream ss(row[MONEY]);
      int argent=0;
      ss >> argent;
      cl= new Client(descCli,pseudo,argent,row[EMAIL],row[DOB],row[GENDER],row[LNAME],row[FNAME],row[ADRESS],row[CITY],row[ZIPCODE],row[COUNTRY]);
    }
    mysql_query(&utilisateur,"UNLOCK TABLES");
    mysql_close(&utilisateur);
  }
  else{
    cout<<"Erreur de la connexion à la base de donnée"<<endl;
    }
  
  return cl;
}

void Serveur::modifClient(char* modification,Client* cl){
  cout<<"Modification de donnée"<<endl;
  int cpt=0;
  char entierAConvertir[2];
  while(modification[cpt]!='&'){
    entierAConvertir[cpt]=modification[cpt];
    cpt++;
  }
  int colonne=atoi(entierAConvertir);
  cout<<colonne<<endl;
  MYSQL utilisateur;
  mysql_init(&utilisateur);
  const char* option="option";
  mysql_options(&utilisateur,MYSQL_READ_DEFAULT_GROUP,option);
  //Chez la fac
  if(mysql_real_connect(&utilisateur,"venus","flucia","flucia","flucia",0,NULL,0)){
  //Chez jm
  //if(mysql_real_connect(&utilisateur,"localhost","root","azertySQL","pokerL3",0,NULL,0)){   
    switch(colonne){
    case PASSWORD:
      {
      /////Penser à encrypter merci....
	
	string requete="update infoclients set Password='"+string(strtok(modification+cpt+1,separateur))+"' where Username='"+cl->getNom()+"'";
	mysql_query(&utilisateur,"LOCK TABLES infoclients WRITE");
	mysql_query(&utilisateur,requete.c_str());
	break;
      }
    case EMAIL:
      {
	string requete="update infoclients set Email='"+string(strtok(modification+cpt+1,separateur))+"' where Username='"+cl->getNom()+"'";
	mysql_query(&utilisateur,"LOCK TABLES infoclients WRITE");
	mysql_query(&utilisateur,requete.c_str());
	break;
      }
    case DOB:
      {
	cout<<"2"<<endl;
	string requete="update infoclients set DOB='"+string(strtok(modification+cpt+1,separateur))+"' where Username='"+cl->getNom()+"'";
	mysql_query(&utilisateur,"LOCK TABLES infoclients WRITE");
	mysql_query(&utilisateur,requete.c_str());
	break;
      }
    case GENDER:
      {
	cout<<"Le client veut modifier le genre(il a surement changé de sexe pendant la nuit, vous voyez)"<<endl;
	string requete="update infoclients set Gender='"+string(strtok(modification+cpt+1,separateur))+"' where Username='"+cl->getNom()+"'";
	mysql_query(&utilisateur,"LOCK TABLES infoclients WRITE");
	mysql_query(&utilisateur,requete.c_str());
	break;
      }
    case LNAME:
      {
	cout<<"2"<<endl;
	string requete="update infoclients set LName ='"+string(strtok(modification+cpt+1,separateur))+"' where Username='"+cl->getNom()+"'";
	mysql_query(&utilisateur,"LOCK TABLES infoclients WRITE");
	mysql_query(&utilisateur,requete.c_str());
	break;
      }
    case FNAME:
      {
	string requete="update infoclients set FName='"+string(strtok(modification+cpt+1,separateur))+"' where Username='"+cl->getNom()+"'";
	mysql_query(&utilisateur,"LOCK TABLES infoclients WRITE");
	mysql_query(&utilisateur,requete.c_str());
	break;
      }
    case ADRESS:
      {
	cout<<"Modification de l'adresse"<<endl;
	string requete="update infoclients set Adress='"+string(strtok(modification+cpt+1,separateur))+"' where Username='"+cl->getNom()+"'";
	mysql_query(&utilisateur,"LOCK TABLES infoclients WRITE");
	mysql_query(&utilisateur,requete.c_str());
	break;
      }
    case CITY:
      {
	string requete="update infoclients set City='"+string(strtok(modification+cpt+1,separateur))+"' where Username='"+cl->getNom()+"'";
	mysql_query(&utilisateur,"LOCK TABLES infoclients WRITE");
	mysql_query(&utilisateur,requete.c_str());
	break;
      }
    case ZIPCODE:
      {
	string requete="update infoclients set ZipCode="+string(strtok(modification+cpt+1,separateur))+" where Username='"+cl->getNom()+"'";
	mysql_query(&utilisateur,"LOCK TABLES infoclients WRITE");
	mysql_query(&utilisateur,requete.c_str());
	break;
      }
  case COUNTRY:
      {
	string requete="update infoclients set Country='"+string(strtok(modification+cpt+1,separateur))+"' where Username='"+cl->getNom()+"'";
	mysql_query(&utilisateur,"LOCK TABLES infoclients WRITE");
	mysql_query(&utilisateur,requete.c_str());
	break;
      }
    default:
      {
	cout<<"Erreur quelque part dans la modification. Bonnne chance!"<<endl;
      }

    }
    mysql_query(&utilisateur,"UNLOCK TABLES");
    mysql_close(&utilisateur);
  }
  else{
    cout<<"Erreur de la connexion à la base de donnée"<<endl;
  }
}


/**********************************************************************************************************************************************************************************************************************************************/

/////////////////////Methode de convertion des types////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Serveur::convertionPseudoMdpClient(char* pseudoMdp,string& pseudo, string& mdp){
  cout<<pseudoMdp<<endl;
  unsigned int i=0;
  stringstream pseudoAConvertir;
  stringstream mdpAConvertir;
  while(i<strlen(pseudoMdp) && pseudoMdp[i]!='&'){
    i++;
  }
  char pseudoChar[20]="";
  char mdpChar[30]="";
  strncpy(pseudoChar,pseudoMdp,i);
  pseudoAConvertir<<pseudoChar;
  pseudoAConvertir>>pseudo;
  i++;
  int j=0;
  while(i<strlen(pseudoMdp) && pseudoMdp[i]!='&'){
    mdpChar[j]=pseudoMdp[i];
    i++;
    j++;
  }
  mdpAConvertir<<mdpChar;
  mdpAConvertir>>mdp;
  cout<<pseudo<<endl;
  cout<<mdp<<endl;
  
}

void Serveur::convertionClientChar(char* buffer,Client* cl){
  int taille=0;
  string pseudo=cl->getNom(); int taillePseudo=pseudo.size();
  strncpy(buffer,pseudo.c_str(),taillePseudo);
  taille+=taillePseudo;
  buffer[taille]='&';
  taille++;
  
  char money[64]=""; sprintf(money,"%f",cl->getArgent());
  int tailleArgent=strlen(money);
  strncpy(buffer+taille,money,tailleArgent);
  taille+=tailleArgent;
  buffer[taille]='&';
  taille++;
  
  string mail=cl->getEmail(); int tailleMail=mail.size();
  strncpy(buffer+taille,mail.c_str(),tailleMail);
  taille+=tailleMail;
  buffer[taille]='&';
  taille++;

  string date=cl->getDOB(); int tailleDate=date.size();
  strncpy(buffer+taille,date.c_str(),tailleDate);
  taille+=tailleDate;
  buffer[taille]='&';
  taille++;

  string genre=cl->getGender();int tailleGenre=genre.size();
  strncpy(buffer+taille,genre.c_str(),tailleGenre);
  taille+=tailleGenre;
  buffer[taille]='&';
  taille++;

  string nom=cl->getLName();int tailleNom=nom.size();
  strncpy(buffer+taille,nom.c_str(),tailleNom);
  taille+=tailleNom;
  buffer[taille]='&';
  taille++;
  
  string prenom=cl->getFName();int taillePrenom=prenom.size();
  strncpy(buffer+taille,prenom.c_str(),taillePrenom);
  taille+=taillePrenom;
  buffer[taille]='&';
  taille++;

  string adr=cl->getAdress();int tailleAdr=adr.size();
  strncpy(buffer+taille,adr.c_str(),tailleAdr);
  taille+=tailleAdr;
  buffer[taille]='&';
  taille++;

  string ville=cl->getCity();int tailleVille=ville.size();
  strncpy(buffer+taille,ville.c_str(),tailleVille);
  taille+=tailleVille;
  buffer[taille]='&';
  taille++;

  string code=cl->getZipCode();int tailleCode=code.size();
  strncpy(buffer+taille,code.c_str(),tailleCode);
  taille+=tailleCode;
  buffer[taille]='&';
  taille++;

  string pays=cl->getCountry();int taillePays=pays.size();
  strncpy(buffer+taille,pays.c_str(),taillePays);
  taille+=taillePays;
  buffer[taille]='&';
  //taille++;

 
}
void Serveur::convertionTableChar(char* buffer){
  char type[]="TInfo";
  cout<<"Avant ajout de la table"<<buffer<<endl;
  for(int i=0;i<tabTable.size();i++){
    strcat(buffer,type);
    strcat(buffer,separateur);
    strcat(buffer,tabTable[i].getNomTable().c_str());
    strcat(buffer,separateur);
    char portChar[10]="";
    sprintf(portChar,"%d",tabTable[i].getPort());
    strcat(buffer,portChar);
    strcat(buffer,separateur);
    char nbJChar[10]="";
    sprintf(nbJChar,"%d",tabTable[i].getNbJ());
    strcat(buffer,nbJChar);
    strcat(buffer,separateur);
    char nbJMax[10]="";
    sprintf(nbJMax,"%d",tabTable[i].getNbJMax());
    strcat(buffer,nbJMax);
    strcat(buffer,separateur);
    char miseChar[20]="";
    sprintf(miseChar,"%d",tabTable[i].getMiseDep());
    strcat(buffer,miseChar);
    strcat(buffer,separateur);
  }
}
void Serveur::envoieTable(int desc){
  for(int i=0;i<tabTable.size();i++){
    char buffer[100]="TInfo&";
    strcat(buffer,tabTable[i].getNomTable().c_str());
    strcat(buffer,separateur);
    char portChar[10]="";
    sprintf(portChar,"%d",tabTable[i].getPort());
    strcat(buffer,portChar);
    strcat(buffer,separateur);
    char nbJChar[10]="";
    sprintf(nbJChar,"%d",tabTable[i].getNbJ());
    strcat(buffer,nbJChar);
    strcat(buffer,separateur);
    char nbJMax[10]="";
    sprintf(nbJMax,"%d",tabTable[i].getNbJMax());
    strcat(buffer,nbJMax);
    strcat(buffer,separateur);
    char miseChar[20]="";
    sprintf(miseChar,"%d",tabTable[i].getMiseDep());
    strcat(buffer,miseChar);
    strcat(buffer,separateur);
    send(desc,buffer,100,0);
  }
}
/**********************************************************************************************************************************************************************************************************************************************/
