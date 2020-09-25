#ifndef JEU2048_H
#define JEU2048_H
#include <iostream>
#include <math.h>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <string>
#define NBVAL 4

using namespace std;
enum MODE_ALEATOIRE
{
    POSITION,
    TUILE
};


class Jeu2048
{
private:
    const int NB_VAL=4;
    ///la grille contenant le jeu
    int grille[4][4];
    ///la direction choisi par le joueur
    char direction;
    ///nombre de déplacement
    int nbCoups;
    ///score obtenu, somme des case de la grille
    int score;
public:
    Jeu2048();
    bool JouerCoup(char _direction);
    int ObtenirNbCoups();
    int ObtenirScore();
    void ObtenirGrille(int _grille[][4]);

private:
    int TirerAleatoire(const MODE_ALEATOIRE _mode);
    void PlacerNouvelleTuille();
    bool Calculer();
    void Deplacer();
    int CalculerScore();
    bool RechercherFinDePartie();

};
#endif // JEU2048_H
