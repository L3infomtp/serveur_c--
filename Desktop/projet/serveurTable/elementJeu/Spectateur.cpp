#include "Spectateur.h"


Spectateur::Spectateur(){
    desc = 0;
    nom = "";
  
}
Spectateur::Spectateur(int i){
    desc = i;
    nom = "Anonyme";
    
}
Spectateur::Spectateur(int i,string s){
    desc = i;
    nom = s;
   
}

Spectateur::Spectateur(const Spectateur& s){
    desc = s.getDesc();
    nom = s.getNom();
}

int Spectateur::getDesc()const{
    return desc;
}
string Spectateur::getNom()const{
    return nom;
}

void Spectateur::setDesc(const int& i){
    desc = i;
}
void Spectateur::setNom(const string& s){
    nom = s;
}

void Spectateur::affiche(ostream& os)const{
    os<<nom<<" - "<<desc<<" - "<<endl;
}

ostream& operator<<(ostream& os, Spectateur& s){
    s.affiche(os);
    return os;
}

