#ifndef JOUEUR_H
#define JOUEUR_H
#include "monstre.h"
#include "Cartes.h"
#include <vector>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include "classJeu.h"

class Joueur
{
private:
    std::string m_nom;
    int m_argent;
    int m_pv = 100;
    bool m_monstre;
    Cartes *m_pose;
    Cartes *m_specialePose;//SI IL A UNE SPECIALE PERSISTANTE
    bool m_speciale;
    int m_bouclier;
    //Cartes *m_specialeActive;
    //int m_carteMiseEnJeu;
    Cartes *m_carteMiseEnJeu;
    std::vector<Cartes*> m_collection;
    std::vector<Cartes*> m_main;
    std::queue<Cartes*> m_deck;
    std::vector<Cartes*> m_cimetiere;

    bool m_defaite;

public:
    Joueur();
    Joueur(std::string _nom, int _argent);
    ~Joueur();

    std::string getNom();
    void setNom(std::string val);
    void setCarteMiseEnJeu(Cartes *newCarteMiseEnJeu);
    Cartes* getCarteMiseEnJeu();
    int getArgent();
    void setArgent(int val);
    int getPv();
    void setPv(int val);
    Cartes* getPose();
    void setPose(Cartes* val);
    std::vector<Cartes*> getCollection();
    void setCollection(std::vector<Cartes*> val);
    std::vector<Cartes*> getMain();
    void setMain(std::vector<Cartes*> val);
    std::queue<Cartes*> getDeck();
    void setm_cimetiere(std::vector<Cartes*> val);
    std::vector<Cartes*> getCimetiere();
    void setCimetiere(std::vector<Cartes*> val);
    void remplirCollection(Cartes *c);
    void afficheJoueur();
    void shuffleDeck();
    void choisirDeck();
    void miseEnJeu();
    void afficheMiseEnJeu();
    void piocherCarte();
    bool checkMonstreDeck();
    bool checkJoueurVie();
    void viderDeck();
    Cartes* getDerniereCarte();//RENVOIE LA PREMIERE CARTE DU DECK
    void popFirstCard();//SUPPRIME LA PREMIERE CARTE DU DECK
    void placeFin(); //MET LA PREMIERE CARTE DU DECK A LA FIN
    void popDeck();//SUPP LA PREMIERE CARTE
    void afficheMontre(int x,int y);
    void ajoutMain(Cartes* nv); //AJOUTER UNE CARTE A LA MAIN
    void videMain();
    int mainVide();
    void ajoutCimetiere(Cartes *nv);
    void monstrePose();
    void monstreMort();
    bool checkPose();
    int getPvMonstre()const;
    bool defaite();
    void Perdre();
    void popMain();
    void ajoutCollection(Cartes *nv);//AJOUTER UNE CARTE A LA COLLECTION
    void specialePose();
    void specialeMort();
    bool chekSpeciale();
    void setSpeciale(Cartes *nv);
    Cartes* ressuciteMonstre(); //RENVOIE LE DERNIER MONSTRE MORT
    void ajoutDeck(Cartes *nv);
    void setBouclier(int a);
    int getBouclier()const;
    void afficheBouclier();
    void ajoutEnergie();
    void videDeck();
    void UpAttaque();

    void test();


};

#endif // JOUEUR_H
