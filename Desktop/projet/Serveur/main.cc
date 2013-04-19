#include <iostream>
#include "Serveur.h"
using namespace std;

/*void gerante(int sig){
  cout<<"Stop les ctrl-C"<<endl;
  s.~Serveur();
  exit(1);
  
  }*/
int main(int argc, char* argv[],char* env[]){
  /*struct sigation action;
  action.sa_handler=gerante;
  sigaction(SIGINT,&action,NULL);*/
  Serveur s=Serveur(env);
  s.lanceServeur();
}
