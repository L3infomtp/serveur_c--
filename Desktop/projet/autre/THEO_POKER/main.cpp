

#include "Paquet.h"
#include "Table.h"
#include "Joueurs.h"
#include "Gagnant.h"

using namespace std;


int main()
{
    //Test de classe Paquet
    Paquet new_paquet;
    new_paquet.AffichagePaquet();
    
    cout << "Melange en Cours " << endl;
    new_paquet.MelangerPaquet();
    new_paquet.AffichagePaquet();
    
    //Test des points d'une main au Poker
    Carte cartes[5];
    cartes[0].habillage = 0;
    cartes[0].valeur = 12;
    
    cartes[1].habillage = 1;
    cartes[1].valeur = 10;
    
    cartes[2].habillage = 2;
    cartes[2].valeur = 7;
    
    cartes[3].habillage = 3;
    cartes[3].valeur = 11;
    
    cartes[4].habillage = 0;
    cartes[4].valeur = 5;
    
	Carte otherCards[2];
	otherCards[0].habillage = 0;
	otherCards[0].valeur = 9;
	otherCards[1].habillage = 0;
	otherCards[1].valeur = 2;

    Table jeux;
    

    //cout << " Test de detection d'une main " << endl;
//    int point;
//    point = jeux.ObtenirPointMain(cartes);
//    cout << " Point : " << point << endl;
    
    jeux.setCartesTable(cartes);
    
    //Test joueurs & main gagnantes
    Carte jeuxj1[2];
    jeuxj1[0] = cartes[0];
    jeuxj1[1] = otherCards[0];
    
    Carte jeuxj2[2];
    jeuxj2[0] = otherCards[0];
    jeuxj2[1] = otherCards[1];

	Carte jeuxj3[2];
	jeuxj3[0] = cartes[0];
	jeuxj3[1] = otherCards[1];
    
    Joueur joueur1;
    joueur1.setPseudo("Theo");
    joueur1.setCartes(jeuxj1);
    joueur1.setPlaying(true);
    
    Joueur joueur2;
    joueur2.setPseudo("Pierre");
    joueur2.setCartes(jeuxj2);
    joueur2.setPlaying(true);
    
    Joueur joueur3;
    joueur3.setPseudo("Caroline");
    joueur3.setCartes(jeuxj3);
    joueur3.setPlaying(true);
    
    jeux.setJoueur(0,joueur1);
    jeux.setJoueur(1,joueur2);
    jeux.setJoueur(2,joueur3);
    
    Gagnant tab_gagnant(6);
    tab_gagnant = jeux.SavoirGagnant();
    tab_gagnant.AfficherGagnant();
    
//    cout <<" Le gagnant est : "<<gagnant[0]<<endl;
 
    
    while(1);
    return 0;
}
