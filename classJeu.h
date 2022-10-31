#ifndef CLASSJEU_H_INCLUDED
#define CLASSJEU_H_INCLUDED
#include "utilitaire.h"

class Joueur;

class Jeu
{

private :
    std::vector< Cartes* > m_allCartes ;
    std::vector< Joueur* > m_allJoueurs;

public :
    Jeu(){};
    ~Jeu(){m_allCartes.clear();m_allJoueurs.clear();}

    std::vector<Joueur*> get_allJoueurs();
    std::vector<Cartes*> get_allCartes()const;

    void addJoueurs(Joueur* j);
    void setAllCartes(std::vector<Cartes*> allCartes);
    void chargerCarte();

    void afficher()const;
};

#endif // CLASSJEU_H_INCLUDED
