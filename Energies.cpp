#include "Energies.h"
#include <iostream>

/// CLASS MERE ENERGIES
Energie :: Energie()
{

}

Energie :: Energie(std::string _nom)
    : m_type("Energie"),m_nom(_nom)
{

}
Energie :: ~Energie()
{

}



std::string Energie :: getType()const
{
    return m_type;
}

std::string Energie :: getNom()const
{
    return m_nom;
}


void Energie :: affiche(int x,int y)
{
    int couleur=15;

    if(getNom() == "Chateau")
    {
        couleur=12;
    }
    if(getNom() == "Foret")
    {
        couleur=10;
    }
    if(getNom() == "Grotte")
    {
        couleur=3;
    }
    if(getNom() == "Tombe")
    {
        couleur=8;
    }


    contour_carte(x,y,couleur);
    color(couleur,0);
    gotoligcol(x+1,y+5);
    std::cout << getNom();
    color(15,0);

    gotoligcol(x+3,y+2);
    std::cout << " Carte    ";

    gotoligcol(x+4,y+2);
    std::cout << " Energie  ";

    gotoligcol(x+5,y+2);
    std::cout <<"            ";

    gotoligcol(x+6,y+2);
    std::cout<<"            ";

    gotoligcol(x+7,y+2);
    std::cout<<"            ";

    gotoligcol(x+8,y+2);
    std::cout<<"            ";

    gotoligcol(30,50);
}

Energie* creerTombe()
{
    Energie *tombe = new Energie("Tombe");
    return tombe;
}
Energie* creerForet()
{
    Energie *foret = new Energie ("Foret");
    return foret;
}
Energie* creerChateau()
{
    Energie *chateau = new Energie("Chateau");
    return chateau;
}
Energie* creerGrotte()
{
    Energie *grotte = new Energie ("Grotte");
    return grotte;
}




