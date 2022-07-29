/**
 * @file Test.h
 * @author Bruno SEILLIEBERT
 * @brief Fichier contenant les fonctions de tests
 * @date 2022-03-29
 */

#ifndef __TEST__
#define __TEST__

#include "Jeu.h"

/**
 * @brief Teste la fonction est_case_occupee
 * 
 * @return int 
 */
int test_est_case_occupee();

/**
 * @brief Teste la fonction placer_dame_position
 * 
 * @return int 
 */
int test_placer_dame_position();

/**
 * @brief Teste la fonction retirer_dame_position
 * 
 * @return int 
 */
int test_retirer_dame_position();

/**
 * @brief Teste la fonction init_pos
 * 
 * @return int 
 */
int test_init_pos();

/**
 * @brief Teste les fonctions du programme
 * 
 * @return int 
 */
int test();

#endif