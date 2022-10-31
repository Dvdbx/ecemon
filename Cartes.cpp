#include "Cartes.h"
#include <iostream>

Cartes :: Cartes() {}
Cartes :: ~Cartes() {}

Cartes::Cartes(std::string _nom,std::string _type)
    :m_nom(_nom),m_type(_type){}

std::string Cartes::getNom()const
{
    return m_nom;
}
void Cartes :: setNom(std::string _nom)
{
    m_nom = _nom;
}

std::string Cartes::getType()const
{
    return m_type;
}

void Cartes :: affiche(int x,int y )
{
    std::cout << "je suis une carte" << std::endl;
}

int Cartes::getExemplaire()
{
    return m_exemplaire;
}
void Cartes::setExemplaire(int _exemplaire)
{
    m_exemplaire=_exemplaire;
}

int Cartes :: setPoison(Cartes *mobInGame)
{
    return 1;
}


Attaque Cartes :: getNormale()
{
    Attaque nv;
    return nv;
}

Attaque Cartes :: getSpeciale()
{
    Attaque nv;
    return nv;
}

int Cartes :: getPv()const
{
    return 1;
}


std::string Cartes ::  getDomaine()const
{
    return "ok";
}

std::string Cartes ::  getNomAttaqueSpeciale()const
{
    return "ok";
}

std::string Cartes :: getNomAttaqueNormale()const
{
    return "ok";
}
