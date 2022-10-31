#include "speciale.h"
#include "monstre.h"

#define PV_MAX 100
#include "utilitaire.h"

/*********************
    Carte speciale
        Classe mère
**********************/
Speciale::Speciale() {}
Speciale::Speciale(std::string _nom, int _cycleVie, std::string _effet, std::string _state)
    :Cartes(_nom,"Speciale"), m_cycleVie(_cycleVie), m_effet(_effet), m_state(_state)
{


}
Speciale::~Speciale() {}
std::string Speciale::getNom()const
{
    return m_nom;
}
int Speciale::getCycleVie()const
{
    return m_cycleVie;
}
std::string Speciale::getEffet()const
{
    return m_effet;
}
std::string Speciale::getState()const
{
    return m_state;
}
std::string Speciale::getDescriptif()const
{
    return m_desciptif;
}


void Speciale::setNom(std::string newNom)
{
    m_nom = newNom;
}
void Speciale::setCycleVie(int newCycleVie)
{
    m_cycleVie = newCycleVie;
}
void Speciale::setEffet(std::string newEffet)
{
    m_effet = newEffet;
}
void Speciale::setState(std::string newState)
{
    m_state = newState;
}
void Speciale::setDescriptif(std::string newDesc)
{
    m_desciptif = newDesc;
}

bool Speciale::checkStateCycleLife()
{
    if(getCycleVie() == 0)
    {
        return false;
    }
    else
        return true;
}
void Speciale::checkConditionDestroy()
{
    if(checkStateCycleLife() == false)
        setState("isOut");
}


void Speciale::moveToGraveyard()
{
    if(getState() == "isOut")
    {
        //=> move to graveyard
    }

}

void Speciale :: affiche(int x,int y)
{

    contour_carte(x,y,15);

    if(getNom()=="Malediction")
    {
        y-=2;
        gotoligcol(x+1,y+5);
        std::cout << getNom();
        y+=2;
    }
    else if(getNom()=="Bouclier")
    {
        y-=1;
        gotoligcol(x+1,y+5);
        std::cout << getNom();
        y+=1;
    }
    else
    {
        gotoligcol(x+1,y+5);
        std::cout << getNom();
    }

    color(15,0);
    if(getNom()=="Revivre")
    {
        gotoligcol(x+3,y+2);
        std::cout <<"Ressucite";
        gotoligcol(x+4,y+2);
        std::cout <<"un monstre";
        gotoligcol(x+5,y+2);
        std::cout <<"mort";

    }
    else if(getNom()=="Bouclier")
    {
        gotoligcol(x+3,y+2);
        std::cout <<"Protege le ";
        gotoligcol(x+4,y+2);
        std::cout <<"monstre de ";
        gotoligcol(x+5,y+2);
        std::cout <<"la prochaine";
        gotoligcol(x+6,y+2);
        std::cout<<"attaque";

    }
    else if(getNom()=="KitSoin")
    {
        gotoligcol(x+3,y+2);
        std::cout <<"Te soigne";
        gotoligcol(x+4,y+2);
        std::cout <<"+10 PV";
    }
    else if(getNom()=="Poison")
    {
        gotoligcol(x+3,y+2);
        std::cout <<"Inflige des ";
        gotoligcol(x+4,y+2);
        std::cout <<"des degats";
        gotoligcol(x+5,y+2);
        std::cout <<"a ton ";
        gotoligcol(x+6,y+2);
        std::cout <<"adversaire";
    }
    else if(getNom()=="Malediction")
    {
        gotoligcol(x+3,y+2);
        std::cout <<"Le monstre";
        gotoligcol(x+4,y+2);
        std::cout <<"adverse ne ";
        gotoligcol(x+5,y+2);
        std::cout <<"peut pas";
        gotoligcol(x+6,y+2);
        std::cout <<"attaquer au";
        gotoligcol(x+7,y+2);
        std::cout <<"prochain";
        gotoligcol(x+8,y+2);
        std::cout <<"tour";
    }
    else if(getNom() == "Up")
    {
        gotoligcol(x+3,y+2);
        std::cout <<"Tu gagnes";
        gotoligcol(x+4,y+2);
        std::cout <<"une carte ";
        gotoligcol(x+5,y+2);
        std::cout <<"energie";

    }






    //gotoligcol(x+4,y+2);
    // std::cout<<getEffet;

    //gotoligcol(x+5,y+2);
    //std::cout <<getSpeciale().getNom()<<":"<<getSpeciale().getDegats()<<"pv" ;*/

    gotoligcol(30,50);
}






/********************
    Classe fille
*********************/
/// Bouclier
Bouclier::Bouclier() {}
Bouclier::Bouclier(std::string _nom, int _cycleVie, std::string _effet, std::string _state)
    :Speciale(_nom, _cycleVie, _effet, _state) {}
Bouclier::~Bouclier() {}


void Bouclier::useShield()
{
    // à reflechir : il faut trouver un moyen de récuperer les damage de l'adv
}


/// Respawn
Respawn::Respawn() {}
Respawn::Respawn(std::string _nom, int _cycleVie, std::string _effet, std::string _state)
    :Speciale(_nom, _cycleVie, _effet, _state) {}
Respawn::~Respawn() {}
/*
void Respawn::resetPV(Cartes *mobInGame)
{
    if(mobInGame->getNom() == "Loup-Garou")
    {
        mobInGame->setPv(100);
    }
    else if(mobInGame->getNom() == "Zombie")
    {
        mobInGame->setPv(50);
    }
    else if(mobInGame->getNom() == "Vampire")
    {
        mobInGame->setPv(80);
    }
    else if(mobInGame->getNom() == "Fantome")
    {
        mobInGame->setPv(40);
    }
    else if(mobInGame->getNom() == "Sorciere")
    {
        mobInGame->setPv(40);
    }
    else if(mobInGame->getNom() == "Lutin")
    {
        mobInGame->setPv(30);
    }
    else if(mobInGame->getNom() == "Elfe")
    {
        mobInGame->setPv(30);
    }
    else if(mobInGame->getNom() == "Araignee")
    {
        mobInGame->setPv(70);
    }



}*/

/*
void Respawn::setPV(Monstre monstre){
    monstre->setPV(PV_MAX);

}
*/
void Respawn::moveStateToLife()
{
    if(getState() == "isDied")
    {
        setState("isLiving");
    }
}


/// KitSoin
KitSoin::KitSoin() {}
KitSoin::KitSoin(std::string _nom, int _cycleVie, std::string _effet, std::string _state)
    :Speciale(_nom, _cycleVie, _effet, _state) {}

KitSoin::~KitSoin() {}

int KitSoin::getNbSoin()const
{
    return m_nbSoin;
}

void KitSoin::setNbSoin(int newSoin)
{
    m_nbSoin = newSoin;
}

void KitSoin::addHealth(Cartes *mobInGame)
{

    mobInGame->setPv(mobInGame->getPv() + getNbSoin());
    //setCycleVie(getCycleVie()-1);

}


/// Up
Up::Up() {}
Up::Up(std::string _nom, int _cycleVie, std::string _effet, std::string _state)
    :Speciale(_nom, _cycleVie, _effet, _state) {}
Up::~Up() {}
int Up::getNbEnergie()const
{
    return m_nbEnergie;
}
void Up::setNbEnergie(int newEnergie)
{
    m_nbEnergie = newEnergie;
}
void Up::addEnergie()
{


}


/// Poison
Poison::Poison() {}
Poison::Poison(std::string _nom, int _cycleVie, std::string _effet, std::string _state)
    :Speciale(_nom, _cycleVie, _effet, _state) {}
Poison::~Poison() {}

int Poison::getDamage()const
{
    return m_damage;
}

void Poison::setDamage(int newDamage)
{
    m_damage = newDamage;
}

int Poison::setPoison(Cartes *mobInGame)
{
    int degat = mobInGame->getPv()-getDamage();
    if (  degat < 0 )
    {
        mobInGame->setPv(0);
        return degat;
    }
    else
    {
        mobInGame->setPv(mobInGame->getPv()-getDamage());
        return 0;
    }


}


/// Malédiction
/*
 * Fonctionnement de la carte :
 * -> divise la vie du monstre de l'adversaire par 2
 * -> mais le jouer jouant cette carte perd 30 PV
 */
Malediction::Malediction() {}
Malediction::Malediction(std::string _nom, int _cycleVie, std::string _effet, std::string _state)
    :Speciale(_nom, _cycleVie, _effet, _state)
{
    setCycleVie(1);

}
Malediction::~Malediction() {}


/*
void Malediction::useCurse(){

}
*/
Bouclier *creerBouclier()
{
    Bouclier *bouclier = new Bouclier("Bouclier",3,"Protege le monstre de la prochaine attaque","ok");
    return bouclier;
}

Respawn *creerRespawn()
{
    Respawn *respawn = new Respawn("Revivre",6," Ressucite un monstre depuis le cimetiere","ok");
    return respawn;
}

KitSoin *creerKitSoin()
{
    KitSoin *kit = new KitSoin("KitSoin",6,"Soigne l'utilisateur","ok");
    return kit;
}

Poison *creerPoison()
{
    Poison *poison = new Poison("Poison",4,"Inflige des degats l'adversaire","ok");
    return poison;
}

Malediction *creerMalediction()
{
    Malediction *male = new Malediction("Malediction",6,"Le monstre adverse ne peut attaquer au prochain tour","ok");
    return male;
}

Up *creerUp()
{
    Up *up = new Up("Up",0,"Tu gagne une carte energie","ok");
    return up;
}
