#ifndef ENERGIES_H_INCLUDED
#define ENERGIES_H_INCLUDED
#include "monstre.h"
#include "Energies.h"
#include "speciale.h"
#include <vector>
#include "Cartes.h"
#include <iostream>
#include "utilitaire.h"

class Energie : public Cartes
{
private :

    std::string m_type;//type de carte
    std::string m_nom; //nom de la carte


public:
    Energie();
    Energie(std::string _nom);
    ~Energie();

    int getPoint()const;
    std::string getType()const;
    std::string getNom()const;
    void affiche(int x,int y);
};

Energie* creerTombe();
Energie* creerForet();
Energie* creerChateau();
Energie* creerGrotte();




#endif // ENERGIES_H_INCLUDED
