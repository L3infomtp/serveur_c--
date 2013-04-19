#ifndef TABLE_H
#define TABLE_H

#include "Joueur.h"
#include"sock.h"
#include"sockdist.h"

class Table{
 private:
    Sock brPub;
    int descTable;
    fd_set descLec;
    int nbJoueur;
    const int nbJMax;
    vector<Joueur> joueurs;
    vector<Spectateur> spectacteurs;
    int miseMin;
    int pot;
    Paquet paquet;
    Carte[5] milieu;

 public:
    Table();
    Table(int);

  int getDescTable()const;
  int getNbJoueur()const;
  int getnbJMax()const;
  int getMiseMin()const;
  int getPot()const;
  Carte* getMilieu()const;
  Joueur getJoueur(int)const;
  Client getSpectateur(int)const;

  void addJoueur();
  void addSpectateur();
  void removeJoueur();
  void removeSpectateur();
  void run();
  void tourDeTable();
};

#endif // TABLE_H
