#ifndef JOUEUR_H
#define JOUEUR_H

class Joueur:public Client{
 private:
  int jeton;
  bool actif;
  bool fold;
 public:
  Joueur();
  Joueur(int jetonEchange);
};
#endif
