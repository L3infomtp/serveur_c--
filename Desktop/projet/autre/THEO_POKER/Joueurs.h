#ifndef _JOUEURS_H
#define _JOUEURS_H

#include "Carte.h"
#include <string>

using namespace std;
//Simule un joueur
class Joueur{
    public:
    string pseudo;
    int monnaie;
    Carte cartes[2];
    bool playing;
    bool round;
    bool goodToGo;
    int valeurMain;
    bool isGagnant;
    
    Joueur();
    //utilisé pour test
    void setCartes(Carte p_cartes[2]);
    void setPseudo(string);
    string getPseudo();
    void setPlaying(bool play);
};

#endif
