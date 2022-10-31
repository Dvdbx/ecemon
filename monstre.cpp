#include <iostream>
#include "monstre.h"
#include "Attaque.h"
#include "utilitaire.h"

Monstre::Monstre()
{
   m_pv=0;
}

Monstre::Monstre(std::string _nom,std::string _domaine,int _pv,std::string _attaque1,int _degat1,std::string _attaque2,int _degat2)
    :Cartes(_nom,"Monstre"),m_domaine(_domaine),m_pv(_pv),m_normale(_attaque1,_degat1),m_speciale(_attaque2,_degat2) {}

Monstre::~Monstre() {}

std::string Monstre ::  getDomaine()const
{
    return m_domaine;
}

int Monstre::getPv()const
{
    return m_pv;
}

void Monstre::setPv(int _pv)
{
    m_pv =_pv;
}

bool Monstre::checkLife()const
{
    if(getPv() > 0)
    {
        return true;
    }
    else
        return false;
}

// le monstre a attaque le monstre b et retourne les degats en plus qu'il faudra infliger directement au joueur
int attaquerNormale(Cartes *a,Cartes *b)
{
    int dommage;
    dommage = b->getPv() - a->getNormale().getDegats();
    if(dommage >=0)
        {
            b->setPv(dommage);
            dommage=0;
        }
    if(dommage < 0)
        {
            b->setPv(0);
        }
        return dommage;
}

// le monstre a attaque le monstre b et retourne les degats en plus qu'il faudra infliger directement au joueur
int attaquerSpeciale(Cartes *a,Cartes *b)
{
    int dommage;

    dommage = b->getPv() - a->getSpeciale().getDegats();
    if(dommage >=0)
        {
            b->setPv(dommage);
            dommage=0;
        }
    if(dommage < 0)
        {
            b->setPv(0);
        }
        return dommage;
}

void Monstre :: affiche(int x,int y)
{
    int couleur=15;

    if(getDomaine()=="Chateau")
    {
        couleur = 12;
    }
    if(getDomaine()=="Tombe")
    {
        couleur = 8;
    }
    if(getDomaine()=="Foret")
    {
        couleur = 10;
    }
    if(getDomaine()=="Grotte")
    {
        couleur = 3;
    }

    contour_carte(x,y,15);
    color(couleur,0);
    gotoligcol(x+1,y+3);
    std::cout << getNom();

    color(15,0);

    gotoligcol(x+4,y+2);
    std::cout <<getNormale().getNom()<<":";
    gotoligcol(x+5,y+2);
    std::cout<<getNormale().getDegats()<<" pts";

    gotoligcol(x+6,y+2);
    std::cout <<getSpeciale().getNom()<<":";
    gotoligcol(x+7,y+2);
    std::cout<< getSpeciale().getDegats()<<" pts";

    color(10,0);
    gotoligcol(x+9,y+7);
    std::cout<<getPv()<<" PV";
    color(15,0);

}



Attaque Monstre::getNormale()
{
    return m_normale;
}
Attaque Monstre::getSpeciale()
{
    return m_speciale;
}


std::string Monstre :: getNomAttaqueNormale()const
{
    return(m_normale.getNom());
}

std::string Monstre :: getNomAttaqueSpeciale()const
{
    return (m_speciale.getNom());
}

void Monstre :: AugmenteAttaque()
{
    m_normale.augmente();
}

//creation des monstres

Monstre * creerLoup()
{
    Monstre *loup = new Monstre("Loup-Garou","Foret",60,"Griffure",12,"Morsure",24);
    return loup;
}

Monstre * creerZombie()
{
    Monstre *zombie = new Monstre("Zombie","Tombe",50,"Coup d'tete",14,"Infection",28);
    return zombie;
}

Monstre * creerVampire()
{
    Monstre *vampire = new Monstre("Vampire","Chateau",60,"Hypnose",12,"Drainage",24);
    return vampire;
}

Monstre * creerFantome()
{
    Monstre *fantome = new Monstre("Fantome","Tombe",30,"Frayeur",20,"Cauchemard",40);
    return fantome;
}

Monstre* creerSorciere()
{
    Monstre *sorciere = new Monstre("Sorciere","Chateau",40,"Poison",18,"Paralysie",36);
    return sorciere;
}

Monstre * creerLutin()
{
    Monstre *lutin = new Monstre("Lutin","Grotte",40,"Ruse",18,"Croche-pied",36);
    return lutin;
}

Monstre* creerElfe()
{
    Monstre *elfe = new Monstre("Elfe","Foret",50,"Fleches",14,"Embuscade",28);
    return elfe;
}

Monstre* creerAraignee()
{
    Monstre *araignee = new Monstre("Araignee","Grotte",30,"Toile",20,"Venin",40);
    return araignee;
}
