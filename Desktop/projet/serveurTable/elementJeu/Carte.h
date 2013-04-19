#ifndef CARTE_H
#define CARTE_H
/**
*\file Joueur.h
*\brief Header de la classe Carte du point de vue d'une table.
*\author Maryan Ludwiczak
*\date 10 avril 2013
*/
#include <iostream>
using namespace std;
/** *\class Carte Carte.h "/media/USB20FD/proker/*serveurTable/elementJeu"
*\brief classe représentant une carte
*
*/ 
class Carte{
    private:
        int valeur; /** Valeur de la carte représentée par un entier*/
        int couleur;/** Couleur de la carte représentée par un entier*/
    public:
    /**
    * \brief Constructeur par défaut
    *
    * Constructeur par défaut de la classe carte
    */
        Carte();
        /**
        * \brief Constructeur par copie
        *
        * Constructeur par copie de la classe Carte prenant
        * en paramètre une instance de la classe Carte
        *
        * \param carte: instance de la classe Carte que l'on va 
        * copier pour créer une nouvelle carte
        */
        Carte(const Carte& carte);
        /**
        * \brief Constructeur
        *
        * Constructeur de la classe Carte prenant
        * en paramètre une valeur et une couleur
        *
        * \param valeur: Valeur que l'on souhaite donner à
        * la carte
        * \param couleur: Couleur que l'on souhaite donner
        * à la carte
        */
        Carte(const int& valeur, const int& couleur);
        Carte& operator=(const Carte&);
		  
        void setValeur(const int&);
        void setCouleur(const int&);
        int getValeur();
        int getCouleur();

        void affiche(ostream& os);
};
ostream& operator<<(ostream&,Carte&);
#endif
