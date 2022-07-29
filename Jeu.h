/**
 * @file Jeu.h
 * @author Bruno SEILLIEBERT
 * @brief Fichier contenant les fonctions de gestion du jeu
 * @date 2022-03-29
 */

#ifndef __JEU__
#define __JEU__

#include <stdio.h>
#define NB_DAMES 8

typedef enum {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8
} Case;

typedef unsigned long long Position;
Position tab_cases_attaquees[64];

/**
 * @brief Retourne 1 si la case c est occupée par une dame, 0 sinon
 *
 * @param pos
 * @param c
 * @return int
 */
int est_case_occupee(Position pos, Case c);

/**
 * @brief Place la dame dans la case c
 *
 * @param pos
 * @param c
 * @return int
 */
int placer_dame_position(Position* pos, Case c);

/**
 * @brief Retire la dame de la case c
 *
 * @param pos
 * @param c
 * @return int
 */
int retirer_dame_position(Position* pos, Case c);

/**
 * @brief Initlise la position pos à 0
 *
 * @param pos
 */
void init_pos(Position* pos);

/**
 * @brief Genere un tableau de 64 cases, chaque case est un entier
 * valant 1 si la case est occupée par une dame, 0 sinon
 *
 * @param pos
 * @param tab_cases_attaquees
 */
void generer_tableau(Position pos, int tab[64]);

/**
 * @brief Affiche la position pos sur la sortie standard
 *
 * @param pos
 * @return int
 */
int afficher_position(Position pos);

/**
 * @brief Calcule les cases attaquées par la dame dans la position pos
 *
 * @param pos
 * @param c
 * @return int
 */
int calculer_cases_attaquees(Position* pos, Case c);

/**
 * @brief Ajoute les cases attaquées par toutes les dames dans le tableau
 *
 * @param pos
 */
void generer_tab_cases_attaquees(Position pos);

/**
 * @brief Retourne 1 si les dames sont sans attaques mutuelles, 0 sinon
 *
 * @param pos
 * @return int
 */
int est_sans_attaque_mutuelle(Position pos);

#endif