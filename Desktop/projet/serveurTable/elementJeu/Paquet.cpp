#include "Paquet.h"

Paquet::Paquet(){
    for(int k=0;k<4;k++){
        for(int j=0;j<13;j++){
            cartes.push_back(Carte(k,j));
        }
    }

}

Carte Paquet::sortirCarte(){
    int alea;
    Carte c;
    srand(time(NULL));
    alea = rand()%cartes.size();
    c = cartes[alea];
    cartes.erase(cartes.begin()+alea);
    return c;
}

 void Paquet::initialiserPaquet(){
    cartes.clear();
    for(int k=0;k<4;k++){
        for(int j=0;j<13;j++){
            cartes.push_back(Carte(k,j));
        }
    }
 }
int Paquet::getTaille(){
    return cartes.size();
}
