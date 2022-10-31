#ifndef MONSTRE_H_INCLUDED
#define MONSTRE_H_INCLUDED
#include "Cartes.h"
#include "Attaque.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

class Monstre : public Cartes
{
protected :

    std::string m_domaine;
    int m_pv;
    Attaque m_normale;
    Attaque m_speciale;

public:
    Monstre();
    ~Monstre();
    Monstre(std::string _nom,std::string _domaine,int _pv,std::string _attaque1,int _degat1,std::string _attaque2,int _degat2);

    std::string getNomAttaqueNormale()const;
    std::string getNomAttaqueSpeciale()const;
    std::string getDomaine()const;
    int getPv()const;
    void setPv(int _pv);
    Attaque getNormale();
    Attaque getSpeciale();
    int attaquerNormale(Monstre *a);
    int attaquerSpeciale(Monstre *a);
    void affiche(int x,int y);
    bool checkLife()const;
    void AugmenteAttaque();
};

int attaquerSpeciale(Cartes *a,Cartes *b);
int attaquerNormale(Cartes *a,Cartes *b);

Monstre * creerLoup();
Monstre * creerZombie();
Monstre * creerVampire();
Monstre * creerFantome();
Monstre* creerSorciere();
Monstre * creerLutin();
Monstre* creerElfe();
Monstre *creerAraignee();

#endif // MONSTRE_H_INCLUDED
