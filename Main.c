/**
 * @file Main.c
 * @author Bruno SEILLIEBERT
 * @brief Fichier contenant les fonctions principales du programme
 * @date 2022-03-29
 */

#include "Affichage.h"
#include "Test.h"
#include <assert.h>

 /**
  * @brief Gestion d'une partie
  *
  * @return int
  */
int joue_partie() {
    int touche, dames, coord, col, lines;
    int pos_dames[NB_DAMES];
    Position pos;
    col = COLS;
    lines = LINES;
    init_pos(&pos);
    dames = NB_DAMES;
    afficher_plateau(pos);
    while (touche != 'q') {
        touche = getch();
        touche = (LINES == lines && COLS == col) ? touche : 'q';
        if ((coord = gestion_clique(touche)) >= 0 && dames) {
            placer_dame_position(&pos, coord);
            pos_dames[dames] = coord;
            dames--;
        }
        if (touche == 'a' && dames < NB_DAMES) {
            retirer_dame_position(&pos, pos_dames[dames + 1]);
            dames++;
        }
        afficher_plateau(pos);
        afficher_nb_dames(dames);
        if (!dames) {
            return est_sans_attaque_mutuelle(pos);
        }
    }
    return -1;
}

/**
 * @brief Fonction principale du programme
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char const* argv[]) {
    int victoire;

    assert(test());

    initscr();

    assert(LINES >= 8 * 2 + 8);
    assert(COLS > 8 * 8);

    noecho();
    curs_set(FALSE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    affiche_titre();

    victoire = joue_partie();
    if (victoire >= 0) {
        nodelay(stdscr, FALSE);
        getch();
        affiche_fin(victoire);
        getch();
    }

    endwin();
    return 0;
}
