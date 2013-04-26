#ifndef SERVEUR_H
#define SERVEUR_H
#include <iostream>
#include <vector>
//#include<string.h>
#include "ClientVuServeur/Client.h"
#include "sock/sock.h"
#include "Table/Table.h"
using namespace std;
/**
 *@mainpage Projet L3 : Poker
 *Création de la classe Serveur

 *\author LAGNIEZ Jean-Marc
 */
class Serveur{
 private:
  Sock brPub;
  int descBrPub;
  
  int descLectMax;
  fd_set desc_en_lect;
  
  vector<Client*> tabClient;
  int tailleVecteur;
  
  vector<Table> tabTable;
  int nbJ;
  char** env;
  
 public:
  /**
   *\fn Serveur(char** env)
   *@brief Le constructeur de Serveur
   *Permet de creer un serveur. Ce constructeur va créer plusiers processus fils pour créer des tables ayant les même variables d'environement que son père 
   \param env Les variables d'environement du Serveur principal
*/
  Serveur(char**);
  /**
   *\fn ~Serveur()
   *@brief Le destructeur de Serveur
   *Permet de détruire le Serveur.
  */
  ~Serveur();
  /**
   *\fn void lancerServeur()
   *@brief Place le Serveur dans un état d'attende 
   *Permet d'attendre les conexions et les actions des différents clients
  */
  void lanceServeur();
  /**
   *\fn void creerTable(char** env)
   *@brief Créer un processus fils et applique un recouvrement avec le processus projet/serveurTable/Table.
  */
  void creerTable();
  /**
   *\fn void accepterClient()
   *@brief Accepte un nouveau client.
   *Permet d'ajouter un nouveau client se connectant et le rajouter dans le tableau des clients
  */
  void accepterClient();
  /**
   *\fn void erreur() 
   *@brief Après une erreur, on supprime le Serveur
  */
  void erreur();
  
  /**
   *\fn void actionClient(int place)
   *@brief Un client a envoyé une donnée
   *Permet de recupérer l'action du client à la position 'place' dans la table des client.
   \param place La position dans le tableau des clients de l'utilisateur ayant effectué une action
  */
  void actionClient(int);
  /**
   *\fn void actionUtilisateur(int place)
   *@brief Un client a envoyé une donnée
   *Permet de recupérer l'action du client à la position 'place' dans la tables des clients.
   \param place La position dans el tableau des clients de l'utilisateur ayant effecutué une action
  */
     
  void actionUtilisateur(int);
  /**
   *\fn char* decompositionMessage(char* recu, char* buf, int nbSeparateur)
   *@brief Decoupe le message recu
   *Permet de découper un message par rapport à un caractère séparateur et un nombre de séparateur prédéfinie dans le protocole
   \param recu Le message decoupé
   \param buf Le messagge decoupé y est stocké
   \param nbSeparateur Le nombre de caractère séparateur
   *@return L'ancienne chaîne de caractère privé du message découpé
  */
  char* decompositionMessage(char*,char*,int);
  /**
   *\fn char* getMessage(char* recu, char* bufTchat)
   *@brief Decoupe le message recu pour récuperer le message de chat
   *Permer de découper un message par rapport à une taille donné dans celui-ci
   \param recu Le message decoupé
   \param buf Le message de chat y est stocké
   *@return L'ancienne chaîne de caractère privé du message découpé
  */

  char* getMessage(char*, char*);
  /**
   *\fn void decoClient(int place)
   *@brief Un client est parti
   *Permet de supprimer le client à la position 'place' dans le tableau des clients 
   *\param place La position dans le tableau des clients de l'utilisateur quittant le Serveur
  */
  void decoClient(int);
  /**
   *\fn void msgClient(char* message)
   *@brief Envoie message à tous les clients
   *\param message Le message a envoyé à tous les utilisateurs
  */
  void msgClient(char*);
  /**
   *\fn void modifiClient(char* modification,Client* c)
   *@brief Modifie une donnée de la base de donnée d'un client
   *Permet d'appliquer 'modification' sur le n-uplets du Client 'c'
   *\param modification La chaine de caractère indiquant la modification à éffectuer
   *\param c L'utilisateur a modifier
  */
  void modifClient(char*,Client*);
  /**
   *\fn void actionTable(int place)
   *@brief Une table a envoyé une donnée
   *Permet de récupérer l'action d'une Table à la position 'place' dans la table des Table
   *\param place La position dans le tableau des Tables ayant effectué une action
  */
  void actionTable(int);

  
  void convertionPseudoMdpClient(char*,string&, string&);
  void convertionClientChar(char* buffer,Client* cl);
  void convertionTableChar(char*);
  void envoieTable(int); //int descripteur utilisateur

  Client* connexionClientBDD(const int,const string,const string);
  
 
};
#endif
