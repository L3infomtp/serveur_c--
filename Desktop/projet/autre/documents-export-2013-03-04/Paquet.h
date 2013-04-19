#ifndef PAQUET_H
#define PAQUET_H
#include <vector>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include "C:\Users\Maryan\Documents\ProjetL3\ProjetL3\include\Carte.h"

using namespace std;

class Paquet{
    private:
        vector<Carte> cartes;
    public:
        Paquet();
        Carte sortirCarte();
        void initialiserPaquet();
        int getTaille();
};

#endif
