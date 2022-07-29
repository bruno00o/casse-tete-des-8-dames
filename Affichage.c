/**
 * @file Affichage.c
 * @author Bruno SEILLIEBERT
 * @brief Fichier contenant les fonctions d'affichage du jeu
 * @date 2022-03-29
 */

#include "Affichage.h"

char* genere_ligne(int taille) {
    int i;
    char* ligne = malloc(sizeof(char) * 128);
    for (i = 0; i < taille; i++) {
        strncat(ligne, "+---", 5);
    }
    strncat(ligne, "+", 2);
    return ligne;
}

int compte_caracteres_ligne(int taille) {
    int val;
    char* ligne = genere_ligne(taille);
    val = strlen(ligne);
    free(ligne);
    return val;
}

void afficher_plateau(Position pos) {
    int i, j, k, init;
    char* ligne = genere_ligne(8);
    init = COLS / 2 - compte_caracteres_ligne(8) / 2;
    k = 0;
    for (i = 4 + 8 * 2; i > 4; i--) {
        if (i % 2 == 0)
            mvprintw(i, init, ligne);
        else {
            for (j = 0; j < 8; j++) {
                mvprintw(i, init + j * 4, "| %c ",
                    est_case_occupee(pos, k) ? 'O' : ' ');
                k++;
                if (j == 8 - 1)
                    mvprintw(i, init + j * 4 + 4, "|");
            }
        }
    }
    mvprintw(i, init, ligne);
}

int gestion_clique(int touche) {
    int i, j;
    MEVENT ev;
    if (touche == KEY_MOUSE && getmouse(&ev) == OK) {
        j = (ev.x - (COLS / 2 - compte_caracteres_ligne(8) / 2)) / 4;
        i = (((ev.y - 4) / 2 - 7) * -1) * 8;
        if (j >= 0 && j <= 7 && ev.y >= 4 && ev.y <= 8 * 2 + 4)
            return i + j;
    }
    return -1;
}

void afficher_nb_dames(int dames) {
    int init, i;
    init = COLS / 2 - compte_caracteres_ligne(8) / 2 - 4;
    for (i = 4; i < 4 + 8 * 2; i++) {
        if (i % 2 == 0 || !dames)
            mvprintw(i, init, " ");
        else {
            mvprintw(i, init, "O");
            dames--;
        }
    }
}

void affiche_titre() {
    char* titre = "Casse-tête des huits dames";
    mvprintw(2, COLS / 2 - strlen(titre) / 2, titre);
}

void affiche_fin(int victoire) {
    char message[128];
    clear();
    if (victoire)
        strcpy(message, "Casse-tête réussi !");
    else
        strcpy(message, "Casse-tête échoué...");
    mvprintw(LINES / 2, COLS / 2 - strlen(message) / 2, "%s", message);
}
