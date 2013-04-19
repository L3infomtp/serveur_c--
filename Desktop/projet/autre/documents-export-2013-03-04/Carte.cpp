#include "C:\Users\Maryan\Documents\ProjetL3\ProjetL3\include\Carte.h"

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

void Carte::setvaleur(const int& v){
    valeur = v;
}
void Carte::setcouleur(const int& c){
 couleur = c;
}

int Carte::getvaleur(){
    return valeur;
}

int Carte::getcouleur(){
    return couleur;
}

void Carte::affiche(ostream& os){
    os<<"["<<couleur<<" "<<valeur<<"]";
}

ostream& operator<<(ostream& os,Carte& c){
    c.affiche(os);
    return os;
}
