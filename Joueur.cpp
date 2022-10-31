#include <iostream>
#include "Joueur.h"
#include <vector>
#include <queue>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include "utilitaire.h"
#define NB_DECK 15
#include <stdio.h>
#include <stdlib.h>


Joueur::Joueur()
{
    //ctor;
    m_defaite = false;
    m_monstre = false;
    m_speciale = false;
    //getMain().clear();
    getCimetiere().clear();
    getCollection().clear();
    m_bouclier = 0;

}

Joueur::~Joueur()
{
    //dtor
    //getMain().clear();
    getCimetiere().clear();
    getCollection().clear();
}

std::string Joueur ::  getNom()
{
    return m_nom;
}

void Joueur :: setNom(std::string val)
{
    m_nom = val;
}

void Joueur :: setCarteMiseEnJeu(Cartes *newCarteMiseEnJeu)
    {
        m_carteMiseEnJeu = newCarteMiseEnJeu;
    }

Cartes* Joueur :: getCarteMiseEnJeu()
    {
        return m_carteMiseEnJeu;
    }

    int Joueur :: getArgent()
    {
        return m_argent;
    }

    void Joueur :: setArgent(int val)
    {
        m_argent = val;
    }

    int Joueur :: getPv()
    {
        return m_pv;
    }
    void Joueur :: setPv(int val)
    {
        m_pv = val;
    }

     Cartes* Joueur :: getPose()
    {
        return m_pose;
    }

    void  Joueur :: setPose(Cartes* val)
    {
        m_pose = val;
    }

        std::vector<Cartes*> Joueur :: getCollection()
    {
        return m_collection;
    }
    void Joueur :: setCollection(std::vector<Cartes*> val)
    {
        m_collection = val;
    }

    std::vector<Cartes*> Joueur :: getMain()
    {
        return m_main;
    }
    void Joueur :: setMain(std::vector<Cartes*> val)
    {
        m_main = val;
    }

    std::queue<Cartes*> Joueur :: getDeck()
    {
        return m_deck;
    }
    void Joueur :: setm_cimetiere(std::vector<Cartes*> val)
    {
        m_cimetiere = val;
    }

    std::vector<Cartes*> Joueur ::  getCimetiere()
    {
        return m_cimetiere;
    }
    void Joueur :: setCimetiere(std::vector<Cartes*> val)
    {
        m_cimetiere = val;
    }

Joueur::Joueur(std::string _nom, int _argent)
{
    //copy ctor
    m_nom =_nom;
    m_argent=_argent;

    getMain().clear();
    getCimetiere().clear();
    getCollection().clear();

}


void Joueur :: remplirCollection(Cartes *c)
{
    m_collection.push_back(c);
}

void Joueur::shuffleDeck()
{
    std::srand ( unsigned ( std::time(0) ) );
    std::vector<Cartes*> temp;
    for(unsigned int i=0; i < 15; i++)
    {
        temp.push_back(m_deck.front());
        m_deck.pop();
    }
    std::random_shuffle( temp.begin(), temp.end());
    for(unsigned int i=0; i < temp.size(); i++)
    {
        m_deck.push(temp[i]);
    }
}

void Joueur::choisirDeck()
{
    system("CLS");

    const SHORT Mask = 32768;
    int carte=0;
    int nb=0;
    int k=0;
    //char c = 0xBA;
    int x = 0;
    int y = 0;
    int exemplaire = 0;
    int limite_monstre=0;

    Jeu jeu;
    jeu.chargerCarte();
    std::vector<Cartes*> tempCollection;
    std::vector<Cartes*> tempDeck;
    std::vector<Cartes*> Deck;
    tempCollection= jeu.get_allCartes();
    tempDeck=  jeu.get_allCartes();
    //Cartes *nv;


    //On charge une copie de collection
    for(unsigned int i = 0; i< tempCollection.size(); i++)
    {
        for(const auto & elem : m_collection)
        {
            if(tempCollection[i]->getNom() == elem->getNom())
                exemplaire+=1;

            tempCollection[i]->setExemplaire(exemplaire);
        }
        exemplaire=0;
    }

    gotoligcol(5,60);
    std::cout<<getNom()<<", CHOISIS LES CARTES QUE TU VEUX AJOUTER A TON DECK";
    gotoligcol(7,60);
    std::cout<<"APPUIES SUR LES FLECHES TE DEPLACER ET ENTREE POUR AJOUTER CETTE CARTE A TON DECK :";
    x=0;
    y=0;

    /*for(int l =0; l<50; l++)
    {
        gotoligcol(l,98);
        std::cout<<c;
    }*/

    //AFFICHAGE DE TOUTE LES CARTES:

    /* for(auto elem : tempCollection)
     {

         elem->affiche(x,y);

         y+=20;

         if(y == 100)
         {
             x += 14;
             y=0;
         }


     }*/

//SELECTION DES CARTES

    //ON AFFICHE LA PREMIERE CARTE
    tempCollection[0]->affiche(9,70);
    gotoligcol(13,90);
    std::cout << "IL RESTE " << tempCollection[0]->getExemplaire() << " " << tempCollection[0]->getNom() << "       ";

    while(nb<15)
    {

        if (GetKeyState(VK_LEFT) & Mask)
        {
            k=0;
            carte --;

            for(auto elem : tempCollection)
            {

                if(k == carte)
                {
                    gotoligcol(8,70);
                    std::cout<<"              ";
                    gotoligcol(9,70);
                    std::cout<<"              ";
                    gotoligcol(10,70);
                    std::cout<<"              ";
                    gotoligcol(11,70);
                    std::cout<<"              ";
                    gotoligcol(12,70);
                    std::cout<<"              ";
                    gotoligcol(13,70);
                    std::cout<<"              ";
                    gotoligcol(14,70);
                    std::cout<<"              ";
                    gotoligcol(15,70);
                    std::cout<<"              ";
                    gotoligcol(16,70);
                    std::cout<<"              ";
                    gotoligcol(17,70);
                    std::cout<<"              ";
                    gotoligcol(18,70);
                    std::cout<<"              ";
                    gotoligcol(19,70);
                    std::cout<<"              ";

                    gotoligcol(13,90);
                    std::cout << "IL RESTE " << elem->getExemplaire() << " " << elem->getNom() << "       ";
                    elem->affiche(9,70);
                }
                k++;
            }
        }
        if (GetKeyState(VK_RIGHT) & Mask)
        {
            k=0;
            carte ++;

            for(auto elem : tempCollection)
            {
                if(k == carte)
                {
                    gotoligcol(8,70);
                    std::cout<<"              ";
                    gotoligcol(9,70);
                    std::cout<<"              ";
                    gotoligcol(10,70);
                    std::cout<<"              ";
                    gotoligcol(11,70);
                    std::cout<<"              ";
                    gotoligcol(12,70);
                    std::cout<<"              ";
                    gotoligcol(13,70);
                    std::cout<<"              ";
                    gotoligcol(14,70);
                    std::cout<<"              ";
                    gotoligcol(15,70);
                    std::cout<<"              ";
                    gotoligcol(16,70);
                    std::cout<<"              ";
                    gotoligcol(17,70);
                    std::cout<<"              ";
                    gotoligcol(18,70);
                    std::cout<<"              ";
                    gotoligcol(19,70);
                    std::cout<<"              ";

                    gotoligcol(13,90);
                    std::cout << "IL RESTE " << elem->getExemplaire() << " " << elem->getNom() << "       ";
                    elem->affiche(9,70);
                }
                k++;
            }
        }

        gotoligcol(21,60);
        std::cout<<"ENCORE "<<15-nb<<" CARTES A CHOISIR!!";
        if(carte<0)
        {
            carte = 17;
        }
        if(carte>17)
        {
            carte=0;
        }


        Sleep(100);


        k=0;

        if(GetKeyState(VK_RETURN) & Mask)
        {

            for(unsigned int i = 0; i < tempCollection.size() ; i++)
            {

                if(k == carte)
                {
                    if(tempCollection[i]->getExemplaire() >0)
                    {
                        gotoligcol(14,90);
                        std::cout<<"                                 ";

                        //if((limite_monstre < 4)&&(tempCollection[i]->getType() == "Monstre"))
                        //{

                        if(tempCollection[i]->getNom()=="Sorciere")
                        {
                            Deck.push_back(creerSorciere());
                            limite_monstre++;
                        }
                        else if(tempCollection[i]->getNom()=="Loup-Garou")
                        {
                            Deck.push_back(creerLoup());
                            limite_monstre++;
                        }
                        else if(tempCollection[i]->getNom()=="Zombie")
                        {
                            Deck.push_back(creerZombie());
                            limite_monstre++;
                        }
                        else if(tempCollection[i]->getNom()=="Vampire")
                        {
                            Deck.push_back(creerVampire());
                            limite_monstre++;
                        }
                        else if(tempCollection[i]->getNom()=="Fantome")
                        {
                            Deck.push_back(creerFantome());
                            limite_monstre++;
                        }
                        else if(tempCollection[i]->getNom()=="Lutin")
                        {
                            Deck.push_back(creerLutin());
                            limite_monstre++;
                        }
                        else if(tempCollection[i]->getNom()=="Elfe")
                        {
                            Deck.push_back(creerElfe());
                            limite_monstre++;
                        }
                        else if(tempCollection[i]->getNom()=="Araignee")
                        {
                            Deck.push_back(creerAraignee());
                            limite_monstre++;
                        }
                       // }

                        else if(tempCollection[i]->getNom()=="Chateau")
                        {
                            Deck.push_back(creerChateau());
                        }
                        else if(tempCollection[i]->getNom()=="Tombe")
                        {
                            Deck.push_back(creerTombe());
                        }
                        else if(tempCollection[i]->getNom()=="Grotte")
                        {
                            Deck.push_back(creerGrotte());
                        }
                        else if(tempCollection[i]->getNom()=="Foret")
                        {
                            Deck.push_back(creerForet());
                        }

                        else if(tempCollection[i]->getNom()=="Bouclier")
                        {
                            Deck.push_back(creerBouclier());
                        }
                        else if(tempCollection[i]->getNom()=="Revivre")
                        {
                            Deck.push_back(creerRespawn());
                        }
                        else if(tempCollection[i]->getNom()=="KitSoin")
                        {
                            Deck.push_back(creerKitSoin());
                        }
                        else if(tempCollection[i]->getNom()=="Malediction")
                        {
                            Deck.push_back(creerMalediction());
                        }
                        else if(tempCollection[i]->getNom()=="Poison")
                        {
                            Deck.push_back(creerPoison());
                        }
                        else if(tempCollection[i]->getNom()== "Up")
                        {
                            Deck.push_back(creerUp());
                        }

                        //Deck.push_back(tempCollection[i]);
                        tempCollection[i]->setExemplaire(tempCollection[i]->getExemplaire() - 1);
                        // std::cout << "  " << tempCollection[i]->getNom() << " a ete ajoute              " << std ::endl;
                        gotoligcol(13,90);
                        std::cout << "IL RESTE " << tempCollection[i]->getExemplaire() << " " << tempCollection[i]->getNom() << "       ";
                        nb++;
                    }
                    else if(tempCollection[i]->getExemplaire() < 0)
                    {
                        gotoligcol(14,90);
                        std::cout << "  PLUS ASSEZ DE " << tempCollection[i]->getNom() << std ::endl;
                    }
                    /*
                    else if((limite_monstre >= 4)&&(tempCollection[i]->getType()=="Monstre"))
                    {
                        gotoligcol(14,90);
                        std::cout << " LIMITE DE 4 MONSTRES PAR DECK " << std ::endl;
                    }
                    */
                }

                k++;

            }
        }


    }
    Sleep(10);


    //l'attribut m_deck file prend la valeur du vecteur deck
    for(unsigned int i=0; i < Deck.size(); i++)
    {
        m_deck.push(Deck[i]);
    }

    // On charge une copie du deck triée pour l'affichage
    exemplaire =0 ;
    for(unsigned int i = 0; i< tempDeck.size(); i++)
    {
        for(const auto & elem : Deck)
        {
            if(tempDeck[i]->getNom() == elem->getNom())
                exemplaire+=1;

            tempDeck[i]->setExemplaire(exemplaire);
        }
        exemplaire=0;
    }

    system("CLS");


    int touche = 0;
    exemplaire=0;

    gotoligcol(1,70);
    std::cout<<getNom()<<" VOICI TON DECK POUR LE MATCH :";

    x=3;
    y=30;
    for(unsigned int i = 0; i< Deck.size()/*tempDeck.size() */; i++)
    {

        Deck[i]->affiche(x,y);
        //tempDeck[i]->affiche(x,y);
        gotoligcol(x+11,y+2);
        //std::cout << "X " << m_deck.front()->getExemplaire();

        y+=20;

        if(y == 150)
        {
            x += 14;
            y=30;
        }

    }

    std::cout<< " APPUYER SUR ESPACE POUR CONTINUER ";
    touche= getch();
    while (touche != ESPACE)
    {
        touche = getch();
    }


}

void Joueur :: popMain()
{
    m_main.pop_back();
}

void Joueur :: ajoutCollection(Cartes *nv)
{
    m_collection.push_back(nv);
}

void Joueur::miseEnJeu()
{
    Jeu jeu;
    Joueur joueur;
    srand(time(NULL));

    //std::vector<Cartes*> tempCollec;
    //tempCollec = jeu.get_allCartes();

    int tailleCollec = m_collection.size();
    int rangCarte = rand()% tailleCollec + 1;
    Cartes *c = m_collection[rangCarte];

    setCarteMiseEnJeu(c);
}

void Joueur::afficheMiseEnJeu()
{
    std::cout << "La carte mise en jeu est : ";
    /// Affichage carte graphique ???
    getCarteMiseEnJeu();
}

/// piocher une carte que l'on met dans la main
/// a voir si on garde la main
void Joueur::piocherCarte()
{
    Cartes *tmpCarte = m_deck.front();
    m_deck.pop();
    m_main.push_back(tmpCarte);
}

bool Joueur::checkMonstreDeck()
{
    while(!m_deck.empty())
    {
        std::string nom = m_deck.front()->getNom();
        /// Normalement avec le getType => plus simple
        if(nom == "Loup-Garou" || nom == "Zombie" || nom == "Vampire" || nom == "Fantome")
        {
            return true;
        }
        else
        {
            m_deck.pop();
        }
    }
    return false;
}

bool Joueur::checkJoueurVie()
{
    bool valeur;
    if(getPv() > 0)
        valeur = true;

    else if(getPv() <= 0)
        valeur = false;

    return valeur;
}

void Joueur::viderDeck()
{
    while(!m_deck.empty())
    {
        m_deck.pop();
    }
    std::cout << "Empty" << std::endl;
}


Cartes* Joueur :: getDerniereCarte()
{
    return ( m_deck.front());
}

void Joueur :: popFirstCard()
{
    m_deck.pop();
}

void Joueur::placeFin()
{
    m_deck.push(m_deck.front());
    m_deck.pop();
}


void Joueur :: popDeck()
{
    m_deck.pop();
}


void Joueur :: afficheMontre(int x,int y)
{
    m_pose->affiche(x,y);
}


void Joueur :: ajoutMain(Cartes* nv)
{
    m_main.push_back(nv);
}


void Joueur :: videMain()
{
    for(auto elem : m_main)
    {
        elem = elem;
        m_main.pop_back();
    }
}

int Joueur ::  mainVide()
{
    if(m_main.size() == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


void Joueur ::  ajoutCimetiere(Cartes *nv)
{
    m_cimetiere.push_back(nv);
}

void Joueur ::  monstrePose()
{
    m_monstre = true;
}
void Joueur :: monstreMort()
{
    m_monstre = false;
}
bool Joueur :: checkPose()
{
    return m_monstre;
}

int Joueur :: getPvMonstre()const
{
    return ( m_pose->getPv() );
}

bool Joueur :: defaite()
{
    if(m_defaite == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Joueur :: Perdre()
{
    m_defaite = true;
}


void Joueur :: specialePose()
{
    m_speciale = true;
}

void Joueur :: specialeMort()
{
    m_speciale = false;
}

bool Joueur :: chekSpeciale()
{
    return m_speciale;
}

void Joueur :: setSpeciale(Cartes *nv)
{
    m_speciale = nv;
}

Cartes* Joueur :: ressuciteMonstre()
{
    std::vector<Cartes*> temp;
    Cartes *re = new Cartes;
    int i=0;
    unsigned int y =0;
    for(auto elem : m_cimetiere)
    {
        if( (elem->getType() == "Monstre") && (i<1) )
        {
            re = elem;
            i++;
        }
        else
        {
            y++;
            temp.push_back(elem);
        }
    }

   if(y == m_cimetiere.size())
    {
        re->setNom("NULL");
        return re;
    }
    else
    {
        m_cimetiere = temp;
        return re;
    }
    //return re;

}

void Joueur :: ajoutDeck(Cartes *nv)
{
    m_deck.push(nv);
}

void Joueur :: setBouclier(int a)
{
    m_bouclier = a;
}

int Joueur :: getBouclier()const
{
    return m_bouclier;
}

void Joueur :: afficheBouclier()
{
    for(int i = 0; i<13; i++)
    {
        gotoligcol(X_DECK + 12 +i,Y_DECK);
        std::cout<<"                          ";

    }
    Bouclier *bouclier = new Bouclier("Bouclier",3,"Protege le monstre de la prochaine attaque","ldk");
    bouclier->affiche(X_DECK + 12,Y_DECK);
}

void Joueur :: ajoutEnergie()
{
    srand(time(NULL));
    int alea = rand()%3;
    Energie *tombe = new Energie("Tombe");
    Energie *foret = new Energie ("Foret");
    Energie *chateau = new Energie("Chateau");
    Energie *grotte = new Energie ("Grotte");
    switch(alea)
    {
    case 0:

        m_main.push_back(tombe);
        break;
    case 1:

        m_main.push_back(foret);
        break;
    case 2:

        m_main.push_back(chateau);
        break;
    case 3:

        m_main.push_back(grotte);
        break;



    }
}

void Joueur :: videDeck()
{
   for (unsigned int i = 0; i<m_deck.size(); i++)
   {
       m_deck.pop();
   }
}

void Joueur :: UpAttaque()
{
    m_pose->AugmenteAttaque();
}

void Joueur::test()
{
    Jeu j;
    j.chargerCarte();
    setCollection(j.get_allCartes());
    choisirDeck();
    shuffleDeck();
    for(unsigned int i = 0; i< 15; i++)
       {
           m_deck.front()->affiche(1,i*8);
           m_deck.pop();
       }
}
