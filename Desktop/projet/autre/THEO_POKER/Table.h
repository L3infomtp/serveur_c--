#pragma once

#ifndef _TABLE_H
#define _TABLE_H

#include "Joueurs.h"
#include "Paquet.h"
#include "Gagnant.h"

using namespace std;


//Simule une table de poker de 6 joueurs
class Table{
      private:
        Joueur joueurs[6];
        Paquet PaquetDuJeu;
        int blind;
        Carte CartesTable[5];
        int pot,action,mise,rational,betOn,winner,maxPoints,roundWinner;
        int pointsMain[6];
        int meilleurMains[6][3];
        
        public:
		Table();
        //uniquement pour test
        void setCartesTable(Carte p_cartes[5]);
        void Demarrer(string name);
        void setJoueur(int num,Joueur newjoueur);
        void DistributionDesJeux();
        void DistributionFlop();
        void DistributionTurn();
        void DistributionRiver();
        int JoueursRestant();
        //Verifier si il y a quelqu'un encore qui a parier ou caller
        int VerifieSiJoueursMise();
        //Obtenir le numéro du joueur Gagnant
        int ObtenirNumeroGagnant();
        //Retournera le numero des joueurs gagnants
        Gagnant SavoirGagnant();
        //Obtenir le nombre de point d'une main specifié en parametre
        int ObtenirPointMain(Carte main[]);

		//Evalue la main d'un joueur - combiné avec EssayerMain
		void EvaluerMain();

		//Essayer la main avec les différentes combinaisons possible
		int EssayerMain(int[],int);
        
        
       
};

static int comparerCartes(const void *cartes1, const void *cartes2);
#endif
