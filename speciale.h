#ifndef SPECIALE_H_INCLUDED
#define SPECIALE_H_INCLUDED

#include <iostream>
#include "Cartes.h"
#include "monstre.h"

class Speciale : public Cartes
{
protected :
    //std::string m_nom;
    int m_cycleVie;
    std::string m_effet;
    std::string m_state;
    std::string m_desciptif;
    ///  bool pr indentifier l'emplacement :
    ///  => deck
    ///  => hand
    ///  => graveyard

public :
    Speciale();
    Speciale(std::string _nom, int _cycleVie, std::string _effet, std::string _state);
    ~Speciale();
    std::string getNom()const;
    int getCycleVie()const;
    std::string getEffet()const;
    std::string getState()const;
    std::string getDescriptif()const;

    void setNom(std::string newNom);
    void setCycleVie(int newCycleVie);
    void setEffet(std::string newEffet);
    void setState(std::string newState);
    void setDescriptif(std::string newDesc);

    bool checkStateCycleLife();
    void checkConditionDestroy();
    void moveToGraveyard();


    void affiche(int x,int y);
};


/// Carte pour se proteger
class Bouclier : public Speciale
{
private :

public :
    Bouclier();
    Bouclier(std::string _nom, int _cycleVie, std::string _effet, std::string _state);
    ~Bouclier();

    void useShield();

};


/// Ressusciter un monstre
class Respawn : public Speciale
{
public :
    Respawn();
    Respawn(std::string _nom, int _cycleVie, std::string _effet, std::string _state);
    ~Respawn();
    void resetPV(Cartes *mobInGame);
    void moveStateToLife();


};


/// Se soigner
class KitSoin : public Speciale
{
private :
    int m_nbSoin = 20;

public :
    KitSoin();
    KitSoin(std::string _nom, int _cycleVie, std::string _effet, std::string _state);
    ~KitSoin();

    int getNbSoin()const;
    void setNbSoin(int newSoin);

    void addHealth(Cartes *mobInGame);
};


/// Augmenter le nombre d'energie
class Up : public Speciale
{
private :
    int m_nbEnergie;
public :
    Up();
    Up(std::string _nom, int _cycleVie, std::string _effet, std::string _state);
    ~Up();

    int getNbEnergie()const;
    void setNbEnergie(int newEnergie);

    void addEnergie(); /// Sur quel énergie ? - de combien ?? => à définir

};


/// Infliger des dégats à l'adversaire
class Poison : public Speciale
{
private :
    int m_damage = 30;
public :
    Poison();
    Poison(std::string _nom, int _cycleVie, std::string _effet, std::string _state);
    ~Poison();
    int getDamage() const;
    void setDamage(int newDamage);

    int setPoison(Cartes *mobInGame);
};


/// Augmenter les points d'attaque du monstre mais le joueur qui la pose perd des points de vie
class Malediction : public Speciale
{
public :
    Malediction();
    Malediction(std::string _nom, int _cycleVie, std::string _effet, std::string _state);
    ~Malediction();

    //void useCurse(Monstre &mobInGame, Joueur &playerInGame);
};

Bouclier *creerBouclier();
Respawn *creerRespawn();
KitSoin *creerKitSoin();
Poison *creerPoison();
Malediction *creerMalediction();
Up *creerUp();

#endif // SPECIALE_H_INCLUDED
