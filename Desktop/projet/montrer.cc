//////DEBUT EVALUER MAIN


int Table::EssayerMain3CartesMilieu(int array[],int player)
{
  cout<<"Debut EssayerMain3CartesMilieu"<<endl;
	Carte mains[5];

         for (int i=1;i<4;i++)
                mains[i-1] = milieu[array[i]];

         for (int i=0;i<2;i++)
	  {
             //   mains[i+3] = joueurs[player].cartes[i];
		mains[i+3] = joueurs[player]->getCartes(i);
	  }
	 cout<<"fin EssayerMain3CartesMilieu"<<endl;
         return ObtenirPointMain(mains);
}

int Table::EssayerMain4CartesMilieu(int array[],int player)
{
  cout<<"Debut EssayeMain4CartesMilieu"<<endl;

	Carte mains[5];
	int ptC1=0;
	int ptC2=0;

         for (int i=1;i<5;i++)
	{
                mains[i-1] = milieu[array[i]];
	}

	// mains[4] = joueurs[player].cartes[0];
	 mains[4] = joueurs[player]->getCartes(0);
	 ptC1 = ObtenirPointMain(mains);
	 mains[4] = joueurs[player]->getCartes(1);
     //    mains[4] = joueurs[player]->cartes[1];
	 ptC2 = ObtenirPointMain(mains);

	 if (ptC1 > ptC2)
	{	
		//joueurs[player].carteMax = joueurs[player].cartes[0];
	  joueurs[player]->setCarteMax(joueurs[player]->getCartes(0));
	  return ptC1;
	}
	 else
	   {
	     joueurs[player]->setCarteMax(joueurs[player]->getCartes(1));
	     //joueurs[player].carteMax = joueurs[player].cartes[1];
	     return ptC2;
	   }
	 cout<<"Fin EssayerMain4CarteMilieu"<<endl;
}



void Table::RemplissageJeuxMax()
{
  cout<<"Debut RemplissagejeuxMax"<<endl;
  for (int q=0;q<nbJMax;q++)
    {
      if(joueurs[q]!=NULL){
	if (joueurs[q]->getValeurMain3() > joueurs[q]->getValeurMain4())
	  {
	    for (int i=0;i<3;i++)
	      {
		joueurs[q]->setCartesMax(i,joueurs[q]->getMainMax3(i));
	      }
	    int k=0;
	    for (int i=3;i<5;i++)
	      {
		joueurs[q]->setCartesMax(i,joueurs[q]->getCartes(k));
		k++;
	      }
	  }
	else
	  {
	    for (int i=0;i<4;i++)
	      {
		joueurs[q]->setCartesMax(i,joueurs[q]->getMainMax4(i));
	      }
	    joueurs[q]->setCartesMax(4,joueurs[q]->getCarteMax());
	    
	    
	  }
      }
    }
  cout<<"Fin RemplissagejeuxMax"<<endl;
}



//Cette fonction permet d'evaluer les mains maximun des joueurs en prenant en compte 4 cartes du board et les deux cartes des joueurs
// Elle remplis l'attribut valeurMain4 qui contiendra le nombre de point maximun que le joueur peut avoir ainsi que mainMax4 qui contiendra les 4 meilleurs cartes pour ce nombre de points
void Table::EvaluerMain2()
{
  cout<<"Debut Main2"<<endl;
  int stack[10],k;
  int PointsCourant;
  
  for (int q=0;q<nbJMax;q++){
    //joueurs[q].valeurMain4 = 0;
    if(joueurs[q]!=NULL){
      joueurs[q]->setValeurMain4(0);
      if (!joueurs[q]->isFold()){
	stack[0]=-1; /* -1 is not considered as part of the set */
	k = 0;
	while(1){
	  if (stack[k]<4){
	    stack[k+1] = stack[k] + 1;
	    k++;
	  }
	  
	  else{
	    stack[k-1]++;
	    k--;
	  }
	  
	  if (k==0)
	    break;

	  if (k==4){
	    PointsCourant = EssayerMain4CartesMilieu(stack,q);
	    if (PointsCourant>joueurs[q]->getValeurMain4()){
	      joueurs[q]->setValeurMain4(PointsCourant);
	      for (int x=0;x<4;x++){
		//   joueurs[q]->mainMax4[x] = milieu[stack[x+1]];
		joueurs[q]->setMainMax4(x,milieu[stack[x+1]]);
	      }
	      
	      
	    }
	  }
	  
	}
      }
    }
  }
  cout<<"Fin EvaluerMain2"<<endl;
}



//Cette fonction permet d'evaluer les mains maximun des joueurs en prenant en compte 3 cartes du board et les deux cartes des joueurs
// Elle remplis l'attribut valeurMain3 qui contiendra le nombre de point maximun que le joueur peut avoir ainsi que mainMax3 qui contiendra les 3 meilleurs cartes pour ce nombre dvector<int>e points
void Table::EvaluerMain()
{
  cout<<"Debut EvaluerMain()"<<endl;
  int stack[10],k;
  int PointsCourant;
  
  cout<<"TESTE 0"<<endl;
  for (int q=0;q<nbJMax;q++){
    if(joueurs[q]!=NULL){
      joueurs[q]->setValeurMain3(0);
      cout<<"TTTTTTEEEESSSTEE"<<endl;
      if (!joueurs[q]->isFold()){
	cout<<"TESTE 00"<<endl;
	stack[0]=-1; /* -1 is not considered as part of the set */
	k = 0;
	cout<<"TESTE 1"<<endl;
	while(1){
	  if (stack[k]<4){
	    stack[k+1] = stack[k] + 1;
	    k++;
	  }
	  
	  else{
	    stack[k-1]++;
	    k--;
	  }
	  
	  if (k==0)
	    break;
	  
	  if (k==3){
	    cout<<"TESTE 2"<<endl;
	    PointsCourant = EssayerMain3CartesMilieu(stack,q);
	    if (PointsCourant>joueurs[q]->getValeurMain3()){
	      joueurs[q]->setValeurMain3(PointsCourant);
	      for (int x=0;x<3;x++){
		//  joueurs[q].mainMax3[x] = milieu[stack[x+1]];
		joueurs[q]->setMainMax3(x,milieu[stack[x+1]]);
	      }
			    
	    }
	  }
	  
	}
      }
      
    }
  }
  cout<<"Fin EvaluterMain()"<<endl;
}



void Table::SetClassementJoueurs()
{
  cout<<"Debut SetClassementJoueurs()"<<endl;
  this->EvaluerMain();
  this->EvaluerMain2();
  this->RemplissageJeuxMax();
  //cout<<"HELLO world: "<<endl;
  int tab_joueurs[nbJMax][2];
  
  for (int i=0;i<nbJMax;i++)
    {
	  if(joueurs[i]!=NULL){
	    tab_joueurs[i][0] = i;
	    tab_joueurs[i][1] = -1;
	  }
	  else{
	    tab_joueurs[i][0]=-1;
	    tab_joueurs[i][1]=-1;
	  }
    }
  
  cout<<"Detection de la main max"<<endl;
  for (int i=0;i<nbJMax;i++)
	{
	  if(joueurs[i]!=NULL && !joueurs[i]->isFold() ){
	    if (joueurs[i]->getValeurMain3() > joueurs[i]->getValeurMain4() )
	    joueurs[i]->setValeurMainMax(joueurs[i]->getValeurMain3());
	    else
	      joueurs[i]->setValeurMainMax(joueurs[i]->getValeurMain4());
	  }
	}
  
  cout<<"remplissage tableau num_joueur_point"<<endl;
  for (int i=0;i<nbJMax;i++)
    {
      if(joueurs[i]!=NULL && !joueurs[i]->isFold()){
	  tab_joueurs[i][0] = i;
	  tab_joueurs[i][1] = joueurs[i]->getValeurMainMax();
	}
    }

  int tmp[2];
  for (int i=0;i<nbJMax;i++)
    {
      for(int j=0;j<i;j++){
	if(tab_joueurs[j][1] < tab_joueurs[i][1])
	  {
	    tmp[0] = tab_joueurs[i][0];
	    tmp[1] = tab_joueurs[i][1];
	    tab_joueurs[i][0] = tab_joueurs[j][0];
	    tab_joueurs[i][1] = tab_joueurs[j][1];
	    tab_joueurs[j][0] = tmp[0];
	    tab_joueurs[j][1] = tmp[1];
	  }
	else{
	  j=i;
	}
      }
    }
  
  cout<<"copie du tableau dans l'attribut classement"<<endl;
  int j=0;
  for (int i=0;i<nbJoueur;i++)
    {
      cout<<"Classement joueurs "<<tab_joueurs[i][0]<<tab_joueurs[i][1]<<endl;
      classementJoueurs[j][0] = tab_joueurs[i][0];
      classementJoueurs[j][1] = tab_joueurs[i][1];
      j++;
     
    }
  
  cout<<"Fin setClassementJoueur()"<<endl;
}








int Table::ObtenirPointMain(Carte main[])
{
  cout<<"Debut ObtenirPointMain"<<endl;
	Carte main_copie[5];
	main_copie[0] = main[0];
	main_copie[1] = main[1];
	main_copie[2] = main[2];
	main_copie[3] = main[3];
	main_copie[4] = main[4];
    	int points;
    	int valMax = 0;
    //Classement des cartes de la plus petite � la plus grande
    qsort(main_copie,5,sizeof(Carte),comparerCartes);
     for (int i=0;i<5;i++)
     {
	valMax += main_copie[i].getValeur();

     }



     //Test du trie
        for (int i=0;i<5;i++)
             {
                  cout<<"getValeur() carte : "<<main[i].getValeur()<<" ";
             }
    int suite,couleur,brelan,carre,full,paires,CarteHaute;
    suite = couleur = brelan = carre = full = paires = CarteHaute = 0;
    int cpt = 0 ;

    //Verification pour voir si il y a un carr�
    for (int i=0;i<2;i++){
        cpt = i;
        while (  cpt<i+3 && (main_copie[cpt].getValeur() == main_copie[cpt+1].getValeur()))
              cpt++;
        if (cpt==i+3){
           carre = 1;
           CarteHaute = main_copie[i].getValeur();
        }
    }

    //Verification d'une getCouleur()
    cpt = 0;
    while (cpt<4 && main_copie[cpt].getCouleur()==main_copie[cpt+1].getCouleur())
          cpt++;
    if (cpt==4){
       couleur = 1;
    }

    //Verification d'une suite
    cpt=0;
    while (cpt<4 && main_copie[cpt].getValeur() == main_copie[cpt+1].getValeur()-1)
    {
          cpt++;
    }
    if (cpt==4)
       suite = 1;



    //Verification d'un brelan ou d'un full
    if (!carre){
       for (int i=0;i<3;i++){
           cpt = i;
           while (cpt<i+2 && (main_copie[cpt].getValeur()==main_copie[cpt+1].getValeur()))
           {
                 cpt++;
           }
           if (cpt==i+2){
              //Brelan a �t� detecter
              brelan = 1;
              CarteHaute=main_copie[i].getValeur();
              //Verification d'un full

              //Brelan sur  les 3 premieres cartes donc on verifie les deux dernieres
              if (i==0){
                 if (main_copie[3].getValeur()==main_copie[4].getValeur())
                    full=1;
              }
              //Brelan sur les cartes du milieu
              else if(i==1){
                   if (main_copie[0].getValeur()==main_copie[4].getValeur())
                      full=1;
              }
              else{
              //Brelan sur les 3 dernieres cartes
                   if (main_copie[0].getValeur()==main_copie[1].getValeur())
                      full=1;
              }
           }
       }
    }
    //Quinte Flush
    if (suite&&couleur)
         return 300 + main_copie[4].getValeur() + valMax;
    else if(carre)
         return 270 + CarteHaute + valMax;
    else if(full)
         return 250 + CarteHaute + valMax;
    else if(couleur)
         return 220 + valMax;
    else if(suite)
    {
         return 200 + main_copie[4].getValeur() + valMax;
    }
    else if(brelan)
         return 150 + CarteHaute + valMax;

    int valPaire =0 ;
    //Verification d'une ou des paires
    for (cpt=0;cpt<4;cpt++){
        if (main_copie[cpt].getValeur()==main_copie[cpt+1].getValeur()){
	   valPaire += main_copie[cpt].getValeur();
           paires++;
	   
           if (main_copie[cpt].getValeur()>CarteHaute)
              CarteHaute = main_copie[cpt].getValeur();
        }
    }
    if (paires==2)
    {
        return  100 + valPaire + valMax;
    }
    else if(paires)
         return 30 + valMax;
    else
         return main_copie[4].getValeur();

}

int comparerCartes(const void *cartes1, const void *cartes2){
  cout<<"Debut comparerCartes"<<endl;
  return (*(Carte *)cartes1).getValeur() - (*(Carte *)cartes2).getValeur();
}



///////FIN EVALUER MAIN
