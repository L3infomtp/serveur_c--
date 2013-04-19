

#include "Joueurs.h"

Joueur::Joueur()
{
    playing = false;
    isGagnant = false;
}
    //utilisé pour test
void Joueur::setCartes(Carte p_cartes[2])
{
     cartes[0] = p_cartes[0];
     cartes[1] = p_cartes[1];
}
     
void Joueur::setPlaying(bool play)
{
         playing = play;
}

void Joueur::setPseudo(string name)
{
     pseudo = name;
}

string Joueur::getPseudo()
{
       return pseudo;
}
