#include <iostream>
#include "Attaque.h"

Attaque::Attaque(std::string _nom,int _degats)
    :m_nom(_nom),m_degats(_degats)
{

}

Attaque::Attaque()
    :m_nom(" "),m_degats(0)
{

}

Attaque::~Attaque()
{

}

std::string Attaque::getNom()const
{
    return m_nom;
}

int Attaque::getDegats()const
{
    return m_degats;
}

void Attaque::setNom(std::string _nom)
{
    m_nom=_nom;
}
void Attaque::setDegats(int _degats)
{
    m_degats=_degats;
}

void Attaque :: augmente()
{
    m_degats += 10;
}
