#ifndef CARTES_H_INCLUDED
#define CARTES_H_INCLUDED
#include <iostream>
#include "Attaque.h"
//#include "utilitaire.h"

// CLASSE MERE DE TOUTES LES TYPES DE CARTE
class Cartes
{
private:

protected:
    std::string m_nom;
    std::string m_type;
    int m_exemplaire;
    std::string m_description;

public:
    Cartes();
    Cartes(std::string _nom, std::string _type);
    virtual~Cartes();
    virtual void affiche(int x, int y);
    virtual void setNom(std::string _nom);
    virtual std::string getNom()const;
    virtual std::string getType()const;
    int getExemplaire();
    void setExemplaire(int _exemplaire);
    virtual int getPv()const;
    virtual std::string getDomaine()const;
    virtual std::string getNomAttaqueSpeciale()const;
    virtual std::string getNomAttaqueNormale()const;
    virtual Attaque getNormale();
    virtual Attaque getSpeciale();
    virtual void setPv(int _pv){}
    virtual int setPoison(Cartes *mobInGame);
    virtual void addHealth(Cartes *mobInGame){}
    virtual void AugmenteAttaque(){}

   // virtual void resetPV(Cartes *mobInGame){}
};
    //virtual int attaquerSpeciale(Monstre * a) {}
    //virtual int attaquerNormale(Monstre * a) {}
//    virtual std::string getNom()const;

    //virtual std::string getDomaine()const{};


#endif // CARTES_H_INCLUDED
