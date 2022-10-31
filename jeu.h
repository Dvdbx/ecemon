#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "utilitaire.h"
void menu_jeu();
void nouveauJoueur();
std::vector<Joueur*> choixJoueur();
std::vector<Joueur*> chargerJoueurs();
void gameLoop(std::vector<Joueur*> joueurs);
void parties(std::vector<Joueur*> joueurs);
void affichageJeu(Joueur *joueur);
void affichageEnergies(Joueur *joueur);
void affichageMonstreAdverse(Joueur *joueur);
void effaceInfo();
void affichageInfo(Cartes *info);
void effaceMonstreAdverse();
void animationAttaque(int degat);
void CompteEnergie(int *f,int *g,int *t, int *c, Joueur *j );
int ConditionAttaque(Joueur *j);
void retirerEnergie(Joueur *j);
void AnimationKitSoin();
void effaceMonstre();
void affichageInfoSpeciale (int bouclier);

#endif // JEU_H_INCLUDED
