#include <stdio.h>
#include <stdlib.h>
#include "utilitaire.h"
#include <iostream>


void gotoligcol( int lig, int col )
{
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void contour_carte(int x,int y,int col)
{
    char c;
    color(col,0);
    gotoligcol(x, y+1);
    c=0xC9;
    std::cout << c;
    gotoligcol(x, y+14);
    c=0xBB;
    std::cout << c;
    gotoligcol(x+10, y+1);
    c=0xC8;
    std::cout << c;
    gotoligcol(x+10, y+14);
    c=0xBC;
    std::cout << c;
    c=0xCD;

    for (int i=0; i<12; i++)
    {
        gotoligcol(x,y+i+2);
        std::cout <<c;

    }



    for (int i=0; i<12; i++)
    {
        gotoligcol(x+2,y+i+2);
        std::cout <<c;

    }

    for (int i=0; i<12; i++)
    {
        gotoligcol(x+10,y+i+2);
        std::cout <<c;

    }

    c=0xBA;
    for (int i=0; i<9; i++)
    {
        gotoligcol(x+1+i, y+1);
        std::cout <<c;
        gotoligcol(x+1+i, y+14);
        std::cout <<c;
    }
    gotoligcol(x+6,y+10);
}


void contour_carte2(int x,int y,int col)
{
    char c;
    color(col,0);
    gotoligcol(x, y+1);
    c=0xC9;
    std::cout << c;
    gotoligcol(x, y+14);
    c=0xBB;
    std::cout << c;
    gotoligcol(x+10, y+1);
    c=0xC8;
    std::cout << c;
    gotoligcol(x+10, y+14);
    c=0xBC;
    std::cout << c;
    c=0xCD;

    for (int i=0; i<12; i++)
    {
        gotoligcol(x,y+i+2);
        std::cout <<c;

    }



  /*  for (int i=0; i<12; i++)
    {
        gotoligcol(x+2,y+i+2);
        std::cout <<c;

    }*/

    for (int i=0; i<12; i++)
    {
        gotoligcol(x+10,y+i+2);
        std::cout <<c;

    }

    c=0xBA;
    for (int i=0; i<9; i++)
    {
        gotoligcol(x+1+i, y+1);
        std::cout <<c;
        gotoligcol(x+1+i, y+14);
        std::cout <<c;
    }
    gotoligcol(x+6,y+10);
}


void resetPV(Cartes *mobInGame)
{
    if(mobInGame->getNom() == "Loup-Garou")
    {
        mobInGame->setPv(60);
    }
    else if(mobInGame->getNom() == "Zombie")
    {
        mobInGame->setPv(50);
    }
    else if(mobInGame->getNom() == "Vampire")
    {
        mobInGame->setPv(60);
    }
    else if(mobInGame->getNom() == "Fantome")
    {
        mobInGame->setPv(30);
    }
    else if(mobInGame->getNom() == "Sorciere")
    {
        mobInGame->setPv(40);
    }
    else if(mobInGame->getNom() == "Lutin")
    {
        mobInGame->setPv(40);
    }
    else if(mobInGame->getNom() == "Elfe")
    {
        mobInGame->setPv(50);
    }
    else if(mobInGame->getNom() == "Araignee")
    {
        mobInGame->setPv(30);
    }

}
