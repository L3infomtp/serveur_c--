#pragma once

#ifndef _PAQUET_H
#define _PAQUET_H
#include <string>

#include "Carte.h"

using namespace std;

extern string valeurs[13];
extern string habillages[4];

class Paquet
{
      private:
      Carte cartes[52]; //Initialisation du paquet
      int hauteur; 
      
      public:
      Paquet();
      void AffichagePaquet();
      void MelangerPaquet();
      
      //Tire une carte en haut du paquet
      Carte TirerUneCarte();
   
      
};

#endif
