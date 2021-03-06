#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include "sock/sock.h"
#include "sock/sockdist.h"
#include "ClientC.h"

using namespace std;

//////////Les variables statics/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int nbColonneBdd=-1;
int action=0;
/**********************************************************************************************************************************************************************************/

///////////////////Fonction/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void clean_stdin(void){
  fflush(stdin);
}


char* getInput(char* messageUtilisateur){
  int cpt=0;
  do 
    {
      messageUtilisateur[cpt++]=(char)fgetc(stdin);
    } while(cpt < 256 && messageUtilisateur[cpt-1] != '\n' && messageUtilisateur[cpt-1] != EOF);
    messageUtilisateur[cpt-1]='\0';
    //clean_stdin();
  return messageUtilisateur;
} 
/**********************************************************************************************************************************************************************************/


///////////////////////Constructeur/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ClientC::ClientC(char* nomOrdi){


  //Creation de la boite reseau du circuit virtuel et de sa longeur 
  SockDist brPub(nomOrdi, (short)21345);
  adrBrPub=brPub.getAdrDist();
  lgAdrBrPub=sizeof(struct sockaddr_in);
  char pseudo[512]="";
  do
    {
      //Creer la boite reseau privé
      brPri=Sock(SOCK_STREAM,0);
       close(descbreCli);
      //Creer le descripteur de la boite reseau privé 
      if(brPri.good()) descbreCli=brPri.getsDesc();
      else{
	cout<<"pb BR privé"<<endl;
	exit(1);
      }
     
      char pseudoMdp[51]="";
      /////WARNING:Entre les id de l'utilisateur. A modif selon QT
      entrePseudoMdp(pseudoMdp);
      ////////
      //Se connecte au serveur
      int erlude=connect(descbreCli,(struct sockaddr *)adrBrPub,lgAdrBrPub);
      if(erlude ==-1)
	{
	  cout<<"Conexion ne marche pas "<<endl;
	  exit(1);
	}
      send(descbreCli,pseudoMdp,51,0);
      descLectMax=descbreCli;
      
    } while(recv(descbreCli,pseudo ,512,0)==0);
  joueur=Info(pseudo);
  cout<<joueur.toString()<<endl;;
}
/**********************************************************************************************************************************************************************************/

////Action du client sans interaction avec le serveur///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ClientC::entrePseudoMdp(char* pseudoMdp){
  cout<<"Quel est ton pseudo?"<<endl;
  cin>>pseudoMdp;
  pseudoMdp[strlen(pseudoMdp)]='&';
  char mdp[20]="";
  cout<<"Quel est ton mdp"<<endl;
  cin>>mdp;
  strcat(pseudoMdp,mdp);
}

/**********************************************************************************************************************************************************************************/


/********************************************************************************Methode tournant tous le temps********************************************************************/
void ClientC::lanceClient(){
  string quitter="";
  while(quitter != "quitter"){
    //Initialise à faux l'ensemble de lecture à surveiller et positionne à vrai les descripteurs à surveiller
    FD_ZERO(&desc_en_lect);
    FD_SET(descbreCli,&desc_en_lect);
    FD_SET(0,&desc_en_lect);
    clean_stdin();
    if(action==0){
      cout<<"Quel action faire?"<<endl;
      cout<<"1-Modif compte"<<endl;
      cout<<"2-Parler dans le chan"<<endl;
    }
    int retourSelect=select(descLectMax+1,&desc_en_lect,NULL,NULL,NULL);
    cout<<"Dans le select"<<endl;
    //Si erreur au select 
    if(retourSelect==-1){
      cout<<"Erreur au select"<<endl;
      close(descbreCli);
      exit(1);
    }
    else{
      //Si c'est le descripteur d'écriture qui à changé
      if(FD_ISSET(0,&desc_en_lect)){
	if(action==0){
	 
	  action=(int)fgetc(stdin);
	}
	else{
	  envoieServeur(action);
	}
      }
      else{
	//Si c'est le descripteur de la boite reseau privé qui à bougé
	if(FD_ISSET(descbreCli,&desc_en_lect)){
	  recuServeur();
	}
      }
    }
  }
}
/**********************************************************************************************************************************************************************************/


/******************************************************************************envoieServeur*******************************************************************************/

void ClientC::envoieServeur(const int actionAEffectuer){
  switch(actionAEffectuer)
    {
      //Represente 1
    case 49:
      envoieModif();
      clean_stdin();
      break;
      //Represente 2
    case 50:
      envoieTchat();
      //clean_stdin();
      break;
    default:
      cout<<"Erreur de saisie"<<endl;
      clean_stdin();
    }
  
  ////////////////////////////////////////////////////////////
}

void ClientC::envoieTchat(){
  //Prepare le message de chat
  char messageType[300]="Tchat";
  char pseudo[20];
  strcpy(pseudo,joueur.getNom().c_str());
  strcat(messageType,pseudo);
  messageType[strlen(messageType)]=':';
  char messageUtilisateur[256]="";
  cout<<"teste1"<<endl;
  getInput(messageUtilisateur);
  cout<<"teste2"<<endl;
  strcat(messageType,messageUtilisateur);
  //Envoie se que l'utilisateur à rentré
  int envoie=send(descbreCli,messageType,strlen(messageType),0);
  if(envoie==-1){
    cout<<"Erreur au send"<<endl;
    exit(1);
  }
  action=0;
}

void ClientC::envoieModif(){
  char messageModif[50]="Modif5&yeti";
  int envoie=send(descbreCli,messageModif,strlen(messageModif),0);
  if(envoie==-1){
    cout<<"Erreur au send"<<endl;
    exit(1);
  }
}
/**********************************************************************************************************************************************************************************/

/***********************************************Recu Serveur*******************************************************************************************************************************************************************************************/

void ClientC::recuServeur(){
  char messageServeur[256];
  int taille=recv(descbreCli,messageServeur,256,0);
  if(taille==0){
    cout<<"Le serveur ne fonctionne plus"<<endl;
    close(descbreCli);
    exit(1);
  }
  else{
    if(messageServeur[0]=='T' && messageServeur[1]=='c' && messageServeur[2]=='h' && messageServeur[3]=='a' && messageServeur[4]=='t'){
      recuTchat(messageServeur+5);
    }
  }
}

void ClientC::recuTchat(char* messageAAfficher){
  cout<<messageAAfficher<<endl;
}
/******************************************************************************************************************************************************************************************************************************************************/



