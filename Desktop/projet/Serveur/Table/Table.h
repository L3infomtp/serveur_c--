#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <string>
using namespace std;

class Table{
 private:
  int port;
  int descEnvoie;
  int descRecu;

  string nomTable;
  int nbJ;
  int nbJMax;
  int miseDep;
 public:
  Table(int,int,int,string,int,int);
  
  int getDescEnvoie()const;

  int getDescRecu()const;
  int getNbJ()const;
  int getNbJMax()const;
  string getNomTable()const;
  int getMiseDep()const;
  int getPort()const;
  
  void setDescEnvoie(const int);
  void setDescRecu(const int);
  void setNomTable(const string);
  void setMiseDep(const int);
  
  void augmenterNbJ();
  void diminuerNbJ();
};
#endif
