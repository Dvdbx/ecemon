#include <iostream>
#include "utilitaire.h"
#include <stdlib.h>
#include <windows.h>
#include "menu.h"
#include "jeu.h"
#include <stdio.h>
#include <conio.h>
#include <fstream>

void affichage_menu()
{
    char a;

    a = 0xCD;
    color(11,0);
    for(int i=0; i<172; i++)
    {
        gotoligcol(0,i);
        std::cout<<a;
    }

    for(int i=0; i<172; i++)
    {
        gotoligcol(40,i);
        std::cout<<a;
    }
    /* a = 0xC9;
     gotoligcol(0,0);
     std::cout<<a;*/

    /*a = 0xBA;

    for(int i = 2;i<38;i++)
    {
        gotoligcol(i,0);
        std::cout<<a;
    }*/


    gotoligcol(4,85);
    color(11,0);
    std::cout<<"ECEMON";

    gotoligcol(8,80);
    color(11,0);
    std::cout<<" -NOUVELLE PARTIE-  ";
    color(15,0);
    gotoligcol(10,80);
    std::cout<<"  NOUVEAU JOUEUR  ";
    gotoligcol(12,80);
    std::cout<<"  BOUTIQUE  ";
    gotoligcol(14,80);
    std::cout<<"  REGLES  ";
    gotoligcol(16,80);
    std::cout<<"  AUTEURS  ";
    gotoligcol(18,80);
    std::cout<<"  QUITTER  ";
}

void menu2(int position)
{
    switch(position)
    {
    case 1:
        gotoligcol(8,80);
        color(11,0);
        std::cout<<" -NOUVELLE PARTIE-  ";
        color(15,0);
        gotoligcol(10,80);
        std::cout<<"  NOUVEAU JOUEUR  ";
        gotoligcol(12,80);
        std::cout<<"  BOUTIQUE  ";
        gotoligcol(14,80);
        std::cout<<"  REGLES  ";
        gotoligcol(16,80);
        std::cout<<"  AUTEURS  ";
        gotoligcol(18,80);
        std::cout<<"  QUITTER  ";
        break;


    case 2:
        gotoligcol(8,80);
        std::cout<<"  NOUVELLE PARTIE  ";
        gotoligcol(10,80);
        color(11,0);
        std::cout<<" -NOUVEAU JOUEUR-  ";
        gotoligcol(12,80);
        color(15,0);
        std::cout<<"  BOUTIQUE ";
        gotoligcol(14,80);
        std::cout<<"  REGLES  ";
        gotoligcol(16,80);
        std::cout<<"  AUTEURS  ";
        gotoligcol(18,80);
        std::cout<<"  QUITTER  ";
        break;
    case 3:
        gotoligcol(8,80);
        color(15,0);
        std::cout<<"  NOUVELLE PARTIE  ";
        gotoligcol(10,80);
        std::cout<<"  NOUVEAU JOUEUR  ";
        gotoligcol(12,80);
        color(11,0);
        std::cout<<" -BOUTIQUE-  ";
        color(15,0);
        gotoligcol(14,80);
        std::cout<<"  REGLES  ";
        gotoligcol(16,80);
        std::cout<<"  AUTEURS  ";
        gotoligcol(18,80);
        std::cout<<"  QUITTER  ";
        break;
    case 4:
        gotoligcol(8,80);
        color(15,0);
        std::cout<<"  NOUVELLE PARTIE  ";
        gotoligcol(10,80);
        std::cout<<"  NOUVEAU JOUEUR  ";
        gotoligcol(12,80);
        std::cout<<"  BOUTIQUE ";
        gotoligcol(14,80);
        color(11,0);
        std::cout<<" -REGLES-  ";
        color(15,0);
        gotoligcol(16,80);
        std::cout<<"  AUTEURS  ";
        gotoligcol(18,80);
        std::cout<<"  QUITTER  ";
        break;
    case 5:
        gotoligcol(8,80);
        color(15,0);
        std::cout<<"  NOUVELLE PARTIE  ";
        gotoligcol(10,80);
        std::cout<<"  NOUVEAU JOUEUR  ";
        gotoligcol(12,80);
        std::cout<<"  BOUTIQUE  ";
        gotoligcol(14,80);
        std::cout<<"  REGLES  ";
        gotoligcol(16,80);
        color(11,0);
        std::cout<<" -AUTEURS-  ";
        color(15,0);
        gotoligcol(18,80);
        std::cout<<"  QUITTER  ";
        break;
    case 6:
        gotoligcol(8,80);
        color(15,0);
        std::cout<<"  NOUVELLE PARTIE  ";
        gotoligcol(10,80);
        std::cout<<"  NOUVEAU JOUEUR  ";
        gotoligcol(12,80);
        std::cout<<"  BOUTIQUE  ";
        gotoligcol(14,80);
        std::cout<<"  REGLES  ";
        gotoligcol(16,80);
        std::cout<<"  AUTEURS  ";
        gotoligcol(18,80);
        color(11,0);
        std::cout<<" -QUITTER-  ";
        color(15,0);
        break;

    }
}


void menu()
{
    system("CLS");
    int choix=1;
    int touche;


    while(choix!=7)
    {
        system("CLS");
        affichage_menu();
        //choix = 7;
        Sleep(100);

        do
        {

            menu2(choix);

            touche = getch();

            switch(touche)
            {
            case 80:
                choix++;
                break;
            case 72:
                choix --;
                break;
            }


            if(choix<1)
            {
                choix = 6;
            }
            else if(choix>6)
            {
                choix = 1;
            }



        }
        while(touche!=13);




        switch(choix)
        {
        case 1:

            choixJoueur();
            break;

        case 2:
            nouveauJoueur();
            break;

        case 3:
            boutique();

            break;

        case 4:
            regles();

            break;

        case 5:
            auteurs();

            break;

        case 6:
            system("CLS");
            choix = 7;
            break;

        case 8:
            break;

        }



    }


}

void auteurs()
{
    system("CLS");
    char a;

    //int touche;

    //touche =0;
    a= 0xCD;

    color(11,0);
    for(int i=0; i<172; i++)
    {
        gotoligcol(0,i);
        std::cout<<a;
    }

    for(int i=0; i<172; i++)
    {
        gotoligcol(40,i);
        std::cout<<a;
    }

    gotoligcol(4,70);
    color(15,0);
    std::cout<<"AUTEURS";
    gotoligcol(8,68);
    std::cout<<"HU Valentina";
    gotoligcol(10,68);
    std::cout<<"SU David";
    gotoligcol(12,68);
    std::cout<<"ZARGA Selma";

    /*touche = */getch();
    system("CLS");
    return;



}


void regles()
{
    system("CLS");
    char a;
    //int touche=0;


    a= 0xCD;
    color(11,0);
    for(int i=0; i<172; i++)
    {
        gotoligcol(0,i);
        std::cout<<a;
    }

    for(int i=0; i<172; i++)
    {
        gotoligcol(40,i);
        std::cout<<a;
    }

    gotoligcol(4,70);
    color(15,0);
    std::cout<<"ECEMON";
    gotoligcol(6,40);
    std::cout<<"ECEMON est un jeu de cartes type Pokemon, il existe plusieurs type de cartes : Monstre,";
    gotoligcol(7,40);
    std::cout<<"Speciale, Energie. Vous allez devoir affronter votre adversaire et vous defendre grace a";
    gotoligcol(8,40);
    std::cout<<"vos cartes alors choisissez les bien. Au debut d'un match vous allez devoir choisir parmi";
    gotoligcol(9,40);
    std::cout<<"votre collection de carte 15 carte que vous allez utiliser durant le match";
    gotoligcol(10,40);
    std::cout<<"Placez un monstre devant vous afin d'attaquer le monstre ennemi. Pour attaquer";
    gotoligcol(11,40);
    std::cout<<"et utiliser les cartes speciales vous allez avoir besoin de differents type d'energies";
    gotoligcol(12,40);
    std::cout<<"Le premier joueur qui n'a plus de points de vie ou qui n'a plus de monstre a perdu";
    gotoligcol(13,40);
    std::cout<<"Le gagnant recupere la carte mise en jeu du perdant au debut de la partie";
    gotoligcol(14,40);
    std::cout<<"A vous de jouer!!";

    /*touche =*/ getch();
    system("CLS");
    return;



}

void boutique() //ACHETER UNE NV CARTE
{
    //recuperer le tableau de joueur
    //effacer tout le fichier
    //si le joueur choisis a la fin de sa ligne :  numero de la nv carte
    //on ecrit le reste
    std::vector <Joueur*> allPlayers = chargerJoueurs();
    std::vector<Joueur*> joueurs;// LES JOUEURS CHOSIS
    system("CLS");
    color(15,0);
    gotoligcol(1,1);
    int nb=0;
    int touche=0;
    ///int ok = 0;
    Joueur *jouer;


    // touche = getch();




    system("CLS");


    gotoligcol(2,70);
    color(15,0);
    std::cout<<"QUI VEUX ACHETER UNE CARTE?";


    gotoligcol(6,30);
    color(11,0);
    std::cout<<"LISTE DES JOUEURS:";
    unsigned int i =0;
    int k=0;
    unsigned int y =0;
    ///int numJoueur = 0;

    color(15,0);



    for(auto elem : allPlayers)
    {
        gotoligcol(9+i,30);
        std::cout<<" "<<elem->getNom();
        i+=2;

    }
    gotoligcol(9,30);
    color(12,0);
    std::cout<<"-"<<allPlayers[0]->getNom();
    color(15,0);

    gotoligcol(6,70);
    std::cout<<"JOUEUR CHOISI: ";

    ///long unsigned int choix=0;
    unsigned int choix =0;
    int m =0;

    while(k != 1)
    {


        touche = getch();
        i=0;
        y=0;

        switch(touche)
        {
        case 80:
            choix++;
            break;
        case 72:
            choix --;
            break;
        }

        if(choix<0)
        {
            choix =  allPlayers.size() ;
        }
        if(choix >   allPlayers.size()  )
        {
            choix = 0;
        }


        for(auto elem : allPlayers)
        {
            if((i/2) == choix)
            {
                gotoligcol(9+i,30);
                color(12,0);
                std::cout<<"-"<<elem->getNom();
            }
            else
            {
                gotoligcol(9+i,30);
                color(15,0);
                std::cout<<" "<<elem->getNom();
            }


            i+=2;



        }

        if(touche == 13)
        {
            for(auto elem : allPlayers)
            {
                if(y == choix )
                {
                    joueurs.push_back(elem);
                    jouer = elem;
                    k++;
                }

                y++;

            }
        }

        m = 0;


        if(joueurs.size()!=0)
        {
            for(unsigned int i = 0 ; i< joueurs.size(); i++)
            ///for(auto elem : joueurs)
            {
                gotoligcol(9+ m,70);
                std::cout<<allPlayers[choix]->getNom();
                m++;
            }

        }


    }
    touche = getch();
    jouer->setArgent(100);

    Jeu jeu;
    jeu.chargerCarte();
    std::vector <Cartes*> tempCollection;
    system("CLS");
    const SHORT Mask = 32768;
    int carte=0;
    nb=0;
    k=0;
    ///char c = 0xBA;
    int x = 0;
    y = 0;
    int exemplaire = 0;
    bool out= false;

    gotoligcol(5,60);
    std::cout<<allPlayers[choix]->getNom()<<", BIENVENUE DANS LA BOUTIQUE! CHOISIS LES CARTES QUE TU VEUX ACHETER";
    gotoligcol(7,60);
    std::cout<<"APPUIES SUR LES FLECHES POUR TE DEPLACER ET ENTREE POUR ACHETER CETTE CARTE";
    gotoligcol(30,60);
    std::cout<<"APPUIES SUR ESC POUR QUITTER";


    /* for(int l =0; l<50; l++)
     {
         gotoligcol(l,98);
         std::cout<<c;
     }*/

    //AFFICHAGE DE TOUTE LES CARTES:

    /* for(auto elem : jeu.get_allCartes())
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
    jeu.get_allCartes()[0]->affiche(9,70);
    gotoligcol(20,70);
    std::cout << "Il TE RESTE " << jouer->getArgent() << " PIECES    ";

    while(!out)
    {

        if (GetKeyState(VK_LEFT) & Mask)
        {
            gotoligcol(20,70);
            std::cout<<"                                           ";
            k=0;
            carte --;

            for(auto elem : jeu.get_allCartes())
            {

                if(k == carte)
                {

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

                    elem->affiche(9,70);
                }
                k++;
            }
        }
        if (GetKeyState(VK_RIGHT) & Mask)
        {
            gotoligcol(20,70);
            std::cout<<"                                           ";
            k=0;
            carte ++;

            for(auto elem : jeu.get_allCartes())
            {
                if(k == carte)
                {

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

                    elem->affiche(9,70);
                }
                k++;
            }
        }

        gotoligcol(20,70);
        std::cout << "Il TE RESTE " << jouer->getArgent() << " PIECES    ";
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


            for(auto elem : jeu.get_allCartes())
            {


                if(k == carte)
                {
                    if(jouer->getArgent() > 5)
                    {
                        allPlayers[choix]->ajoutCollection(elem);
                        tempCollection.push_back(elem);
                        jouer->setArgent(jouer->getArgent()-5);
                        std::cout << "  " << elem->getNom() << " A ETE AJOUTEE              " << std ::endl;
                        gotoligcol(13,70);
                        nb++;
                    }
                    else
                    {
                        gotoligcol(21,70);
                        color(12,0);
                        std::cout << "  PLUS ASSSEZ D'ARGENT " << elem->getNom() << std ::endl;
                        color(15,0);
                    }
                }

                k++;

            }
        }
        if(GetKeyState(VK_ESCAPE) & Mask)
        {
            out=true;
        }



    }
    Sleep(10);


    // On charge de la collection trriée pour l'affichage
    exemplaire =0 ;
    for(unsigned int i = 0; i< tempCollection.size(); i++)
    {
        for(const auto & elem : jeu.get_allCartes())
        {
            if(tempCollection[i]->getNom() == elem->getNom())
                exemplaire+=1;

            tempCollection[i]->setExemplaire(exemplaire);
        }
        exemplaire=0;
    }


    system("CLS");


    exemplaire=0;
    x =3;
    y=30;
    gotoligcol(1,70);
    std::cout<<" VOICI LES CARTES QUE TU AS ACHETE :";

   /* for (auto elem : allPlayers[choix]->getCollection())
    {
        elem->affiche(x,y);
        y+=20;

        if(y == 150)
        {
            x += 14;
            y=30;
        }
    }*/

     for(unsigned int i = 0; i< tempCollection.size() ; i++)
     {


      tempCollection[i]->affiche(x,y);
      gotoligcol(x+11,y+2);
      std::cout << "X " << tempCollection[i]->getExemplaire();

       y+=20;

         if(y == 150)
         {
             x += 14;
             y=30;
         }

     }



    //REEECRITURE DU FICHIER :
    std::string pseudo;
    std::ofstream Fichier("joueurs.txt");
    int numero;

    for(auto elem : allPlayers)
    {
        Fichier<<elem->getNom();

        for (auto carteCollection : elem->getCollection())
        {
            numero = 0;

            for(auto carte : jeu.get_allCartes())
            {
                if(carteCollection->getNom() == carte->getNom())
                {
                    Fichier<<" "<<numero;
                }
                numero++;
            }
        }
        Fichier<<" "<<99;
        Fichier<<std::endl;

    }
    Fichier<<"88";


    touche= getch();
    while (touche != ESPACE)
    {
        touche = getch();
    }

}
