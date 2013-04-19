#include "Carte.h"

Carte::Carte(){
    valeur = 0;
    couleur = 0;
}

Carte::Carte(const Carte& c){
    couleur = c.couleur;
    valeur = c.valeur;
}

Carte::Carte(const int& c, const int& v){
    couleur = c;
    valeur = v;
}

Carte& Carte::operator=(const Carte& c){
    couleur = c.couleur;
    valeur = c.valeur;
    return *this;
}

void Carte::setValeur(const int& v){
    valeur = v;
}
void Carte::setCouleur(const int& c){
 couleur = c;
}

int Carte::getValeur(){
    return valeur;
}

int Carte::getCouleur(){
    return couleur;
}

void Carte::affiche(ostream& os){
    os<<"["<<couleur<<" "<<valeur<<"]";
}

ostream& operator<<(ostream& os,Carte& c){
    c.affiche(os);
    return os;
}
