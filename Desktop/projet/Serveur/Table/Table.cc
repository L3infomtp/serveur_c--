#include "Table.h"

Table::Table(int p,int e,int r,string name,int jMax,int mise){
  port=p;
  descEnvoie=e;
  descRecu=r;
  nomTable=name;
  nbJ=0;
  nbJMax=jMax;
  miseDep=mise;
}

int Table::getDescEnvoie()const{return descEnvoie;}
int Table::getDescRecu()const{return descRecu;}
int Table::getNbJ()const{return nbJ;}
int Table::getNbJMax()const{return nbJMax;}
string Table::getNomTable()const{return nomTable;}
int Table::getMiseDep()const{return miseDep;}
int Table::getPort()const{return port;}

void Table::setDescEnvoie(const int d){descEnvoie=d;}
void Table::setDescRecu(const int d){descRecu=d;}
void Table::setNomTable(const string name){nomTable=name;}
void Table::setMiseDep(const int mise){miseDep=mise;}

void Table::augmenterNbJ(){nbJ++;}
void Table::diminuerNbJ(){nbJ--;}
