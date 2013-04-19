#ifndef _GAGNANT_H
#define _GAGNANT_H

#include "Joueurs.h"
#include <iostream>

using namespace std;

class Gagnant{
      
      int nbJouMax;
      int indicateur_gagnant;
      Joueur *gagnant_suceptible;
      
      public :
      Gagnant(int);
      void AjouterGagnant(Joueur);
      void AfficherGagnant();
};

#endif
