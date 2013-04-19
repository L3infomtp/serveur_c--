#ifndef JOUEUR_H
#define JOUEUR_H
#include "Spectateur.h"

class Joueur:public Spectateur{
 private:
  int Jeton;
  Carte cartes[2];
  bool fold;

 public:
  Joueur();
  Joueur(int&);
  Joueur(int&, Carte[2],bool&);

  int getJeton()const;
  Carte* getCartes()const;
  bool isFold()const;

  void setJeton(const int&);
  void setCartes(const Carte&);
  void setFold(const bool&);

  void saisie(istream&);
  void affiche(ostream&)const;
};

ostream& operator<<(ostream&, Joueur&);
istream& operator>>(istream&, Joueur&);
#endif
