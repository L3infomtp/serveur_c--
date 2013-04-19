#ifndef SPECTATEUR_H
#define SPECTATEUR_H
#include <iostream>
#include<string.h>

using namespace std;

class Spectateur{
 private:
  int descSpectateur;
  string nom;
  float argent;
  bool actif;

 public:
  Spectateur();
  Spectateur(int);
  Spectateur(int,string,float);
  
  int getDescSpectateur()const;
  string getNom()const;
  float getArgent()const;
  bool isActif()const;

  void setDescSpectateur(const int&);
  void setNom(const string&);
  void setArgent(const float&);
  void setActif(const bool&);
};
#endif
