#include "jeu2048.h"
/**
  * @file jeu2048.cpp
  * @version 1.0
  * @author SABRI Sofiane
  * @date 18/09/2020
  * @details Classe Jeu2048
 *
 */

/**

  * @details Constructeur de la classe Jeu2048
  * Initialise le score et le nombre de coups à 0
  * Initialise la grille
  * Place une tuile
 * @brief Jeu2048::Jeu2048
 */

Jeu2048::Jeu2048():
    nbCoups(0),score(0)
{
    srand(time(nullptr));
    for (int i =0;i<NBVAL;i++)
    {
        for (int y=0;y<NBVAL;y++)
        {
            grille[i][y] = 0;
        }
    }


    PlacerNouvelleTuille();

}

/**
 * @brief Jeu2048::JouerCoup
 * @param _direction
 * @return
 */
bool Jeu2048::JouerCoup(const char _direction)
{
    direction = _direction;
    Deplacer();
    if(Calculer())
        Deplacer();
    CalculerScore();
    bool fin = RechercherFinDePartie();
    if (!fin)
        PlacerNouvelleTuille();
    return fin;
}

/**
 * @brief Jeu2048::ObtenirNbCoups
 * @return retourne le nombre de coups
 */
int Jeu2048::ObtenirNbCoups()
{
    return nbCoups;
}
/**
 * @brief Jeu2048::ObtenirScore
 * @return retourne le score
 */
int Jeu2048::ObtenirScore()
{
    return score;
}
/**
 * @brief Jeu2048::ObtenirGrille
 * @param _grille La grille de jeu
 *
 * @return
 */

void Jeu2048::ObtenirGrille(int _grille[][4])
{

    for (int i=0;i<NBVAL;i++)
    {
        for (int y=0;y<NBVAL;y++)
        {
            _grille[i][y]=grille[i][y];
        }
    }
}
/**
 * @brief Jeu2048::TirerAleatoire
 * @param _mode le mode aléatoire choisi
 * @details Choisi une valeur de manière aléatoire en fonction du paramètre mode,
    si mode = POSITION la valeur obtenu est comprise entre 0 et NB_VAL -1
    Si mode = TUILE la valeur est 2 ou 4
 * @return le retour de position ou tuile
 */

int Jeu2048::TirerAleatoire(const MODE_ALEATOIRE _mode)
{
    int retour;
    if (_mode == POSITION)
    {
        retour = rand()%4;
    }
    if (_mode == TUILE)
    {
        retour = (((rand() %2 ) +1) *2);
    }
    return retour;
}

void Jeu2048::PlacerNouvelleTuille()
{
    int i;
    int y;
    do
    {
        i = TirerAleatoire(POSITION);
        y = TirerAleatoire(POSITION);

    }while(grille[i][y] != 0);
    grille[i][y] = TirerAleatoire(TUILE);

}
/**
 * @brief Jeu2048::PlacerNouvelleTuile
 * @details Place une nouvelle tuile de valeur 2 ou 4 à un emplacement libre sur la grille.
    Cet emplacement est choisi au hasard.
 */

/**
 * @brief Jeu2048::Calculer
 * @return
 */

bool Jeu2048::Calculer()
{
    bool retour = false;
    char _direction = direction;
    for (int indice=0;indice<NBVAL -1;indice++)
    {
        switch (_direction) {
        case 'G':
            for (int i=0;i<NBVAL -1;i++)
            {
                for (int y=0;y<NBVAL -2;y++)
                {
                    if (grille[i][y] == 0)
                    {
                        grille[i][y] = grille[i][y] *2;
                        grille[i][y+1] = 0;
                        retour = true;
                    }
                }
            }
            break;
        case 'D':
            for (int i=0;i<NBVAL -1;i++)
            {
                for (int y=NBVAL -2;y>NBVAL-2;y--)
                {
                    if (grille[i][y] == 0)
                    {
                        grille[i][y] = grille[i][y] * 2;
                        grille[i][y-1] = 0;
                        retour = true;
                    }
                }
            }
            break;
        case 'B':
            for (int i=0;i<NBVAL -1;i++)
            {
                for (int y=NBVAL -2;y>NBVAL-2;y--)
                {
                    if (grille[i][y] == 0)
                    {
                        grille[i][y] = grille[i][y] * 2;
                        grille[i-1][y] = 0;
                        retour = true;
                    }
                }
            }
            break;
        case 'H':
            for (int i=0;i<NBVAL -1;i++)
            {
                for (int y=0;y<NBVAL -2;y++)
                {
                    if (grille[i][y] == 0)
                    {
                        grille[i][y] = grille[i][y] * 2;
                        grille[i+1][y] = 0;
                        retour = true;
                    }
                }
            }
            break;

        }
    }
    return retour;

}
/**
 * @brief Jeu2048::Deplacer
 */

void Jeu2048::Deplacer()
{
    char _direction = direction;
    for (int indice=0;indice<NBVAL -1;indice++)
    {
        switch (_direction) {
        case 'G':
            for (int i=0;i<NBVAL -1;i++)
            {
                for (int y=0;y<NBVAL -2;y++)
                {
                    if (grille[i][y] == 0)
                    {
                        grille[i][y] = grille[i][y+1];
                        grille[i][y+1] = 0;
                    }
                }
            }
            break;
        case 'D':
            for (int i=0;i<NBVAL -1;i++)
            {
                for (int y=NBVAL -2;y>NBVAL-2;y--)
                {
                    if (grille[i][y] == 0)
                    {
                        grille[i][y] = grille[i][y-1];
                        grille[i][y-1] = 0;
                    }
                }
            }
            break;
        case 'B':
            for (int i=0;i<NBVAL -1;i++)
            {
                for (int y=NBVAL -2;y>NBVAL-2;y--)
                {
                    if (grille[i][y] == 0)
                    {
                        grille[i][y] = grille[i-1][y];
                        grille[i-1][y] = 0;
                    }
                }
            }
            break;
        case 'H':
            for (int i=0;i<NBVAL -1;i++)
            {
                for (int y=0;y<NBVAL -2;y++)
                {
                    if (grille[i][y] == 0)
                    {
                        grille[i][y] = grille[i+1][y];
                        grille[i+1][y] = 0;
                    }
                }
            }
            break;

        }
    }


}
/**
 * @brief Jeu2048::CalculerScore
 * @details Le score est calculé en effectuant la somme de toutes les cases
 */

int Jeu2048::CalculerScore()
{
    int score;
    for (int i=0;i<NBVAL-1;i++)
    {
        for(int y=0;y<NBVAL-1;y++)
        {
            score = score + grille[i][y];
        }
    }
    return score;

}
/**
 * @brief Jeu2048::RechercherFinDePartie
 * @return la condition de fin
 * @details Une partie se termine lorsqu’une des cases de la grille contient 2048
    ou toutes les cases possèdent une valeur différente de 0
 */

bool Jeu2048::RechercherFinDePartie()
{
    bool fin = false;
    int cpt = 0;
    for (int i=0;i<NBVAL-1;i++)
    {
        for (int y =0;y<NBVAL-1;y++)
        {
            if (grille[i][y]==2048)
            {
                fin = true;
            }
            if (grille[i][y]==0)
            {
                cpt++;
            }
        }
        if (cpt == 0)
        {
            fin = true;
        }
    }
    return fin;

}
