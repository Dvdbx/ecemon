#include <iostream>
#include "utilitaire.h"
#include "jeu.h"
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include "Joueur.h"
#include "Cartes.h"

#define X_DECK 15
#define Y_DECK 95


void gameLoop(std::vector<Joueur*> joueurs)
{


    joueurs[0]->videMain();
    joueurs[1]->videMain();
    //ON MELANGE LE DECK :
    joueurs[0]->shuffleDeck();
    joueurs[1]->shuffleDeck();
    //MISE EN JEU DES CARTES:
    joueurs[0]->setCarteMiseEnJeu(joueurs[0]->getDerniereCarte());
    joueurs[0]->popFirstCard(); // ON ENLEVE LA PREMIERE CARTE DU DECK

    joueurs[1]->setCarteMiseEnJeu(joueurs[1]->getDerniereCarte());
    joueurs[1]->popFirstCard();
    ///////////////////////////////////////////////////////////////////
    Cartes *temp = new Cartes;
    //Energie *Ener = new Energie("Tombe");
    Cartes *cartePose = new Cartes();
    //int finPartie = 0;
    int joueurActif = 0; // POUR GERER LES TOURS
    int adversaire = 1;
    int touche = 0;
    int i = 0;
    unsigned int a=0;
    //int b=0;
    //int x=0,z=0;
    int attaquer = 0;
    int info = 0;
    int dommage = 0;
    int aie;
    // int f,c,g,t;
    int attaque=0;
    do
    {

        system("CLS");



        affichageJeu(joueurs[joueurActif]);
        if( joueurs[joueurActif]->checkPose() == true)
        {
            joueurs[joueurActif]->afficheMontre(X_DECK,Y_DECK-20); //AFFICHAGE DU MONSTRE DU JOUEUR ACTIF
        }



        if( joueurs[adversaire]->checkPose() == true)
        {
            affichageMonstreAdverse(joueurs[adversaire]);
        }



        gotoligcol(1,2);
        color(15,0);
        //std::cout<<joueurs[joueurActif]->getNom()<<": "<<joueurs[joueurActif]->getCimetiere().size();
        std::cout<<joueurs[joueurActif]->getNom()<<" c'est ton tour!";
        gotoligcol(2,2);

        std::cout<<"PV :";
        color(10,0);
        std::cout<<joueurs[joueurActif]->getPv();
        color(15,0);
        gotoligcol(39,0);
        std::cout<<" TOUR NUMERO : "<<i+1;




        // PIOCHER UNE CARTE :
        gotoligcol(2,100);
        std::cout<<"PRESSER ENTREE POUR PIOCHER UNE CARTE DANS LE DECK";
        touche = getch();

        while(touche != ENTREE)
        {
            touche = getch();

        }
        joueurs[joueurActif]->getDeck().front()->affiche(X_DECK, Y_DECK + 15);  //LA CARTE S'AFFICHE A COTES DU DECK

        ////SI LE JOUEUR N'A PAS DE MONSTRE POSEE IL DOIT EN METTRE UN SINON IL A PERDU :
        if  (joueurs[joueurActif]->checkPose() != true)
        {
            a = 0;
            while ( ( joueurs[joueurActif]->getDeck().front()->getType() != "Monstre"  ) && (joueurs[joueurActif]->defaite() == false) )
            {
                /////// SOUS PGRM POUR METTRE LA PREMIERE CARTE A LA FIN DU DECK!!


                gotoligcol(2,100);
                std::cout<<"                                                           ";
                gotoligcol(2,100);
                std::cout<<"PAS UN MONSTRE ENTREE POUR REPIOCHER";


                joueurs[joueurActif]->placeFin();
                touche = getch();

                while(touche != ENTREE)
                {
                    touche = getch();

                }
                for (int y = 0; y< 15 ; y++)
                {
                    gotoligcol(X_DECK + y,Y_DECK + 15 );
                    std::cout<<"                                           ";
                }

                joueurs[joueurActif]->getDeck().front()->affiche(X_DECK, Y_DECK + 15);
                touche = getch();

                while(touche != ENTREE)
                {
                    touche = getch();

                }
                a++;

                if(a == joueurs[joueurActif]->getDeck().size())
                {
                    joueurs[joueurActif]->Perdre();
                    gotoligcol(2,100);
                    std::cout<<"                                                           ";
                    gotoligcol(2,100);
                    color(12,0);
                    std::cout<<"TU N'AS PLUS DE MONSTRE DANS TON DECK !! TU AS PERDU";
                    color(15,0);
                }


            }
        }

        if(joueurs[joueurActif]->defaite() != true)
        {



            //SI IL A PIOCHE UN MONSTRE :
            if(joueurs[joueurActif]->getDeck().front()->getType() == "Monstre")
            {


                gotoligcol(2,100);
                std::cout<<"                                                                                    ";//EFFACE LE MSG PRECEDENT
                gotoligcol(2,100);
                if( joueurs[joueurActif]->checkPose() == true )
                {
                    std::cout<<"SOUHAITES TU REMPLACER TON MONSTRE ACTIF?";

                    /*else
                    {
                        std::cout<<"SOUHAITEZ TU JOUER CE MONSTRE?";
                    }*/

                    //gotoligcol(3,100);
                    //std::cout<<"OUI NON";
                    gotoligcol(3,100);
                    color(11,0);
                    std::cout<<"OUI";
                    color(15,0);
                    gotoligcol(3,104);
                    std::cout<<"NON";
                    touche = getch();
                    a=0;

                    while(touche != ENTREE )
                    {
                        touche = getch();
                        switch(touche)
                        {
                        case DROITE:
                            a++;
                            break;
                        case GAUCHE:
                            a--;
                            break;

                        }

                        if(a < 0)
                        {
                            a = 1;
                        }
                        else if( a> 1)
                        {
                            a = 0;
                        }

                        if(a == 0)
                        {
                            gotoligcol(3,100);
                            color(11,0);
                            std::cout<<"OUI";
                            color(15,0);
                            gotoligcol(3,104);
                            std::cout<<"NON";
                        }
                        else
                        {
                            gotoligcol(3,100);
                            color(15,0);
                            std::cout<<"OUI";
                            color(11,0);
                            gotoligcol(3,104);
                            std::cout<<"NON";

                        }
                    }


                    if(a == 1)//FAUT REMETTRE LA CARTE EN BAS DU DECK
                    {
                        joueurs[joueurActif]->placeFin();
                    }
                    else //IL VEUT JOUER LE MONSTRE :
                    {
                        if( joueurs[joueurActif]->checkPose() == true ) //SI IL AVAIT DEJA UN MONSTRE POSE IL VA AU CIMETIERE
                        {
                            for (int y = 0; y< 10 ; y++) //EFFACE L'ANCIEN MONSTRE
                            {
                                gotoligcol(X_DECK + y,Y_DECK - 20 );
                                std::cout<<"                   ";
                            }
                            joueurs[joueurActif]->ajoutCimetiere( joueurs[joueurActif]->getPose() );//Le monstre pose va au cimentiere
                        }
                        joueurs[joueurActif]->monstrePose();
                        cartePose = joueurs[joueurActif]->getDeck().front();
                        joueurs[joueurActif]->setPose( cartePose );
                        joueurs[joueurActif]->popDeck();


                    }

                }//FIN DE SI IL AVAIT DEJA UN MOSNTRE

                if( joueurs[joueurActif]->checkPose() == false )//SI IL AVAIT PAS DE MONSTRE IL EST OBLIGE DE LE POSE
                {
                    joueurs[joueurActif]->monstrePose();
                    cartePose = joueurs[joueurActif]->getDeck().front();
                    joueurs[joueurActif]->setPose( cartePose );
                    joueurs[joueurActif]->popDeck();
                }

                gotoligcol(2,100);
                std::cout<<"                                                                                    ";


            }//FIN IF MONSTRE

            else if(joueurs[joueurActif]->getDeck().front()->getType() == "Energie")
            {
                gotoligcol(2,100);
                std::cout<<"                                                                                    ";
                touche = getch();
                while(touche != ENTREE)
                {
                    touche = getch();
                }
                cartePose = joueurs[joueurActif]->getDeck().front();
                joueurs[joueurActif]->ajoutMain(cartePose); //ON L'AJOUTE  A LA MAIN
                joueurs[joueurActif]->popDeck(); // ON l'ENLEVE DU DECK
                affichageEnergies(joueurs[joueurActif]);

            }
            else if(joueurs[joueurActif]->getDeck().front()->getType() == "Speciale")
            {
                gotoligcol(2,100);
                std::cout<<"                                                                         ";
                gotoligcol(2,100);
                std::cout<<"SOUHAITES-TU JOUER CETTE CARTE SPECIALE?";



                //gotoligcol(3,100);
                //std::cout<<"OUI NON";
                gotoligcol(3,100);
                color(11,0);
                std::cout<<"OUI";
                color(15,0);
                gotoligcol(3,104);
                std::cout<<"NON";
                touche = getch();
                a=0;

                while(touche != ENTREE )
                {
                    touche = getch();
                    switch(touche)
                    {
                    case DROITE:
                        a++;
                        break;
                    case GAUCHE:
                        a--;
                        break;

                    }

                    if(a < 0)
                    {
                        a = 1;
                    }
                    else if( a> 1)
                    {
                        a = 0;
                    }

                    if(a == 0)
                    {
                        gotoligcol(3,100);
                        color(11,0);
                        std::cout<<"OUI";
                        color(15,0);
                        gotoligcol(3,104);
                        std::cout<<"NON";
                    }
                    else
                    {
                        gotoligcol(3,100);
                        color(15,0);
                        std::cout<<"OUI";
                        color(11,0);
                        gotoligcol(3,104);
                        std::cout<<"NON";

                    }
                }


                if(a == 1)//FAUT REMETTRE LA CARTE EN BAS DU DECK
                {
                    joueurs[joueurActif]->placeFin();
                }
                else //IL VEUT JOUER LA SPECIALE :
                {
                    touche = getch();


                    if(joueurs[joueurActif]->getDeck().front()->getNom() == "Poison")
                    {
                        //MARCHE
                        gotoligcol(2,100);
                        std::cout<<"                                                                         ";
                        gotoligcol(3,100);
                        std::cout<<"                                           ";
                        gotoligcol(2,100);
                        std::cout<<"TON ENNEMI A ETE EMPOISONE!!!!";
                        dommage = joueurs[joueurActif]->getDeck().front()->setPoison(joueurs[adversaire]->getPose());
                        dommage+= joueurs[adversaire]->getPv();
                        joueurs[adversaire]->setPv(dommage);
                        effaceMonstreAdverse();
                        affichageMonstreAdverse(joueurs[adversaire]);
                        animationAttaque(30);
                        joueurs[joueurActif]->ajoutCimetiere(joueurs[joueurActif]->getDeck().front());

                    }
                    else if(joueurs[joueurActif]->getDeck().front()->getNom() == "KitSoin")
                    {
                        //BEUG AVEC 100???
                        gotoligcol(2,100);
                        std::cout<<"                                                                         ";
                        gotoligcol(3,100);
                        std::cout<<"                                           ";
                        gotoligcol(2,100);
                        std::cout<<"TON MONSTRE GAGNE DES PV!!";
                        joueurs[joueurActif]->getDeck().front()->addHealth(joueurs[joueurActif]->getPose());
                        AnimationKitSoin();
                        effaceMonstre();
                        joueurs[joueurActif]->afficheMontre(X_DECK,Y_DECK-20);//ON LE RAFFICHE AVEC SA VIE
                        joueurs[joueurActif]->ajoutCimetiere(joueurs[joueurActif]->getDeck().front());

                    }
                    else if(joueurs[joueurActif]->getDeck().front()->getNom() == "Bouclier")
                    {
                        joueurs[joueurActif]->setSpeciale(joueurs[joueurActif]->getDeck().front());

                        gotoligcol(2,100);
                        std::cout<<"                                                                         ";
                        gotoligcol(3,100);
                        std::cout<<"                                           ";
                        gotoligcol(2,100);
                        std::cout<<"TU SERA PROTEGE DES ATTAQUES AU PROCHAIN TOUR!";
                        //joueurs[joueurActif]->specialePose();//UNE SPECIALE EST POSEE
                        joueurs[joueurActif]->setBouclier(1);
                        joueurs[joueurActif]->afficheBouclier();
                        joueurs[joueurActif]->ajoutCimetiere(joueurs[joueurActif]->getDeck().front());

                    }
                    else if(joueurs[joueurActif]->getDeck().front()->getNom() == "Revivre")
                    {

                        gotoligcol(2,100);
                        std::cout<<"                                                                         ";
                        gotoligcol(3,100);
                        std::cout<<"                                           ";
                        gotoligcol(2,100);
                        std::cout<<"UN MONSTRE DU CIMETIERE VA ETRE RESSUCITE ET REMIS DANS TON DECK!";

                        temp = joueurs[joueurActif]->ressuciteMonstre();
                        if(temp->getNom() == "NULL")
                        {
                            gotoligcol(2,100);
                            std::cout<<"                                                                         ";
                            gotoligcol(2,100);
                            std::cout<<"TU N'AS PAS DE MONSTRE DANS TON CIMETIERE!";
                            touche = getch();
                            while(touche!=ENTREE)
                            {
                                touche = getch();
                            }
                        }
                        else
                        {

                            resetPV(temp);

                            temp->affiche(X_DECK,Y_DECK-40-15);
                            //temp->affiche(0,0);

                            touche = getch();
                            while(touche!=ENTREE)
                            {

                            }

                            for(int i = 0 ; i<15 ; i++)
                            {
                                gotoligcol(X_DECK + i,Y_DECK-40-15);
                                std::cout<<"               ";
                            }

                            joueurs[joueurActif]->ajoutDeck(temp);
                        }
                        joueurs[joueurActif]->ajoutCimetiere(joueurs[joueurActif]->getDeck().front());

                    }
                    else if(joueurs[joueurActif]->getDeck().front()->getNom() == "Up")
                    {
                        gotoligcol(2,100);
                        std::cout<<"                                                                         ";
                        gotoligcol(3,100);
                        std::cout<<"                                           ";
                        gotoligcol(2,100);
                        std::cout<<"TU GAGNE UNE ENERGIE GRACE A CETTE CARTE! ";
                        touche = getch();
                        joueurs[joueurActif]->ajoutEnergie();
                        affichageEnergies(joueurs[joueurActif]);
                        joueurs[joueurActif]->ajoutCimetiere(joueurs[joueurActif]->getDeck().front());

                    }
                    else if(joueurs[joueurActif]->getDeck().front()->getNom() == "Malediction")
                    {
                        gotoligcol(2,100);
                        std::cout<<"                                                                         ";
                        gotoligcol(3,100);
                        std::cout<<"                                           ";
                        gotoligcol(2,100);
                        std::cout<<"TON MONSTRE GAGNE 10 POINTS D'ATTAQUE MAIS TU PERDS ";
                        gotoligcol(3,100);
                        std::cout<<"TU PERDS 10 PV !!";

                        joueurs[joueurActif]->setPv( joueurs[joueurActif]->getPv() - 10 );

                        joueurs[joueurActif]->UpAttaque();
                        joueurs[joueurActif]->ajoutCimetiere(joueurs[joueurActif]->getDeck().front());

                        touche = getch();
                        gotoligcol(2,2);
                        std::cout<<"                         ";
                        gotoligcol(2,2);
                        std::cout<<"PV :";
                        color(10,0);
                        std::cout<<joueurs[joueurActif]->getPv();
                        color(12,0);
                        gotoligcol(3,2);
                        std::cout<<"   -10PV!!";
                        Sleep(150);
                        gotoligcol(3,2);
                        std::cout<<"             ";
                        Sleep(150);
                        gotoligcol(3,2);
                        std::cout<<"   -10PV!!";
                        Sleep(150);
                        gotoligcol(3,2);
                        std::cout<<"             ";
                        Sleep(150);
                        gotoligcol(3,2);
                        std::cout<<"   -10PV!!";
                        Sleep(150);
                        gotoligcol(3,2);
                        std::cout<<"             ";

                        color(10,0);
                        gotoligcol(X_DECK + 3, Y_DECK -20 + 3);
                        std::cout<<"+10 !!";
                        Sleep(150);
                        gotoligcol(X_DECK + 3, Y_DECK -20 + 3);
                        std::cout<<"        ";
                        Sleep(150);
                        gotoligcol(X_DECK + 3, Y_DECK -20 + 3);
                        std::cout<<"+10 !!";
                        Sleep(150);
                        gotoligcol(X_DECK + 3, Y_DECK -20 + 3);
                        std::cout<<"       ";
                        Sleep(150);
                        gotoligcol(X_DECK + 3, Y_DECK -20 + 3);
                        std::cout<<"+10 !!";
                        Sleep(150);
                        gotoligcol(X_DECK + 3, Y_DECK -20 + 3);
                        std::cout<<"        ";

                        color(15,0);



                        joueurs[joueurActif]->afficheMontre(X_DECK,Y_DECK-20);




                        color(15,0);

                    }


                    joueurs[joueurActif]->popDeck();


                }
            }
            //touche = getch();



            //EFFACE l'AFFICHAGE
            gotoligcol(2,100);
            std::cout<<"                                                                 ";
            gotoligcol(3,100);
            color(15,0);
            std::cout<<"                                                                   ";



            //AFFICHAGE DES CARTES POSEE:
            if( joueurs[joueurActif]->checkPose() == true) //AFFICHAGE DU MONSTRE
            {
                joueurs[joueurActif]->afficheMontre(X_DECK,Y_DECK-20);
            }


            for (int y = 0; y< 15 ; y++) //EFFACE LA CARTE PIOCHEE
            {
                gotoligcol(X_DECK + y,Y_DECK + 15 );
                std::cout<<"                                  ";
            }



            //CHOIX : AFFICHER DESCRIPTION + ATTAQUER
            if(i!= 0) // sauf au premier tour
            {


                gotoligcol(2,100);
                std::cout<<" PRESSER ESPACE POUR ATTAQUER VOTRE ADVERSAIRE !";

                //touche = getch();
                a = 0;
                attaquer = 0;
                info = 0;

                touche = getch();
                do
                {
                    info = 0;
                    touche = getch();
                    switch(touche)
                    {

                    case  ESPACE :
                        attaquer = 1;
                        break;

                    case DROITE :
                        a++;
                        break;

                    case GAUCHE :
                        a--;
                        break;
                    case ENTREE:
                        info = 1;
                        break;
                    }


                    if (a > 1)
                    {
                        a = 0;
                    }
                    else if(a <0 )
                    {
                        a = 1;
                    }

                    gotoligcol(10,0);

                    switch(a)
                    {
                    case 0:
                        gotoligcol(X_DECK + 21, Y_DECK + 2 ); //Monstre
                        std::cout<<"     ";
                        gotoligcol(X_DECK + 21,Y_DECK-18);
                        std::cout<<"     ";
                        gotoligcol(X_DECK+9,Y_DECK-18);
                        std::cout<<"#inf";
                        break;
                    case 1:
                        gotoligcol(X_DECK + 21,Y_DECK-18); //Speciale
                        std::cout<<"     ";
                        gotoligcol(X_DECK+9,Y_DECK-18);
                        std::cout<<"     ";
                        gotoligcol(X_DECK + 21, Y_DECK + 2 );
                        std::cout<<"#inf";
                        break;
                        /* case 2:
                             gotoligcol(X_DECK + 21, Y_DECK + 2 );
                             std::cout<<"     ";
                             gotoligcol(X_DECK+9,Y_DECK-18);
                             std::cout<<"     ";
                             gotoligcol(X_DECK + 21,Y_DECK-18);
                             std::cout<<"#inf";

                             break;*/

                    }

                    if(info)
                    {
                        switch(a)
                        {
                        case 0:
                            effaceInfo();
                            affichageInfo(joueurs[joueurActif]->getPose());
                            break;
                        case 1:
                            //AFFCIHAGE INFO CARTE SPECIALE

                            effaceInfo();
                            affichageInfoSpeciale(joueurs[joueurActif]->getBouclier());
                            break;
                            /*  case 2:

                                  effaceInfo();*/

                        }

                    }

                }
                while(!attaquer);


                effaceInfo();
                gotoligcol(2,100);
                std::cout<<"                                                                                    ";

                ////////ATTAQUE//////////
                //choix entre attaque normal et attaque speciale







                a=0;
                attaque = 0;
                if(joueurs[adversaire]->getBouclier() !=1)
                {
                    gotoligcol(2,100);

                    std::cout<<"QUELLE ATTAQUE :";

                    do
                    {
                        //gotoligcol(3,100);
                        //std::cout<<"NORMALE SPECIALE";
                        gotoligcol(3,100);
                        color(11,0);
                        std::cout<<"NORMALE";
                        color(15,0);
                        gotoligcol(3,108);
                        std::cout<<"SPECIALE";
                        touche = getch();

                        gotoligcol(4,100);
                        std::cout<<"                                                              ";

                        while(touche != ENTREE )
                        {
                            touche = getch();
                            switch(touche)
                            {
                            case DROITE:
                                a++;
                                break;
                            case GAUCHE:
                                a--;
                                break;

                            }

                            if(a < 0)
                            {
                                a = 1;
                            }
                            else if( a> 1)
                            {
                                a = 0;
                            }

                            if(a == 0)
                            {
                                gotoligcol(3,100);
                                color(11,0);
                                std::cout<<"NORMALE";
                                color(15,0);
                                gotoligcol(3,108);
                                std::cout<<"SPECIALE";
                            }
                            else
                            {
                                gotoligcol(3,100);
                                color(15,0);
                                std::cout<<"NORMALE";
                                color(11,0);
                                gotoligcol(3,108);
                                std::cout<<"SPECIALE";

                            }
                        }
                        gotoligcol(3,100);
                        std::cout<<"                            ";

                        color(15,0);

                        if(a == 1)//ATTAQUE SPECIALE
                        {
                            //condition sur les attaques:

                            attaquer = ConditionAttaque(joueurs[joueurActif]);

                            if(attaquer == 1)//Si il peut utiliser l'attaque
                            {

                                dommage = attaquerSpeciale( joueurs[joueurActif]->getPose(), joueurs[adversaire]->getPose() );
                                aie = joueurs[joueurActif]->getPose()->getSpeciale().getDegats();
                                dommage+= joueurs[joueurActif]->getPv();
                                joueurs[adversaire]->setPv(dommage);
                                // ENLEVER SES CARTES ENERGIES UTILISEES
                                retirerEnergie(joueurs[joueurActif]);
                                //AFFCIHEE LES ENERGIES CHANGEES
                                affichageEnergies(joueurs[joueurActif]);
                                animationAttaque(aie);
                                effaceMonstreAdverse();
                                affichageMonstreAdverse(joueurs[adversaire]);
                                attaque = 1;




                            }
                            else
                            {
                                gotoligcol(4,100);
                                color(12,0);
                                std::cout<<"TU N'A PAS ASSEZ D'ENERGIE POUR UTILISER CETTE ATTAQUE!!";
                                color(15,0);
                                attaque = 0;
                            }

                        }
                        else //ATTAQUE NORMALE
                        {

                            dommage = attaquerNormale( joueurs[joueurActif]->getPose(), joueurs[adversaire]->getPose() );
                            aie = joueurs[joueurActif]->getPose()->getNormale().getDegats();
                            dommage+= joueurs[joueurActif]->getPv();
                            joueurs[adversaire]->setPv(dommage);
                            animationAttaque(aie);
                            effaceMonstreAdverse();
                            affichageMonstreAdverse(joueurs[adversaire]);
                            attaque = 1;
                        }



                    }
                    while(attaque!=1);
                } //TANT QU'IL A PAS ATTAQUER

                else if (joueurs[adversaire]->getBouclier() == 1)
                {
                    joueurs[adversaire]->setBouclier(0);
                    gotoligcol(2,100);
                    std::cout<<"                                                                                    ";

                    gotoligcol(2,100);
                    std::cout<<"TON ENNEMI EST PROTEGE TU NE PEUX PAS L'ATTAQUER! " ;
                    touche = getch();
                }




            }//Fin attaque et info

            if(i!=0)//METTRE LE MONSTRE MORT AU CIMETIERE
            {
                if(joueurs[adversaire]->getPose()->getPv() <= 0 )//SI PLUS DE PV IL A PLUS DE MONSTRE
                {
                    joueurs[adversaire]->ajoutCimetiere(joueurs[adversaire]->getPose()); //MONSTRE MORT AU CIMETIERE
                    joueurs[adversaire]->monstreMort();
                    joueurs[adversaire]->setPose(NULL);
                }
            }



            if (joueurs[adversaire]->getPv() <= 0)
            {
                joueurs[adversaire]->Perdre(); //SI LE JOUEUR A PLUS DE PV IL A PERDU
            }

            joueurActif++;
            adversaire --;

            if(joueurActif >1)
            {
                joueurActif = 0;
                adversaire = 1;
            }
            i++;

            gotoligcol(2,100);
            std::cout<<" PRESSER ENTREE POUR PASSER AU JOUEUR SUIVANT !";

        }// FIN

        touche = getch();
        /*
        if(touche == 'a')
        {
            finPartie = 1;
        }
        */
        while(touche != 13)
        {
            touche = getch();
        }




    }
    while( (joueurs[joueurActif]->defaite() != true) && (joueurs[adversaire]->defaite()!=true) );

    system("CLS");
    gotoligcol(4,85);
    color(11,0);
    std::cout<<"FIN DE PARTIE";
    color(15,0);


    if(joueurs[joueurActif]->defaite() == true)
    {

        gotoligcol(12,80);
        std::cout<<"VICTOIRE DE "<<joueurs[adversaire]->getNom() <<"!!!";
        gotoligcol(14,80);
        std::cout<<"TU REMPORTE CETTE CARTE DE  "<<joueurs[joueurActif]->getNom()<<" :";
        joueurs[joueurActif]->getCarteMiseEnJeu()->affiche(16,80);
        joueurs[adversaire]->ajoutCollection(  joueurs[joueurActif]->getCarteMiseEnJeu() );

    }
    else
    {
        gotoligcol(12,80);
        std::cout<<"VICTOIRE DE "<<joueurs[joueurActif]->getNom() <<"!!!";
        gotoligcol(14,80);
        std::cout<<"TU REMPORTE CETTE CARTE DE  "<<joueurs[adversaire]->getNom()<<" :";
        joueurs[adversaire]->getCarteMiseEnJeu()->affiche(16,80);
        joueurs[joueurActif]->ajoutCollection(  joueurs[adversaire]->getCarteMiseEnJeu() );
    }


    gotoligcol(38,78);
    std::cout<<"PRESSER ENTREE POUR TERMINER CETTE PARTIE";

    touche = getch();
    while(touche!=ENTREE)
    {
        touche = getch();
    }

}

void parties(std::vector<Joueur*> joueurs)
{
    //SOUS PGRM POUR LANCER LES PARTIES SELON LE NB DE JOUEURS
    // ENCHAINEMENT DES PARTIES
    int touche = 0;
    std::vector<Joueur*> players;
    std::vector<Cartes*> temp1;
    std::vector<Cartes*> temp2; //POUR GARDER LEUR DECK


    if(joueurs.size() == 2)
    {
        system("CLS");
        gotoligcol(1,0);
        color(15,0);
        std::cout<<" MATCH 1 : "<<joueurs[0]->getNom()<<" VS "<<joueurs[1]->getNom();

        gotoligcol(2,0);


        touche = getch();
        joueurs[0]->choisirDeck();
        joueurs[1]->choisirDeck();
        gameLoop(joueurs);


    }
    else if(joueurs.size()== 3)
    {
        // 1 VS 2 PUIS 2 VS 3 PUIS 1 VS 3
        system("CLS");
        gotoligcol(1,0);
        color(15,0);

        //MATCH 1
        std::cout<<" MATCH 1 : "<<joueurs[0]->getNom()<<" VS "<<joueurs[1]->getNom()<<std::endl;
        std::cout<<" MATCH 2 : "<<joueurs[1]->getNom()<<" VS "<<joueurs[2]->getNom();

        players.push_back(joueurs[0]);
        players.push_back(joueurs[1]);
        touche = getch();
        players[0]->choisirDeck();
        players[1]->choisirDeck();

        gameLoop(players);

        //MATCH 2
        players.pop_back();
        players.pop_back();
        system("CLS");
        gotoligcol(1,0);
        std::cout<<" MATCH 2 : "<<joueurs[1]->getNom()<<" VS "<<joueurs[2]->getNom();
        gotoligcol(2,0);
        std::cout<<" PRESSER ESPACE POUR COMMENCER LA PARTIE:";
        touche = getch();
        while(touche!= ESPACE)
        {
            touche = getch();
        }

        players.push_back(joueurs[1]);
        players.push_back(joueurs[2]);
        players[0]->videDeck();
        players[1]->videDeck();
        players[0]->choisirDeck();
        players[1]->choisirDeck();

        gameLoop(players);

        //MATCH 3
        players.pop_back();
        players.pop_back();
        system("CLS");
        gotoligcol(1,0);
        std::cout<<" MATCH 3 : "<<joueurs[0]->getNom()<<" VS "<<joueurs[2]->getNom();
        gotoligcol(2,0);
        std::cout<<" PRESSER ESPACE POUR COMMENCER LA PARTIE:";
        touche = getch();
        while(touche!= ESPACE)
        {
            touche = getch();
        }

        players.push_back(joueurs[0]);
        players.push_back(joueurs[2]);
        players[0]->videDeck();
        players[1]->videDeck();
        players[0]->choisirDeck();
        players[1]->choisirDeck();
        touche = getch();
        gameLoop(players);



    }
    else if(joueurs.size()== 4)
    {
        // 1 VS 2 PUIS 2 VS 3 PUIS 1 VS 3 PUIS 1 VS 4
        system("CLS");
        gotoligcol(1,0);
        color(15,0);

        //MATCH 1
        std::cout<<" MATCH 1 : "<<joueurs[0]->getNom()<<" VS "<<joueurs[1]->getNom()<<std::endl;
        std::cout<<" MATCH 2 : "<<joueurs[1]->getNom()<<" VS "<<joueurs[2]->getNom()<<std::endl;
        std::cout<<" MATCH 3 : "<<joueurs[0]->getNom()<<" VS "<<joueurs[2]->getNom()<<std::endl;
        std::cout<<" MATCH 4 : "<<joueurs[0]->getNom()<<" VS "<<joueurs[3]->getNom()<<std::endl;


        players.push_back(joueurs[0]);
        players.push_back(joueurs[1]);
        touche = getch();
        players[0]->choisirDeck();
        players[1]->choisirDeck();

        gameLoop(players);

        //MATCH 2
        players.pop_back();
        players.pop_back();
        system("CLS");
        gotoligcol(1,0);
        std::cout<<" MATCH 2 : "<<joueurs[1]->getNom()<<" VS "<<joueurs[2]->getNom();
        gotoligcol(2,0);
        std::cout<<" PRESSER ESPACE POUR COMMENCER LA PARTIE:";
        touche = getch();
        while(touche!= ESPACE)
        {
            touche = getch();
        }
        players.push_back(joueurs[1]);
        players.push_back(joueurs[2]);
        players[0]->videDeck();
        players[1]->videDeck();
        players[0]->choisirDeck();
        players[1]->choisirDeck();
        touche = getch();
        gameLoop(players);

        //MATCH 3
        players.pop_back();
        players.pop_back();
        system("CLS");
        gotoligcol(1,0);
        std::cout<<" MATCH 3 : "<<joueurs[0]->getNom()<<" VS "<<joueurs[2]->getNom();
        gotoligcol(2,0);
        std::cout<<" PRESSER ESPACE POUR COMMENCER LA PARTIE:";
        touche = getch();
        while(touche!= ESPACE)
        {
            touche = getch();
        }
        players.push_back(joueurs[0]);
        players.push_back(joueurs[2]);
        players[0]->videDeck();
        players[1]->videDeck();
        players[0]->choisirDeck();
        players[1]->choisirDeck();
        touche = getch();
        gameLoop(players);

        //MATCH 4
        players.pop_back();
        players.pop_back();
        system("CLS");
        gotoligcol(1,0);
        std::cout<<" MATCH 4 : "<<joueurs[0]->getNom()<<" VS "<<joueurs[3]->getNom();
        gotoligcol(2,0);
        std::cout<<" PRESSER ESPACE POUR COMMENCER LA PARTIE:";
        touche = getch();
        while(touche!= ESPACE)
        {
            touche = getch();
        }

        players.push_back(joueurs[0]);
        players.push_back(joueurs[3]);
        players[0]->videDeck();
        players[1]->videDeck();
        players[0]->choisirDeck();
        players[1]->choisirDeck();
        touche = getch();

        gameLoop(players);

    }


}

std::vector<Joueur*> chargerJoueurs()
{
    system("CLS");


    std::ifstream Fichier("joueurs.txt");
    std::string pseudo;
    std::vector<Joueur*> allPlayers;
    int carte;
    Jeu j;
    j.chargerCarte();
    int k= 0;
    //int x=1,y=0;
    //int n =0 ;
    std::string ligne;
    std::vector <Cartes*> temp;
    gotoligcol(1,0);
    //std::cout<<"DEBUT";
    int z=0;
    int fin = 0;

    while( !fin)//getline(Fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
    {


        Fichier>>pseudo;
        z++;


        Joueur *nv = new Joueur();
        nv->setNom(pseudo);


        carte = 0;



        while(carte != 99 )
        {
            k = 0;
            Fichier>>carte;


            if(pseudo == "88")
            {
                fin = 1;
                carte = 99;
            }

            for(auto elem : j.get_allCartes())
            {


                if(carte == k )
                {


                    nv->remplirCollection(elem);

                }

                k++;

            }

        }

        //std::cout<<"joueur ajouter"<<std::endl;
        allPlayers.push_back(nv);
        std::cout<<std::endl;


    }


    // std::cout<<allPlayers[0]->getNom()<<std::endl;
    //  temp = allPlayers[0]->getCollection();

    /*for(auto elem2 : temp)
    {
        elem2->affiche(x,y);
        y+=20;

    if(y == 100)
    {
        x += 14;
        y=0;
    }
    }*/

    allPlayers.pop_back();//SUPPRIME LE DERNIER BEUG
    //std::cout<<" FIN ";
    return allPlayers;
}

std::vector<Joueur*> choixJoueur() // VA RENVOYER LE TABLEAU CONTENANT LES JOUEURS QUI VONT FAIRE LA PARTIE
{
    //LIRE LE FICHIER JOUEUR AFFICHER LES NOM ET SI ON LE CHOISIS RECUPERER SES INFOS
    std::vector <Joueur*> allPlayers = chargerJoueurs();
    std::vector<Joueur*> joueurs;// LES JOUEURS CHOSIS
    system("CLS");
    color(15,0);
    gotoligcol(1,1);
    int nb=0;
    int touche=0;
    int ok = 0;

    std::cout<<"CHOISIR LE NOMBRE DE JOUEURS : (2 MIN ET 4 MAX) ";

    // touche = getch();

    do
    {
        // touche = getch();
        gotoligcol(1,52);
        std::cout<<"                  ";
        gotoligcol(1,52);
        std::cin>>nb;

        if ( (nb == 2) || (nb == 3) || (nb == 4) )
        {
            ok=1;
        }

        /*gotoligcol(1,45);
        std::cout<<" ";
        std::cout<<nb;


        switch(touche)
        {
        case 80:
            nb--;
            break;
        case 72:
            nb ++;
            break;
        }

        if(nb<0)
        {
            nb=4;
        }
        if(nb>4)
        {
            nb=0;
        }

        if ( (touche == 13 ) && ( nb>2 ) )
        {

            ok=1;
        }*/

    }
    while( ok !=1 );


    system("CLS");


    gotoligcol(2,70);
    color(15,0);
    std::cout<<"QUI VA JOUER?";


    gotoligcol(6,30);
    color(11,0);
    std::cout<<"LISTE DES JOUEURS:";
    unsigned int i =0;
    int k=0;
    unsigned int y =0;

    color(15,0);



    for(auto elem : allPlayers)
    {
        gotoligcol(9+i,30);
        std::cout<<" "<<elem->getNom();
        i+=2;

    }
    gotoligcol(9,30);
    color(12,0);
    std::cout << "-" << allPlayers[0]->getNom();
    color(15,0);

    gotoligcol(6,70);
    std::cout<<"LES JOUEURS CHOISIS SONT: ";

    unsigned int choix=0;
    int m =0;

    while(k != nb)
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
        //std::cout<<choix;

        //AFFICHAGE DU CURSEUR:

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
                    k++;
                }

                y++;

            }
        }

        m = 0;


        if(joueurs.size()!=0)
        {
            for(auto elem : joueurs)
            {
                gotoligcol(9+ m,70);
                std::cout<<elem->getNom();
                m++;
            }

        }


    }


    system("CLS");


    /*touche = getch();

    while(touche!= 13)
    {
        touche = getch();
    }*/


    parties(joueurs);

//DEMANDER DE CHOSIR LES JOUEURS QUI VONT JOUER
//CHAQUE JOUEUR CHOISIS SON DECQUE
    return joueurs;

}

void nouveauJoueur()
{
    //ENTRER NOM JOUEUR
    //AFFICHER TOUTE LES CARTES
    //CHOIX DES CARTES POUR LA COLLECTION
    system("CLS");
    std::string pseudo;
    std::cout<<"NOUVEAU JOUEUR"<<std::endl;
    std::vector<Joueur*> allPlayers = chargerJoueurs();
    std::ofstream Fichier("joueurs.txt");

    Joueur *nv = new Joueur();


    //std::ofstream Fichier("joueurs.txt", std::ios::app);
    const SHORT Mask = 32768;
    Jeu j;
    char c = 0xBA;
    //int i = 0;
    j.chargerCarte();

    std::vector<Cartes*> decque;

    if (Fichier)
    {
        gotoligcol(2,2);
        std::cout<<"SAISIR LE PSEUDO DU NOUVEAU JOUEUR :";
        gotoligcol(3,2);
        std::cin>>pseudo;

        nv->setNom(pseudo);
//std::cout<<" PSEUDO SET";
        //Fichier<<std::endl;
        //Fichier<<pseudo<<" ";

        system("CLS");
        int carte=0;
        int nb=0;

        int k=0;


        int x = 0;
        //int num;
        int y = 0;




        gotoligcol(5,100);
        std::cout<<pseudo<<", CHOISIS LES CARTES QUE TU VEUX AJOUTER A TA COLLECTION";
        gotoligcol(7,100);
        std::cout<<"APPUIE SUR ENTREE POUR AJOUTER CETTE CARTE A TA COLLECTION :";
        x=0;
        y=0;

        for(int l =0; l<50; l++)
        {
            gotoligcol(l,98);
            std::cout<<c;
        }


//AFFICHAGE DE TOUTE LES CARTES:

        for(auto elem : j.get_allCartes())
        {

            elem->affiche(x,y);

            y+=20;

            if(y == 100)
            {
                x += 14;
                y=0;
            }


        }

//SELECTION DES CARTES

        j.get_allCartes()[0]->affiche(9,120);

        while(nb<20)
        {


            if (GetKeyState(VK_LEFT) & Mask)
            {
                k=0;
                carte --;

                for(auto elem : j.get_allCartes())
                {
                    if(k == carte)
                    {
                        gotoligcol(8,120);
                        std::cout<<"              ";
                        gotoligcol(9,120);
                        std::cout<<"              ";
                        gotoligcol(10,120);
                        std::cout<<"              ";
                        gotoligcol(11,120);
                        std::cout<<"              ";
                        gotoligcol(12,120);
                        std::cout<<"              ";
                        gotoligcol(13,120);
                        std::cout<<"              ";
                        gotoligcol(14,120);
                        std::cout<<"              ";
                        gotoligcol(15,120);
                        std::cout<<"              ";
                        gotoligcol(16,120);
                        std::cout<<"              ";
                        gotoligcol(17,120);
                        std::cout<<"              ";
                        gotoligcol(18,120);
                        std::cout<<"              ";
                        gotoligcol(19,120);
                        std::cout<<"              ";

                        elem->affiche(9,120);
                    }
                    k++;
                }
            }
            if (GetKeyState(VK_RIGHT) & Mask)
            {
                k=0;
                carte ++;

                for(auto elem : j.get_allCartes())
                {
                    if(k == carte)
                    {
                        gotoligcol(8,120);
                        std::cout<<"              ";
                        gotoligcol(9,120);
                        std::cout<<"              ";
                        gotoligcol(10,120);
                        std::cout<<"              ";
                        gotoligcol(11,120);
                        std::cout<<"              ";
                        gotoligcol(12,120);
                        std::cout<<"              ";
                        gotoligcol(13,120);
                        std::cout<<"              ";
                        gotoligcol(14,120);
                        std::cout<<"              ";
                        gotoligcol(15,120);
                        std::cout<<"              ";
                        gotoligcol(16,120);
                        std::cout<<"              ";
                        gotoligcol(17,120);
                        std::cout<<"              ";
                        gotoligcol(18,120);
                        std::cout<<"              ";
                        gotoligcol(19,120);
                        std::cout<<"              ";

                        elem->affiche(9,120);
                    }
                    k++;
                }
            }

            gotoligcol(20,100);
            std::cout<<"Encore "<<20-nb<<" a choisir!!";
            if(carte<0)
            {
                carte = 18;
            }
            if(carte>18)
            {
                carte = 0;
            }


            Sleep(100);


            k=0;



            if(GetKeyState(VK_RETURN) & Mask)
            {


                for(auto elem : j.get_allCartes())
                {


                    if(k == carte)
                    {
                        nv->ajoutCollection(elem);
                        decque.push_back(elem);
                        // Fichier<<carte<<" ";
                        nb++;
                    }

                    k++;

                }
            }


        }
        Sleep(10);

        // Fichier<<"99";
        //Fichier<<std::endl;



    }
    else
    {
        std::cout<<"ERREUR";
    }

    system("CLS");

    gotoligcol(1,1);
    int touche = 0;
    std::cout<<nv->getNom()<<" ";
    std::cout<<" VOICI TA COLLECTION :";
    int x =5,y=0;


    for(auto elem : nv->getCollection())
    {

        elem->affiche(x,y);

        y+=20;

        if(y == 100)
        {
            x += 14;
            y=0;
        }


    }

    allPlayers.push_back(nv);

    //ECRITURE DANS LE FICHIER :
    // std::ofstream Fichier("joueurs.txt");
    int numero;

    for(auto elem : allPlayers)
    {
        Fichier<<elem->getNom();

        for (auto carteCollection : elem->getCollection())
        {
            numero = 0;

            for(auto carte : j.get_allCartes())
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


void affichageJeu(Joueur *joueur)
{

    system("CLS");
    char a;
    //int touche=0;
    int c = 0;
    int f = 0;
    int g = 0;
    int t =0;


    //COMPTE DU NBR DE CHAQUE ENERGIES :

    for( auto elem : joueur->getMain())
    {
        if(elem->getNom() == "Chateau")
        {
            c++;
        }
        else if(elem->getNom() == "Foret")
        {
            f++;
        }
        else if(elem->getNom() == "Grotte")
        {
            g++;
        }
        else if(elem->getNom() == "Tombe")
        {
            t++;
        }
    }


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


    contour_carte2(X_DECK,Y_DECK-40,15);
    gotoligcol(X_DECK + 1,Y_DECK-37);
    std::cout<<"CIMETIERE";

    contour_carte2(X_DECK + 12,Y_DECK-40,15);
    gotoligcol(X_DECK + 13, Y_DECK - 37);
    std::cout<<" MISE EN ";
    gotoligcol(X_DECK + 14, Y_DECK - 36);
    std::cout<<"   JEU ";

    contour_carte2(X_DECK,Y_DECK,15);
    gotoligcol(X_DECK + 1,Y_DECK + 5);
    std::cout<<"DECK";


    contour_carte2(X_DECK + 12,Y_DECK-20,15);
    gotoligcol(X_DECK + 13, Y_DECK - 18);
    std::cout<<"  ENERGIES ";
    gotoligcol(X_DECK + 15, Y_DECK - 18);
    color(12,0);
    std::cout<<" Chateau ";
    color(15,0);
    std::cout<<c;
    gotoligcol(X_DECK + 16, Y_DECK - 18);
    color(10,0);
    std::cout<<" Foret ";
    color(15,0);
    std::cout<<f;
    gotoligcol(X_DECK + 17, Y_DECK - 18);
    color(3,0);
    std::cout<<" Grotte ";
    color(15,0);
    std::cout<<g;
    gotoligcol(X_DECK + 18, Y_DECK - 18);
    color(8,0);
    std::cout<<" Tombe ";
    color(15,0);
    std::cout<<t;

    contour_carte2(X_DECK + 12,Y_DECK,15);
    gotoligcol(X_DECK + 13, Y_DECK + 3 );
    std::cout<<" SPECIALE ";
    gotoligcol(X_DECK + 15, Y_DECK - 18);

}

void affichageEnergies(Joueur *joueur)
{


    //int touche=0;
    int c = 0;
    int f = 0;
    int g = 0;
    int t =0;


    //COMPTE DU NBR DE CHAQUE ENERGIES :

    for( auto elem : joueur->getMain())
    {
        if(elem->getNom() == "Chateau")
        {
            c++;
        }
        else if(elem->getNom() == "Foret")
        {
            f++;
        }
        else if(elem->getNom() == "Grotte")
        {
            g++;
        }
        else if(elem->getNom() == "Tombe")
        {
            t++;
        }
    }


    contour_carte2(X_DECK + 12,Y_DECK-20,15);
    gotoligcol(X_DECK + 13, Y_DECK - 18);
    std::cout<<"  ENERGIES ";
    gotoligcol(X_DECK + 15, Y_DECK - 18);
    color(12,0);
    std::cout<<" Chateau ";
    color(15,0);
    std::cout<<c;
    gotoligcol(X_DECK + 16, Y_DECK - 18);
    color(10,0);
    std::cout<<" Foret ";
    color(15,0);
    std::cout<<f;
    gotoligcol(X_DECK + 17, Y_DECK - 18);
    color(3,0);
    std::cout<<" Grotte ";
    color(15,0);
    std::cout<<g;
    gotoligcol(X_DECK + 18, Y_DECK - 18);
    color(8,0);
    std::cout<<" Tombe ";
    color(15,0);
    std::cout<<t;
}

void effaceMonstreAdverse()
{
    for (int i=0; i<4; i++)
    {
        gotoligcol(X_DECK-10+i, Y_DECK-22);
        std::cout<<"                             ";

    }
}

void affichageMonstreAdverse(Joueur *joueur)
{
    char c;
    int x = X_DECK-10, y = Y_DECK-22;

    color(12,0);
    gotoligcol(x, y+1);
    c=0xC9;
    std::cout << c;
    gotoligcol(x, y+20);
    c=0xBB;
    std::cout << c;
    gotoligcol(x+8,  y+1);
    c=0xC8;
    std::cout << c;
    gotoligcol(x+8, y+20);
    c=0xBC;
    std::cout << c;
    c=0xCD;

    for (int i=0; i<18; i++)
    {
        gotoligcol(x,y+i+2);
        std::cout <<c;
        gotoligcol(x+8,y+i+2);
        std::cout <<c;

    }


    c=0xBA;
    for (int i=0; i<7; i++)
    {
        gotoligcol(x+1+i, y+1);
        std::cout <<c;
        gotoligcol(x+1+i, y+20);
        std::cout <<c;
    }
    gotoligcol(40,0);

    color(15,0);
    gotoligcol(x+1,y + 8);
    std::cout<<joueur->getNom();
    gotoligcol(x+2,y + 6);
    color(10,0);
    std::cout<<" "<<joueur->getPv();
    color(15,0);
    std::cout<<" PV ";
    gotoligcol(x+3,y + 5);
    if(joueur->checkPose() == true)
    {
        std::cout<<joueur->getPose()->getNom()<<" "<<joueur->getPvMonstre()<<" PV";
    }


    color(15,0);
}

void animationAttaque(int degat)
{
    int x = X_DECK-10, y = Y_DECK-22;

    gotoligcol(x+5,y + 5);
    color(12,0);
    std::cout<<" AIE -"<<degat<<" PV!!";
    Sleep(150);
    gotoligcol(x+5,y + 5);
    std::cout<<"            ";
    Sleep(150);
    gotoligcol(x+5,y + 5);
    color(12,0);
    std::cout<<" AIE -"<<degat<<" PV!!";
    Sleep(150);
    gotoligcol(x+5,y + 5);
    std::cout<<"            ";
    Sleep(150);
    gotoligcol(x+5,y + 5);
    color(12,0);
    std::cout<<" AIE -"<<degat<<" PV!!";
    Sleep(150);
    gotoligcol(x+5,y + 5);
    std::cout<<"            ";
    Sleep(150);
    gotoligcol(x+5,y + 5);
    color(12,0);
    std::cout<<" AIE -"<<degat<<" PV!!";
    Sleep(150);
    gotoligcol(x+5,y + 5);
    std::cout<<"            ";
    Sleep(150);
    gotoligcol(x+5,y + 5);
    color(12,0);
    std::cout<<" AIE -"<<degat<<" PV!!";

    color(15,0);

}
void effaceInfo()
{

    for(int i = 0 ; i<14; i++)
    {
        gotoligcol(X_DECK+3 +i,Y_DECK+20);
        std::cout<<"                                               ";
    }
}


void affichageInfo(Cartes *info)
{

    //gotoligcol(X_DECK,Y_DECK+15);


    char c;
    int x = X_DECK + 3, y = Y_DECK+20;

    color(14,0);
    gotoligcol(x, y+1);
    c=0xC9;
    std::cout << c;
    gotoligcol(x, y+30);
    c=0xBB;
    std::cout << c;
    gotoligcol(x+12,  y+1);
    c=0xC8;
    std::cout << c;
    gotoligcol(x+12, y+30);
    c=0xBC;
    std::cout << c;
    c=0xCD;

    for (int i=0; i<28; i++)
    {
        gotoligcol(x,y+i+2);
        std::cout <<c;
        gotoligcol(x+12,y+i+2);
        std::cout <<c;

    }


    c=0xBA;
    for (int i=0; i<11; i++)
    {
        gotoligcol(x+1+i, y+1);
        std::cout <<c;
        gotoligcol(x+1+i, y+30);
        std::cout <<c;
    }
    gotoligcol(40,0);

    color(15,0);
    if(info->getType() == "Monstre")
    {


        color(15,0);
        gotoligcol(x+1,y + 9);
        std::cout<<" "<<info->getNom();
        //gotoligcol(x+3,y + 3);
        // std::cout<<"Domaine : "<<info->getDomaine();
        gotoligcol(x+3,y + 3);
        std::cout<<"-Attaque normale  ";
        gotoligcol(x+4,y + 3);
        std::cout<<info->getNomAttaqueNormale()<<" "<<info->getNormale().getDegats()<<"Pts (sans energie)";;
        gotoligcol(x+6,y + 3);
        std::cout<<"-Attaque speciale  ";
        gotoligcol(x+7,y + 3);
        std::cout<<info->getNomAttaqueSpeciale()<<" "<<info->getSpeciale().getDegats()<<"Pts";

        if(info->getNom() == "Loup-Garou")
        {
            gotoligcol(x+8,y + 3);
            std::cout<<"Necessite 2 energies Foret";

        }
        else if (info->getNom() == "Zombie")
        {
            gotoligcol(x+8,y + 3);
            std::cout<<"Necessite 1 energie Tombe";
            gotoligcol(x+9,y + 3);
            std::cout<<"et 1 energie Chateau";
        }
        else if (info->getNom() == "Vampire")
        {
            gotoligcol(x+8,y + 3);
            std::cout<<"Necessite 1 energie Chateau";
            gotoligcol(x+9,y + 3);
            std::cout<<"et 1 energie Grotte";
        }
        else if (info->getNom() == "Fantome")
        {
            gotoligcol(x+8,y + 3);
            std::cout<<"Necessite 2 energies Tombe";
        }
        else if (info->getNom() == "Sorciere")
        {
            gotoligcol(x+8,y + 3);
            std::cout<<"Necessite 1 energie Chateau";
        }
        else if (info->getNom() == "Lutin")
        {
            gotoligcol(x+8,y + 3);
            std::cout<<"Necessite 2 energies Grotte";
        }
        else if (info->getNom() == "Elfe")
        {
            gotoligcol(x+8,y + 3);
            std::cout<<"Necessite 1 energie Foret";
        }
        else if (info->getNom() == "Araignee")
        {
            gotoligcol(x+8,y + 3);
            std::cout<<"Necessite 1 energie Grotte";
            gotoligcol(x+9,y + 3);
            std::cout<<"et 1 energie Chateau";
        }

        gotoligcol(x+2,y + 6);
        color(10,0);

        color(15,0);
        std::cout<<"  ";
        gotoligcol(x+4,y + 8);

    }



    else if(info->getType() == "Speciale")
    {
        color(15,0);
        gotoligcol(x+1,y + 8);
        std::cout<<" Cartes Speciales";
    }



}

void affichageInfoSpeciale (int bouclier)
{

    char c;
    int x = X_DECK + 3, y = Y_DECK+20;

    color(14,0);
    gotoligcol(x, y+1);
    c=0xC9;
    std::cout << c;
    gotoligcol(x, y+30);
    c=0xBB;
    std::cout << c;
    gotoligcol(x+12,  y+1);
    c=0xC8;
    std::cout << c;
    gotoligcol(x+12, y+30);
    c=0xBC;
    std::cout << c;
    c=0xCD;

    for (int i=0; i<28; i++)
    {
        gotoligcol(x,y+i+2);
        std::cout <<c;
        gotoligcol(x+12,y+i+2);
        std::cout <<c;

    }


    c=0xBA;
    for (int i=0; i<11; i++)
    {
        gotoligcol(x+1+i, y+1);
        std::cout <<c;
        gotoligcol(x+1+i, y+30);
        std::cout <<c;
    }
    gotoligcol(40,0);


    if(bouclier == 1)//IL A UN BOUCLIER :
    {
        color(15,0);
        gotoligcol(x+1,y + 9);
        std::cout<<"BOUCLIER ";
        color(15,0);
        gotoligcol(x+3,y + 3);
        std::cout<<"CARTE SPECIALE ACTIVE!";
        gotoligcol(x+4,y + 3);
        std::cout<<"LE BOUCLIER TE PROTEGRA DES ";;
        gotoligcol(x+6,y + 3);
        std::cout<<"ATTAQUE DU MONSTRE ADVERSE";
        gotoligcol(x+7,y + 3);
        std::cout<<"AU PROCHAIN TOUR! ";
        gotoligcol(x+8,y + 3);
        std::cout<<"MAIS TU NE SERAS PAS PROTEGE";
        gotoligcol(x+9,y + 3);
        std::cout<<" DES ATTAQUES DES ";
        gotoligcol(x+10,y + 3);
        std::cout<<"CARTES SPECIALES!";
    }
    else
    {
        color(15,0);
        gotoligcol(x+1,y + 9);
        std::cout<<"TU N'A PAS DE CARTE ";
        gotoligcol(x+2,y + 9);
        std::cout<<"SPECIALE ACTIVE";
    }


}

/*
void CompteEnergie(int *f,int *g,int *t, int *c, Joueur *j )
{
    *c = 0;
    *f = 0;
    *g = 0;
    *t =0;


    //COMPTE DU NBR DE CHAQUE ENERGIES :

    for( auto elem : j->getMain())
    {
        if(elem->getNom() == "Chateau")
        {
            *c++;
        }
        else if(elem->getNom() == "Foret")
        {
            *f++;
        }
        else if(elem->getNom() == "Grotte")
        {
            *g++;
        }
        else if(elem->getNom() == "Tombe")
        {
            *t++;
        }
    }
}
*/

void CompteEnergie(int &f,int &g,int &t, int &c, Joueur *j )
{
    //*c = 0;
    //*f = 0;
    //*g = 0;
    //*t =0;


    //COMPTE DU NBR DE CHAQUE ENERGIES :

    for( auto elem : j->getMain())
    {
        if(elem->getNom() == "Chateau")
        {
            c++;
        }
        else if(elem->getNom() == "Foret")
        {
            f++;
        }
        else if(elem->getNom() == "Grotte")
        {
            g++;
        }
        else if(elem->getNom() == "Tombe")
        {
            t++;
        }
    }
}


int ConditionAttaque(Joueur *j)
{
    int retour = 0;
    int c = 0;
    int f = 0;
    int g = 0;
    int t =0;


    //COMPTE DU NBR DE CHAQUE ENERGIES :

    for( auto elem : j->getMain())
    {
        if(elem->getNom() == "Chateau")
        {
            c++;
        }
        else if(elem->getNom() == "Foret")
        {
            f++;
        }
        else if(elem->getNom() == "Grotte")
        {
            g++;
        }
        else if(elem->getNom() == "Tombe")
        {
            t++;
        }
    }

//CONDITION RETOURNE 1 SI IL PEUT ATTAQUER 0 SINON
    if(j->getPose()->getNom() == "Loup-Garou")
    {
        if(f >= 2)
        {
            retour = 1;
        }
    }
    else if(j->getPose()->getNom() == "Zombie")
    {
        if ( (t >= 1) && (c>=1) )
        {
            retour = 1;
        }
    }
    else if(j->getPose()->getNom() == "Vampire")
    {
        if ( (c >= 1) && (g >= 1) )
        {
            retour =1;
        }
    }
    else if(j->getPose()->getNom() == "Fantome")
    {
        if  (t >= 2)
        {
            retour = 1;
        }
    }
    else if(j->getPose()->getNom() == "Sorciere")
    {
        if  (c >= 1)
        {
            retour = 1;
        }
    }
    else if(j->getPose()->getNom() == "Lutin")
    {
        if  (g >= 2)
        {
            retour = 1;
        }
    }
    else if(j->getPose()->getNom() == "Elfe")
    {
        if  (f >= 1)
        {
            retour = 1;
        }
    }
    else if(j->getPose()->getNom() == "Araignee")
    {
        if ( (g>= 1) && (f>=1) )
        {
            retour = 1;
        }
    }

    return retour;
}

void retirerEnergie(Joueur *j) //RETIRE LES ENERGIES UTILISEES POUR L'ATTAQUE
{
    int a = 0;
    int b = 0;
    std::vector<Cartes*> temp;

    if(j->getPose()->getNom() == "Loup-Garou")
    {
        for(auto elem : j->getMain())
        {
            if ( (elem->getNom() == "Foret") && (a<2) )
            {

                j->popMain();
                a++;



            }
            else
            {
                temp.push_back(elem);
            }
        }
        j->setMain(temp);
    }
    else if(j->getPose()->getNom() == "Zombie")
    {
        for(auto elem : j->getMain())
        {
            if ( (elem->getNom() == "Tombe") && (a<1) )
            {

                j->popMain();
                a++;



            }
            else if ( (elem->getNom() == "Chateau") && (b<1) )
            {

                j->popMain();
                b++;



            }
            else
            {
                temp.push_back(elem);
            }
        }
        j->setMain(temp);
    }
    else if(j->getPose()->getNom() == "Vampire")
    {
        for(auto elem : j->getMain())
        {
            if ( (elem->getNom() == "Chateau") && (a<1) )
            {

                j->popMain();
                a++;



            }
            else if ( (elem->getNom() == "Grotte") && (b<1) )
            {

                j->popMain();
                b++;



            }
            else
            {
                temp.push_back(elem);
            }
        }
        j->setMain(temp);
    }
    else if(j->getPose()->getNom() == "Fantome")
    {
        for(auto elem : j->getMain())
        {
            if ( (elem->getNom() == "Tombe") && (a<2) )
            {

                j->popMain();
                a++;



            }
            else
            {
                temp.push_back(elem);
            }
        }
        j->setMain(temp);
    }
    else if(j->getPose()->getNom() == "Sorciere")
    {
        for(auto elem : j->getMain())
        {
            if ( (elem->getNom() == "Chateau") && (a<1) )
            {

                j->popMain();
                a++;



            }
            else
            {
                temp.push_back(elem);
            }
        }
        j->setMain(temp);
    }
    else if(j->getPose()->getNom() == "Lutin")
    {
        for(auto elem : j->getMain())
        {
            if ( (elem->getNom() == "Grotte") && (a<2) )
            {

                j->popMain();
                a++;



            }
            else
            {
                temp.push_back(elem);
            }
        }
        j->setMain(temp);
    }
    else if(j->getPose()->getNom() == "Elfe")
    {
        for(auto elem : j->getMain())
        {
            if ( (elem->getNom() == "Foret") && (a<1) )
            {

                j->popMain();
                a++;



            }
            else
            {
                temp.push_back(elem);
            }
        }
        j->setMain(temp);
    }
    else if(j->getPose()->getNom() == "Araignee")
    {
        for(auto elem : j->getMain())
        {
            if ( (elem->getNom() == "Grotte") && (a<1) )
            {

                j->popMain();
                a++;



            }
            else if ( (elem->getNom() == "Foret") && (b<1) )
            {

                j->popMain();
                b++;



            }
            else
            {
                temp.push_back(elem);
            }
        }
        j->setMain(temp);
    }
}


void AnimationKitSoin()
{

    Monstre *loup = creerLoup();
    loup->affiche(X_DECK,Y_DECK-20);
    gotoligcol(X_DECK+7,Y_DECK-20+2 +7);
    color(10,0);
    std::cout<<"+20PV";
    gotoligcol(X_DECK+7,Y_DECK-20+2 +7);
    Sleep(150);
    std::cout<<"     ";
    gotoligcol(X_DECK+7,Y_DECK-20+2 +7);
    Sleep(150);
    std::cout<<"+20PV";
    gotoligcol(X_DECK+7,Y_DECK-20+2 +7);
    Sleep(150);
    std::cout<<"     ";
    gotoligcol(X_DECK+7,Y_DECK-20+2 +7);
    Sleep(150);
    std::cout<<"+20PV";
    gotoligcol(X_DECK+7,Y_DECK-20+2 +7);
    Sleep(150);
    std::cout<<"     ";
    gotoligcol(X_DECK+7,Y_DECK-20+2 +7);
    Sleep(150);
    std::cout<<"+20PV";
    gotoligcol(X_DECK+7,Y_DECK-20+2 +7);
    Sleep(150);
    std::cout<<"     ";



}

void effaceMonstre()
{
    for (int y = 0; y< 10 ; y++) //EFFACE L'ANCIEN MONSTRE
    {
        gotoligcol(X_DECK + y,Y_DECK - 20 );
        std::cout<<"                   ";
    }

}
