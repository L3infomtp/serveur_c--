#include "Paquet.h"

string valeurs[13];
string habillages[4];

Paquet::Paquet()
{
    habillages[0] = "C"; //Carreau
    habillages[1] = "P"; //Pique
    habillages[2] = "H"; //Coeur (Heart)
    habillages[3] = "T"; //Trèfle
    valeurs[0] = "2";
    valeurs[1] = "3";
    valeurs[2] = "4";
    valeurs[3] = "5";
    valeurs[4] = "6";
    valeurs[5] = "7";
    valeurs[6] = "8";
    valeurs[7] = "9";
    valeurs[8] = "T";
    valeurs[9] = "J";
    valeurs[10] = "Q";
    valeurs[11] = "K";
    valeurs[12] = "A";
    //Association des cartes
    for (int i=0;i<4;i++){
        for (int j=0;j<13;j++){
            cartes[i*13+j].habillage = i;
            cartes[i*13+j].valeur = j;
        }
    }
                   
                        
}
      
void Paquet::AffichagePaquet()
{
     cout << " Affichage du paquet " << endl;
     for (int i=0;i<52;i++)
         cout << valeurs[cartes[i].valeur] << habillages[cartes[i].habillage] << endl;
     cout << endl;
}
      
void Paquet::MelangerPaquet()
{
     hauteur = 51;
     int x;
     Carte CarteTmp;
     for (int i=0;i<4;i++){
         for (int j=0;j<13;j++){
             cartes[i*13+j].habillage = i;
             cartes[i*13+j].valeur = j;
         }
     }
     for (int i=0;i<52;i++){
         x = rand() % 52;
         CarteTmp = cartes[i];
         cartes[i] = cartes[x];
     }
                
}
      
      //Tire une carte en haut du paquet
Carte Paquet::TirerUneCarte()
{
      hauteur--;
      return cartes[hauteur+1];
}
      

