#include "Table.h"

Table::Table(){
    nbJMax = 9;
    miseMin = 0;
    pot = 0;

    brPub = Sock(SOCK_STREAM, 0);
    if(brPub.good())
        descTable = brPub.getsDesc();
    else{
        cout<<"Probleme desc"<<endl;
        exit(1);
    }
    if(listen(descTable,10) == -1){
        cout<<"erreur de creation Boite Publique"<<endl;
        return 0;
    }
}

Table::Table(int JoueurMax){
    nbJMax = JoueurMax;
    miseMin = 0;
    pot = 0;

    brPub = Sock(SOCK_STREAM, 0);
    if(brPub.good())
        descTable = brPub.getsDesc();
    else{
        cout<<"Probleme desc"<<endl;
        exit(1);
    }
    if(listen(descTable,JoueurMax) == -1){
        cout<<"erreur file"<<endl;
        exit(1);
    }
}

int Table::getDescTable()const{
    return descTable;
}

int Table::getNbJoueur()const{
    return joueurs.size();
}

int Table::getnbJMax()const{
    return nbJMax;
}

int Table::getMiseMin()const{
    return miseMin;
}
int Table::getPot()const{
    return pot;
}

Carte* Table::getMilieu()const{
    return &milieu;
}

Joueur Table::getJoueur(int i)const{
    return joueurs[i];
}

Client Table::getSpectateur(int)const{
    return spectacteurs[i];
}

void Table::addJoueur(Joueur j){
    joueurs.push_back(j);
}

void Table::addSpectateur(Spectateur s){
    spectacteurs.push_back(s);
}

void Table::removeJoueur(int i){
    joueurs.erase(joueurs.begin()+i);
}

void Table::removeSpectateur(int i){
    spectateurs.erase(joueurs.begin()+i);
}

void Table::accepterClient(){
    struct sockaddr_in brCV;
    socklen_t lgbrCV=sizeof(struct sockaddr_in);
    int descBrCv = accept(descTable,(struct sockaddr *)&brCV, &lgbrCV);
    if(descBrCv==-1)
        cout<<"N'a pas acceptée le client"<<endl;
    else{
        char nomArgent[52];
        if((int messCli = recv(descBrCv,nomArgent,25,0))!=-1){
            nomArgent[messCli]='\0';
            string pseudo;
            float ag;
            recupNomArgent(nomArgent,pseudo, ag);
            spectateurs.push_back(Spectateur(descBrCv,pseudo,ag));
        }
        else{
            cout<<"Probleme recv client"<<endl;
        }
    }

}

void Table::recupNomArgent(char* src, string& nom, float& ag){
    int i = 0;
    string f;
    while(src[i]!='&'){
        nom.push_back(src[i]);
        i++;
    }
    i++;
    while(src[i]!='\0'){
       f.push_back(src[i]);
        i++;
    }
    ag = atof(f.c_str());
}



void Table::run();

void Table::tourDeTable(int i){
    int i=0;
    char message[1024];
    while(i!=nbJoueur){
        FD_ZERO(&descLec);
        FD_SET(descTable, &descLec);
        for(int j=0; j<spectateurs.size(); j++)
            FD_SET(spectacteurs[j].getDescSpectateur(), &descLec);

        int sel = select(spectacteurs.size()+1, &descLec, NULL, NULL, NULL);

        if(sel != -1){

            if(FD_ISSET(descBrPub,&descLec))
                accepterClient();

            for(int j = 0; j<spectacteurs.size(); j++){
                if(FD_ISSET(spectacteurs[j],&descLec)){

                    int recep = recv(spectacteurs[i].getDescSpectateur(), message, sizeof(message),0);
                    if(recep == -1){

                    }else if(recep == 0){

                    }else{
                        message[recep]='\0';
                        string prefixe;
                        for(int k=0; k<5;k++)
                            prefixe.push_back(message[k])
                        if(prefixe == "/mess"){

                        }else if(prefixe == "/fold"){

                        }else if(mess== "/cont"){

                        }

                    }
                }
            }

        }else{
            cout<<"Erreur SELECT"<<endl;
            exit(1);
        }
    }
}
