#ifndef JOUEUR_H
#define JOUEUR_H
/**
*\file Joueur.h
*\brief Header de la classe Joueur du point de vue d'une table.
*\author Maryan Ludwiczak
*\date 10 avril 2013
*/
#include <math.h>
#include "Spectateur.h"
#include "Carte.h"

/** *\class Joueur Joueur.h "/media/USB20FD/proker/*serveurTable/elementJeu"
*\brief classe représentant un joueur
*
* La classe gère le déroulement de la partie du côté du joueur
*/ 
class Joueur:public Spectateur{
 private:
  int jeton; /** Nombre de jetons du joueur*/
  int jetonDebutDeManche; /** Nombre de jetons en début de manche*/
  int jetonDebutDePartie; /** Nombre de jetons en début de partie*/
  Carte cartes[2]; /** Main du joueur*/
  bool actif; /** Indique si le joueur est encore en jeu ou non*/
  bool fold; /** Indique si le joueur s'est couché ou non*/
  bool allIn; /** Indique si le joueur a fait tapis (misé tous ses jetons) */
  int pot; /** Indique la valeur du gain maximal possible sur le pot*/
  int nbJPot; //Plus utilisé.

      Carte cartesMax[5]; /* Contient la combinaison des 5emes meilleurs cartes avec flop + cartes */

    /* Contient la valeur de la main max avec 4 cartes du board + 1 carte du jeux du joueur */
    int valeurMain4;

    /* contient la valeur de la main max avec 3 cartes du board + les deux cartes du joueur */
    int valeurMain3;

    /* contient la valeur max , ce sera soit valeurMain3 soit valeurMain4 */
    int valeurMainMax;

    /* contient les 4 meilleurs cartes du board qui s'associe avec une carte du joueur */
    Carte mainMax4[4];
    /*contient les 3 meilleurs cartes du board qui s'associe avec le jeux du joueur */
    Carte mainMax3[3];

   /*contient la carte max du joueur pour laquelle la combinaison des 4 cartes du board est la meilleur */
    Carte carteMax;
  

 public:
 /**
 * \brief Constructeur par défaut
 *
 * Constructeur par défaut de la classe Joueur
 */
  Joueur();
 /**
 * \brief Constructeur
 *
 * Constructeur à deux paramètres de la classe Joueur
 *
 * \param Spectateur: une instance de la classe Spectateur
 * 
 * \param nbJetons: Le nombre de jetons avec lequel le joueur rentre dans la partie
 */  
  Joueur(Spectateur, int nbJetons);
  int getJeton()const;
  Carte getCartes(const int&)const;
  bool isFold()const;
  bool isActif()const;
  bool isAllIn()const;
  int getJetonDebutDeManche()const;
  int getJetonDebutDePartie()const;
  int getPot()const;
  int getNbJPot()const;
  
  void setJeton(const int&);
  void setCartes(const Carte&, const int&);
  void setFold(const bool&);
  void setActif(const bool);
  void setAllIn(const bool);
  void setJetonDebutDeManche(const int);
  void setJetonDebutDePartie(const int);
  void setPot(const int);
  void setNbJPot(const int);

  int getValeurMain3();
  int getValeurMain4();
  int getValeurMainMax();
  
  void setValeurMain3(int);
  void setValeurMain4(int);
  void setValeurMainMax(int);
  
  Carte getCarteMax();
  void setCarteMax(Carte);
  
  void setMainMax3(int,Carte);
  void setMainMax4(int,Carte);
  
  void setCartesMax(int,Carte);
  
  Carte getMainMax3(int);
  Carte getMainMax4(int);
  Carte getCartesMax(int);

  
  /**
  * \brief Affichage
  *
  * Permet l'affichage d'un joueur
  */
  void affiche(ostream&)const;
  /**
  * \brief Mise totale du joueur sur une manche
  * 
  * Somme totale qu'aura misée le joueur à la fin d'une manche
  *
  */
  int miseDeCetteManche();
  /**
  * \brief Nouveau gain
  * 
  * Gain du joueur à la fin d'une manche
  */
  void nouveauGain(int);
  void augmentePot(int);//maybe on l'utilise plus
  /**
  * \brief Réinitialisation du Joueur
  *
  * Réinitialisation des attributs du joueur en cas de nouvelle partie
  */
  void resetJ();
};
ostream& operator<<(ostream&, Joueur&);


#endif // JOUEUR_H
