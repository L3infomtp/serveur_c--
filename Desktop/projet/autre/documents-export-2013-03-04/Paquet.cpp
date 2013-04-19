#include "C:\Users\Maryan\Documents\ProjetL3\ProjetL3\include\Paquet.h"

Paquet::Paquet(){
    for(int k=1;k<5;k++){
        for(int j=1;j<14;j++){
            cartes.push_back(Carte(k,j));
        }
    }
    srand(time(NULL));
}

Carte Paquet::sortirCarte(){
    int alea;
    Carte c;
    alea = rand()%cartes.size();
    c = cartes[alea];
    cartes.erase(cartes.begin()+alea);
    return c;
}

 void Paquet::initialiserPaquet(){
    cartes.clear();
    for(int k=1;k<5;k++){
        for(int j=1;j<14;j++){
            cartes.push_back(Carte(k,j));
        }
    }
 }
int Paquet::getTaille(){
    return cartes.size();
}
