#ifndef CARTE_H
#define CARTE_H
#include <iostream>

using namespace std;
class Carte{
    private:
        int valeur;
        int couleur;
    public:
        Carte();
        Carte(const Carte&);
        Carte(const int&, const int&);
        Carte& operator=(const Carte&);

        void setvaleur(const int&);
        void setcouleur(const int&);
        int getvaleur();
        int getcouleur();

        void affiche(ostream& os);
};
ostream& operator<<(ostream&,Carte&);
#endif
