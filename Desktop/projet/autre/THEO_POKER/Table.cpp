
#include "Table.h"

using namespace std;

Table::Table()
{
}
void Table::setCartesTable(Carte p_cartes[5])
{
     for (int i=0;i<5;i++)
         CartesTable[i] = p_cartes[i];
}

void Table::Demarrer(string name){
     for (int i = 0;i < 6; i++){
         joueurs[i].monnaie = 1000;
         joueurs[i].playing = true;
     }
     joueurs[0].pseudo = "Phillipe";
     joueurs[1].pseudo = "Pierre";
     joueurs[2].pseudo = "Francis";
     joueurs[3].pseudo = "Robert";
     joueurs[4].pseudo = name;
     joueurs[5].pseudo = "Albert";
        //    startGame();
}

void Table::setJoueur(int num,Joueur newjoueur)
{
     
     joueurs[num] = newjoueur;

}

void Table::DistributionDesJeux()
        {
            for (int i=0;i<6;i++){
                for (int j=0;j<2;j++){
                    if (joueurs[i].playing){
                        joueurs[i].cartes[j] = PaquetDuJeu.TirerUneCarte();
                    }
                }
            }
            for (int i=0;i<5;i++)
                CartesTable[i].valeur=-1;
        }
        
void Table::DistributionFlop()
{
     for (int i=0;i<3;i++)
         CartesTable[i] = PaquetDuJeu.TirerUneCarte();
}
        
void Table::DistributionTurn()
{
     CartesTable[3] = PaquetDuJeu.TirerUneCarte();
}
        
void Table::DistributionRiver()
{
     CartesTable[4] = PaquetDuJeu.TirerUneCarte();
}

int Table::JoueursRestant()
{
    int nb = 0;
    for (int i = 0; i < 6; i++){
        if (joueurs[i].monnaie>0)
           nb++;
    }
    return nb;
}

//Verifier si il y a quelqu'un encore qui a parier ou caller
int Table::VerifieSiJoueursMise(){
    for (int i = 0;i<6;i++){
        if (joueurs[i].round==true&&joueurs[i].goodToGo==false)
           return 1;
    }
    return 0;
}
        
        //Obtenir le numéro du joueur Gagnant
int Table::ObtenirNumeroGagnant(){
    int gagnant;
    for (int i=0;i<6;i++){
        if (joueurs[i].round)
           gagnant = i;
    }
    return gagnant;
        
}


//Retournera le numero des joueurs gagnants
Gagnant Table::SavoirGagnant()
{
     //REPRENDRE ICI AVEC LES DIFFERENTES POSSIBILITES DU BOARD
    Carte carteTmp[5];
    int nbJoueurActif = 0;
                 
    for (int i=0;i<6;i++)
    {
        if (joueurs[i].playing)
           nbJoueurActif++;
    }
    cout<<"Nb Actif "<<nbJoueurActif<<endl;
    //indiquera le tableau des gagnants (va etre declarer en fonction du nombre joueurs actif max)
    Gagnant tab_winner(nbJoueurActif);


    //Test avec les différents board possible
    //Board 1 - 3 premieres carte
    carteTmp[0] = CartesTable[0];
    carteTmp[1] = CartesTable[1];
    carteTmp[2] = CartesTable[2];
   
    for (int i=0;i<3;i++)
    {
        carteTmp[3] = joueurs[i].cartes[0];
        carteTmp[4] = joueurs[i].cartes[1];
                     
        //Test affichage
        cout << "Jeux 1 : ";
        if (i==0)
           cout<<"Joueur 0 : ";
        else if (i==1)
             cout<<"Joueur 1 : ";
        else
             cout<<"Joueur 2 : ";
        for (int j=0;j<5;j++)
        {
            cout << carteTmp[j].valeur <<" ";
        }
        cout<<endl;
        joueurs[i].valeurMain = ObtenirPointMain(carteTmp);
                     
    }
    cout<<"Affichage de la valeur de la main de chaque joueur : "<< endl;
    for (int i=0;i<3;i++)
        cout<<"Joueur "<<i<<" valeur : "<<joueurs[i].valeurMain<<" - ";
    cout<<endl;
    //Board 2 - 2 , 3 , 4 cartes
    carteTmp[0] = CartesTable[1];
    carteTmp[1] = CartesTable[2];
    carteTmp[2] = CartesTable[3];
                 
    int valeurMainTmp;
    for (int i=0;i<nbJoueurActif;i++)
    {
        carteTmp[3] = joueurs[i].cartes[0];
        carteTmp[4] = joueurs[i].cartes[1];
        //Test affichage
        cout << "Jeux 2 : ";
        if (i==0)
           cout<<"Joueur 0 : ";
        else if (i==1)
             cout<<"Joueur 1 : ";
        else
             cout<<"Joueur 2 : ";
        for (int j=0;j<5;j++)
        {
                         cout << carteTmp[j].valeur <<" ";
        }
        cout<<endl;
        valeurMainTmp = ObtenirPointMain(carteTmp);
        if (valeurMainTmp > joueurs[i].valeurMain)
           joueurs[i].valeurMain = valeurMainTmp;
    }
    cout<<"Affichage de la valeur de la main de chaque joueur : "<< endl;
    for (int i=0;i<3;i++)
        cout<<"Joueur "<<i<<" valeur : "<<joueurs[i].valeurMain<<" - ";
    cout<<endl;
    //Board 2 - 3 , 4 , 5 cartes
    carteTmp[0] = CartesTable[2];
    carteTmp[1] = CartesTable[3];
    carteTmp[2] = CartesTable[4];            
    for (int i=0;i<nbJoueurActif;i++)
    {
        carteTmp[3] = joueurs[i].cartes[0];
        carteTmp[4] = joueurs[i].cartes[1];
        //Test affichage
        cout << "Jeux 3 : ";
          if (i==0)
           cout<<"Joueur 0 : ";
        else if (i==1)
             cout<<"Joueur 1 : ";
        else
             cout<<"Joueur 2 : ";
        for (int j=0;j<5;j++)
        {
            cout << carteTmp[j].valeur <<" ";
        }
        cout<<endl;
        valeurMainTmp = ObtenirPointMain(carteTmp);
        if (valeurMainTmp > joueurs[i].valeurMain)
           joueurs[i].valeurMain = valeurMainTmp;
    }
    for (int i=0;i<3;i++)
        cout<<"Joueur "<<i<<" valeur : "<<joueurs[i].valeurMain<<endl;
    //Savoir quelle joueur à la meilleur
    int cpt=0;
    
    int noJoMax=0;
    for (int i=1;i<nbJoueurActif;i++)
    {
        if (joueurs[noJoMax].valeurMain < joueurs[i].valeurMain)
           noJoMax = i;
    }
    cout<<"Le numero du joueur max est "<<noJoMax<<endl;
    tab_winner.AjouterGagnant(joueurs[noJoMax]);

//    for (int i=1;i<nbJoueurActif;i++)
//    {
//        if (joueurs[cpt].valeurMain < joueurs[i].valeurMain)
//           gagnant[cpt] = i;
//        else{
//            gagnant[cpt] = cpt;
//        }
//        cpt++;
//    }

    //Recherche des égalités
    for (int i=0;i<nbJoueurActif;i++)
    {
       if ( (joueurs[noJoMax].valeurMain == joueurs[i].valeurMain) && noJoMax != i)
          tab_winner.AjouterGagnant(joueurs[i]);
    }
    return tab_winner;

}

int comparerCartes(const void *cartes1, const void *cartes2){
               return (*(Carte *)cartes1).valeur - (*(Carte *)cartes2).valeur;
}

//Obtenir le nombre de point d'une main specifié en parametre
int Table::ObtenirPointMain(Carte main[])
{
	Carte main_copie[5];
	main_copie[0] = main[0];
	main_copie[1] = main[1];
	main_copie[2] = main[2];
	main_copie[3] = main[3];
	main_copie[4] = main[4];
    //Classement des cartes de la plus petite à la plus grande
    qsort(main_copie,5,sizeof(Carte),comparerCartes);
             
    //     //Test du trie
//             for (int i=0;i<5;i++)
//             {
//                  cout<<"valeur carte : "<<main[i].valeur<<" ";
//             }
    int suite,couleur,brelan,carre,full,paires,CarteHaute;
    suite = couleur = brelan = carre = full = paires = CarteHaute = 0;
    int cpt = 0 ;
             
    //Verification pour voir si il y a un carré
    for (int i=0;i<2;i++){
        cpt = i;
        while (  cpt<i+3 && (main_copie[cpt].valeur == main_copie[cpt+1].valeur))
              cpt++;
        if (cpt==i+3){
           carre = 1;
           CarteHaute = main_copie[i].valeur;
        }
    }
            
    //Verification d'une couleur
    cpt = 0;
    while (cpt<4 && main_copie[cpt].habillage==main_copie[cpt+1].habillage)
          cpt++;
    if (cpt==4){
       couleur = 1;
    }
            
    //Verification d'une suite
    cpt=0;
    while (cpt<4 && main_copie[cpt].valeur == main_copie[cpt+1].valeur-1)
          cpt++;
    if (cpt==4)
       suite = 1;
                
    //Verification d'un brelan ou d'un full
    if (!carre){
       for (int i=0;i<3;i++){
           cpt = i;
           while (cpt<i+2 && (main_copie[cpt].valeur==main_copie[cpt+1].valeur))
           {
                 cpt++;
           }
           if (cpt==i+2){
              //Brelan a été detecter
              brelan = 1;
              CarteHaute=main_copie[i].valeur;
              //Verification d'un full
                       
              //Brelan sur  les 3 premieres cartes donc on verifie les deux dernieres
              if (i==0){
                 if (main_copie[3].valeur==main_copie[4].valeur)
                    full=1;
              }
              //Brelan sur les cartes du milieu
              else if(i==1){
                   if (main_copie[0].valeur==main_copie[4].valeur)
                      full=1;
              }
              else{
              //Brelan sur les 3 dernieres cartes
                   if (main_copie[0].valeur==main_copie[1].valeur)
                      full=1;
              }
           }
       }
    }
    //Quinte Flush
    if (suite&&couleur)
         return 170 + main_copie[4].valeur;
    else if(carre)
         return 150 + CarteHaute;
    else if(full)
         return 130 + CarteHaute;
    else if(couleur)
         return 110;
    else if(suite)
         return 90 + main_copie[4].valeur;
    else if(brelan)
         return 70 + CarteHaute;
                
    //Verification d'une ou des paires
    for (cpt=0;cpt<4;cpt++){
        if (main_copie[cpt].valeur==main_copie[cpt+1].valeur){
           paires++;
           if (main_copie[cpt].valeur>CarteHaute)
              CarteHaute = main_copie[cpt].valeur;
        }
    }
    if (paires==2)
        return 50 + CarteHaute;
    else if(paires)
         return 30 + CarteHaute;
    else
        return main_copie[4].valeur;
}
