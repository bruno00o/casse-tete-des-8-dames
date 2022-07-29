/**
 * @file Affichage.h
 * @author Bruno SEILLIEBERT
 * @brief Fichier contenant les fonctions d'affichage du jeu
 * @date 2022-03-29
 */

#ifndef __AFFICHAGE__
#define __AFFICHAGE__

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "Jeu.h"

/**
 * @brief Génère une ligne d'affichage
 *
 * @param taille
 * @return char*
 */
char* genere_ligne(int taille);

/**
 * @brief Compte le nombre de caractères d'une ligne
 *
 * @param taille
 * @return int
 */
int compte_caracteres_ligne(int taille);

/**
 * @brief Affiche le plateau
 *
 * @param pos
 */
void afficher_plateau(Position pos);

/**
 * @brief Gère le clique de la souris et retourne la coordonnée du tableau
 *
 * @param touche
 * @return int
 */
int gestion_clique(int touche);

/**
 * @brief Affiche le nombre de dames restantes
 *
 * @param dames
 */
void afficher_nb_dames(int dames);

/**
 * @brief Affiche le titre du jeu
 *
 */
void affiche_titre();

/**
 * @brief Affiche un message de fin de jeu
 *
 * @param victoire
 */
void affiche_fin(int victoire);

#endif