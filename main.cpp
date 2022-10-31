#include <iostream>
#include "menu.h"
#include "utilitaire.h"
#include "monstre.h"
#include "Joueur.h"
#include <vector>
#include <stdio.h>
#include <conio.h>
#include "jeu.h"
#include <ctime>


int main()
{
   /*contour_carte2(X_DECK + 12,Y_DECK,15);
    gotoligcol(X_DECK + 13, Y_DECK + 3 );
    std::cout<<" SPECIALE ";
    gotoligcol(X_DECK + 15, Y_DECK - 18);
    int touche = getch();

    for(int i =0;i<15;i++)
    {

    }*/
/*
    int touche;
    Monstre *loup = new Monstre("Loup-Garou","Foret",100,"Griffure",10,10,"Morsure",20,20);
    Monstre *zombie = new Monstre("Zombie","Tombe",0,"Coup d'tete",5,5,"Infection",25,25);
    Monstre *vampire = new Monstre("Vampire","Chateau",80,"Hypnose",10,10,"Drainage",20,10);
    Monstre *fantome = new Monstre("Fantome","Tombe",40,"Frayeur",10,10,"Cauchemard",20,20);
    Monstre *sorciere = new Monstre("Sorciere","Chateau",40,"Poison",10,10,"Paralysie",20,20);

    Joueur *joueurs = new Joueur;
    joueurs->ajoutDeck(loup);
    joueurs->ajoutCimetiere(zombie);
    Cartes *temp = new Cartes;
    gotoligcol(1,0);
    std::cout<<"RESPAWN";
    temp = joueurs->ressuciteMonstre();
    resetPV(temp);

    touche = getch();
    temp->affiche(X_DECK,Y_DECK-40-15);

    touche = getch();

    for(int i = 0 ; i<15 ; i++)
    {
        gotoligcol(X_DECK + i,Y_DECK-40-15);
        std::cout<<"                    ";
    }*/

    //joueurs[joueurActif]->ajoutDeck(temp);






    //boutique();
    menu();
    //Monstre *araignee = new Monstre("Araignee","Grotte",70,"Toile",60,10,"Venin",25,20);
    //Cartes *num1 = new Cartes;
    //num1 = araignee;

    //num1->affiche(0,0);
    //choixJoueur();
    /*affichageJeu();
    gotoligcol(40,0);*/
    /*int dommage;
    Joueur *Selma = new Joueur;
    Joueur *Adam = new Joueur;

    Monstre *araignee = new Monstre("Araignee","Grotte",70,"Toile",60,10,"Venin",25,20);
    Cartes *num1 = new Cartes;
    num1 = araignee;

    Energie *tombe = new Energie("Tombe");
    Energie *foret = new Energie ("Foret");
    Energie *chateau = new Energie("Chateau");
    Energie *foret2 = new Energie ("Foret");
    Energie *foret3 = new Energie ("Foret");
    Energie *foret4 = new Energie ("Foret");
    Energie *grotte = new Energie ("Grotte");
    Energie *grotte2 = new Energie ("Grotte");


    Selma->ajoutMain(tombe);
    Selma->ajoutMain(foret);
    Selma->ajoutMain(chateau);
    Selma->ajoutMain(foret2);
    Selma->ajoutMain(foret3);
    Selma->ajoutMain(foret4);
    Selma->ajoutMain(grotte);
    Selma->ajoutMain(grotte2);

    Selma->setPose(num1);

    std::cout<<"MONSTRE POSE :"<<Selma->getPose()->getNom()<<std::endl;

    for(auto elem : Selma->getMain())
    {
        std::cout<<elem->getNom()<<std::endl;
    }
    int touche;
    touche = getch();
    std::cout<<"ATTAQUE :"<<Selma->getPose()->getNom()<<std::endl;
    retirerEnergie(Selma);
     for(auto elem : Selma->getMain())
    {
        std::cout<<elem->getNom()<<std::endl;
    }*/

    /* Selma->setPose(num1);
     Adam->setPose(num2);


     std::cout<<" ARAIGNNEE : "<<Adam->getPose()->getPv()<<" PV:"<< Adam->getPv()<<std::endl;
     int touche;
     touche = getch();
     while(touche!= ESPACE)
     {
     dommage = attaquerNormale(Selma->getPose(),Adam->getPose());
     dommage += Adam->getPv();
     Adam->setPv(dommage);
     std::cout<<" ARAIGNNEE : "<<Adam->getPose()->getPv()<<" PV:"<< Adam->getPv()<<std::endl;
     touche = getch();

     }*/
    /*int touche;
    touche = getch();
    Monstre *loup = new Monstre("Loup-Garou","Foret",100,"Griffure",10,10,"Morsure",20,20);
    affichageInfo(loup);
    touche = getch();
    effaceInfo();*/

    /* Cartes *mons = new Cartes;
     Monstre *monstres = new Monstre;
     monstres->setPv(40);
     mons = monstres;
     std::cout<<mons->getPv();*/
    // menu();
    //Joueur *k;
    // affichageMonstreAdverse(k);

    //chargerJoueurs();
    /* int touche;
     touche = getch();

     while(touche!=13)
     {
         touche = getch();
         std::cout<<getch()<<std::endl;
     }*/
     //Jeu j;
     //j.chargerCarte();
     //chargerJoueurs();

    /*
    int i = 0;
    int x = 0;
    int y = 0;
    std::vector<Cartes*> deck;
    int num;
    // std::cin>>num;



    for(auto elem : j.get_allCartes())
    {
        elem->affiche(x,y);

        y+=20;

        if(y == 100)
        {
            x += 14;
            y=0;
        }

        if(i==num)
        {
            deck.push_back(elem);
        }

        i++;

    }


    std::cout<<"pv= "<< deck[0]->getPv()<<std::endl;
    deck[0]->setPv(678);
    std::cout<<"nv pv= "<<deck[0]->getPv()<<std::endl;*/
    /*
    std::srand ( unsigned ( std::time(0) ) );
    std::queue <Cartes *> tempDeck;
    Joueur jo("quelqun",500);

    jo.test();
    */



    //Joueur jo("quelqun",500);
    //jo.testCarte();
    //jo.viderDeck();

    /*
    std::string touche;
    int dommage;
    Monstre *loup = new Monstre("Loup-Garou","Foret",100,"Griffure",10,10,"Morsure",20,20);
    Monstre *zombie = new Monstre("Zombie","Tombe",50,"Coup d'tete",5,5,"Infection",25,25);

    loup->affiche(1,1);
    zombie->affiche(1,20);

    while(touche != "c")
    {
        std::cin >> touche;
    if(touche == "a")
        dommage = attaquerNormale(loup,zombie);

    if(touche == "b")
        dommage = attaquerSpeciale(loup,zombie);

    system("CLS");
    loup->affiche(1,1);
    zombie->affiche(1,20);
    std::cout << " dommage = " << dommage;
    }
    */

    return 0;
}
