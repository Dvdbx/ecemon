#ifndef UTILITAIRE_H_INCLUDED
#define UTILITAIRE_H_INCLUDED
#include "Cartes.h"
#include "Energies.h"
#include "monstre.h"
#include "Attaque.h"
#include <windows.h>
#include "classJeu.h"
#include "speciale.h"
#include "Joueur.h"
#define X_DECK 15
#define Y_DECK 95
#define UP 72
#define DOWN 80
#define GAUCHE 75
#define DROITE 77
#define ENTREE 13
#define ESPACE 32
void gotoligcol( int lig, int col );
void color(int couleurDuTexte,int couleurDeFond);
void contour_carte(int x,int y,int col);
void affiche_carte(Cartes *a,int x,int y);
void contour_carte2(int x,int y,int col);
void resetPV(Cartes *mobInGame);

















/**
Tuyau double:
Angle haut gauche: 0xC9
Angle haut droit:  0xBB
Angle bas gauche:  0xC8
Angle bas droit:   0xBC
Horizontal: 0xCD
Vertical:   0xBA
Vertical gauche: 0xB9
Vertical droit:  0xCC

*/
/*
0 : Noir
1 : Bleu foncé
2 : Vert foncé
3 : Turquoise
4 : Rouge foncé
5 : Violet
6 : Vert caca d'oie
7 : Gris clair
8 : Gris foncé
9 : Bleu fluo
10 : Vert fluo
11 : Turquoise
12 : Rouge fluo
13 : Violet 2
14 : Jaune
15 : Blanc
*/


#endif // UTILITAIRE_H_INCLUDED
