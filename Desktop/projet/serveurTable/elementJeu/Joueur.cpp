#include "Joueur.h"


Joueur::Joueur():Spectateur(){
    jeton = 0;
    jetonDebutDeManche=0;
    fold = true;
    actif=true;
    allIn=false;
    pot=0;
    nbJPot=0;
}

Joueur::Joueur(Spectateur s, int j):Spectateur(s){
    jeton = j;
    jetonDebutDeManche=j;
    fold = true;
    actif=true;
    allIn=false;
    pot=0;
}
bool Joueur::isActif()const{return actif;}
bool Joueur::isAllIn()const{return allIn;}
int Joueur::getJeton()const{return jeton;}
int Joueur::getJetonDebutDeManche()const{return jetonDebutDeManche;}
int Joueur::getJetonDebutDePartie()const{return jetonDebutDePartie;}
Carte Joueur::getCartes(const int& i)const{
    return cartes[i];
}
bool Joueur::isFold()const{
    return fold;
}
int Joueur::getPot()const{return pot;}
void Joueur::setJeton(const int& j){
    jeton = j;
}
void Joueur::setCartes(const Carte& c, const int& i){
    cartes[i] = c;
}
void Joueur::setFold(const bool& b){
    fold = b;
}
void Joueur::setActif(const bool a){actif=a;}
void Joueur::setAllIn(const bool a){allIn=a;}
void Joueur::setJetonDebutDeManche(const int f){jetonDebutDeManche=f;}
void Joueur::setJetonDebutDePartie(const int f){jetonDebutDePartie=f;}
void Joueur::setPot(const int a){pot=a;}
void Joueur::setNbJPot(const int a){nbJPot=a;}
void Joueur::affiche(ostream& os)const{
    Spectateur::affiche(os);
    os<<"Nb Jeton : "<<jeton<<endl;
}
int Joueur::miseDeCetteManche(){
  return jetonDebutDeManche-jeton;
}
void Joueur::nouveauGain(int f){
  jetonDebutDeManche=jetonDebutDeManche+f;
}
void Joueur::augmentePot(int a){pot+=a;}
void Joueur::resetJ(){
  jetonDebutDePartie=jetonDebutDeManche;
  fold = false;
  allIn=false;
  pot=0;
  nbJPot=0;
}
ostream& operator<<(ostream& os, Joueur& j){
    j.affiche(os);
    return os;
}


void Joueur::setMainMax3(int val,Carte c)
{
	mainMax3[val] = c;
}

void Joueur::setMainMax4(int val,Carte c)
{
	mainMax4[val] = c;
}

void Joueur::setCartesMax(int val,Carte c)
{
	cartesMax[val] = c;
}

Carte Joueur::getMainMax3(int val)
{
	return mainMax3[val];
}

Carte Joueur::getMainMax4(int val)
{
	return mainMax4[val];
}

Carte Joueur::getCartesMax(int val)
{
	return cartesMax[val];
}

int Joueur::getValeurMain3()
{
	return valeurMain3;
}

int Joueur::getValeurMain4()
{
	return valeurMain4;
}

int Joueur::getValeurMainMax()
{
	return valeurMainMax;
}

void Joueur::setValeurMain3(int val)
{
	valeurMain3 = val;
}

void Joueur::setValeurMain4(int val)
{
	valeurMain4 = val;
}

void Joueur::setValeurMainMax(int val)
{
	valeurMainMax = val;
}

void Joueur::setCarteMax(Carte new_carte)
{
	carteMax = new_carte;
}

Carte Joueur::getCarteMax()
{
	return carteMax;
}

