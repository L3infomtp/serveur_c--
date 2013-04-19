#ifndef SPECTATEUR_H
#define SPECTATEUR_H
/**
*\file Spectateur.h
*\brief Header de la classe Spectateur du point de vue d'une table.
*\author Maryan Ludwiczak
*\date 10 avril 2013
*/
#include <iostream>
#include<string.h>
#include <string>
using namespace std;
/** *\class Spectateur Spectateur.h "/media/USB20FD/proker/*serveurTable/elementJeu"
*\brief classe représentant un spectateur
*
* La classe gère le déroulement de la partie du côté du spectateur
*/ 
class Spectateur{
 private:
  int desc; /** Entier représentant le descripteur de la
  * boîte réseau du spectateur*/
  string nom; /** Nom du spectateur*/

 public:
 /**
 * \brief Constructeur par défaut
 * 
 * Constructeur par défaut de la classe Spectateur
 */
  Spectateur();
 /**
 * \brief Constructeur
 *
 * Constructeur avec un descripteur de boîte réseau en paramètre
 *
 * \param desc: Descripteur de la boîte réseau pour le spectateur que l'on veut créer
 */ 
  Spectateur(int desc);
  /**
 * \brief Constructeur
 *
 * Constructeur avec un descripteur de boîte réseau en paramètre et le nom qu'on veut donner au spectateur
 *
 * \param desc: Descripteur de la boîte réseau pour le spectateur que l'on veut créer
 * \param nom: Nom que l'on souhaite donner au spectateur crée
 */ 
  Spectateur(int desc,string nom);
  /**
 * \brief Constructeur par copie
 *
 * Constructeur par copie avec en paramètre une instance de
 * la classe Spectateur que l'on copie
 *
 * \param spectateur: Instance de la classe Spectateur
 */ 
  Spectateur(const Spectateur& spectateur);

  int getDesc()const;
  string getNom()const;

  void setDesc(const int&);
  void setNom(const string&);

  virtual void affiche(ostream&)const;
};
ostream& operator<<(ostream&, Spectateur&);

#endif // SPECTATEUR_H
