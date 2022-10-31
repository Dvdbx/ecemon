#include "classJeu.h"
#include "Joueur.h"

void Jeu :: chargerCarte()
{ //A REFAIRE A PARTIR DU CHARMENT D'UN FICHIER!!!
    //CHARGEMENT DES MONSTRES
    Monstre *loup = creerLoup();
    Monstre *zombie = creerZombie();
    Monstre *vampire = creerVampire();
    Monstre *fantome = creerFantome();
    Monstre *sorciere = creerSorciere();
    Monstre *lutin = creerLutin();
    Monstre *elfe = creerElfe();
    Monstre *araignee = creerAraignee();



    m_allCartes.push_back(loup);
    m_allCartes.push_back(zombie);
    m_allCartes.push_back(vampire);
    m_allCartes.push_back(fantome);
    m_allCartes.push_back(sorciere);
    m_allCartes.push_back(lutin);
    m_allCartes.push_back(elfe);
    m_allCartes.push_back(araignee);



    //CHARGEMENT DES ENERGIES
    Energie *tombe = creerTombe();
    Energie *foret = creerForet();
    Energie *chateau = creerChateau();
    Energie *grotte = creerGrotte();
    m_allCartes.push_back(tombe);
    m_allCartes.push_back(foret);
    m_allCartes.push_back(chateau);
    m_allCartes.push_back(grotte);

    //CHARGEMENT DES CARTES SPECIALES
    Bouclier *bouclier = creerBouclier();
    Respawn *respawn = creerRespawn();
    KitSoin *kit = creerKitSoin();
    Poison *poison = creerPoison();
    Malediction *male = creerMalediction();
    Up *up = creerUp();
    m_allCartes.push_back(bouclier);
    m_allCartes.push_back(respawn);
    m_allCartes.push_back(kit);
    m_allCartes.push_back(male);
    m_allCartes.push_back(poison);
    m_allCartes.push_back(up);


}

std::vector<Cartes*> Jeu :: get_allCartes()const
{
    return m_allCartes;
}

void Jeu::afficher()const
{
    for(unsigned int i = 0; i< m_allCartes.size(); i++)
    {
        m_allCartes[i]->affiche(5,15*i);
        //afficher toutes les cartes du jeu
    }

}

std::vector<Joueur*> Jeu:: get_allJoueurs()
{
    return m_allJoueurs;
}

void Jeu:: addJoueurs(Joueur *j)
{
    m_allJoueurs.push_back(j);
}

