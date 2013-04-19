#include "Gagnant.h"

Gagnant::Gagnant(int nbJou)
{
     gagnant_suceptible = new Joueur[nbJou];
	 nbJouMax = nbJou;
     indicateur_gagnant = 0;
}

void Gagnant::AjouterGagnant(Joueur j)
{
     gagnant_suceptible[indicateur_gagnant] = j;
     gagnant_suceptible[indicateur_gagnant].isGagnant = true;
	 indicateur_gagnant++;
}

void Gagnant::AfficherGagnant()
{
     cout<<"Le ou les gagnant sont : ";
     for (int i=0;i<=indicateur_gagnant;i++)
     {
         cout<<gagnant_suceptible[i].getPseudo()<<" ";
     }
}
