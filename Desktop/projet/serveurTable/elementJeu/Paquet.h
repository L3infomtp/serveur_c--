#ifndef PAQUET_H
#define PAQUET_H
/**
*\file Paquet.h
*\brief Header de la classe Paquet du point de vue d'une table.
*\author Maryan Ludwiczak
*\date 10 avril 2013
*/
#include <vector>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include "Carte.h"
using namespace std;
/** *\class Paquet Paquet.h "/media/USB20FD/proker/*serveurTable/elementJeu"
*\brief classe représentant un paquet de cartes
*/ 

class Paquet{
    private:
        vector<Carte> cartes; /** vector contenant des instances de la classe Carte
        * représentant les cartes du paquet*/
    public:
    	  /**
    	  * \brief Constructeur par défaut
    	  * 
    	  * Constructeur par défaut de la classe Paquet
    	  */
        Paquet();
        /**
        * \brief Sortir une carte du paquet
        *
        * Méthode qui sort une carte déterminée aléatoirement
        * du paquet, ladite carte est supprimé du vector cartes 
        */ 
        Carte sortirCarte();
        /**
        * \brief Réinitialisation du paquet
        *
        * Le paquet est réinitialisé en cas de nouvelle partie
        */
	  void initialiserPaquet();
        int getTaille();
};

#endif
