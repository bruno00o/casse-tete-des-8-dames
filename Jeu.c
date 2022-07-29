/**
 * @file Jeu.c
 * @author Bruno SEILLIEBERT
 * @brief Fichier contenant les fonctions de gestion du jeu
 * @date 2022-03-29
 */

#include "Jeu.h"

int est_case_occupee(Position pos, Case c) {
    if ((pos >> c) & 1) {
        return 1;
    }
    return 0;
}

int placer_dame_position(Position* pos, Case c) {
    if (est_case_occupee(*pos, c)) {
        return 0;
    }
    *pos |= (1ULL << c);
    return 1;
}

int retirer_dame_position(Position* pos, Case c) {
    if (!est_case_occupee(*pos, c))
        return 0;
    *pos &= ~(1ULL << c);
    return 1;
}

void init_pos(Position* pos) {
    *pos = (1ULL << 0);
    retirer_dame_position(pos, 0);
}

void generer_tableau(Position pos, int tab[64]) {
    int i;
    for (i = 0; pos > 0; i++) {
        tab[i] = pos % 2;
        pos = pos / 2;
    }
    for (i = i; i < 64; i++) {
        tab[i] = 0;
    }
    if (pos < 0) {
        tab[63] = 1;
    }
}

int afficher_position(Position pos) {
    int i, j;
    int tab[64];
    generer_tableau(pos, tab);
    for (i = 63 - 7; i >= 0; i -= 8) {
        for (j = 0; j < 8; j++)
            tab[i + j] ? printf("+ ") : printf(". ");
        printf("\n");
    }
    return 1;
}

int calculer_cases_attaquees(Position* pos, Case c) {
    unsigned long long i, j, res;
    if (!est_case_occupee(*pos, c)) {
        for (i = 0; i < c % 8; i++) {
            placer_dame_position(pos, c - i - 1);
        }
        for (i = 0; i < 7 - c % 8; i++) {
            placer_dame_position(pos, c + i + 1);
        }
        for (j = 0; j < 7 - c / 8; j++) {
            placer_dame_position(pos, c + 8 + j * 8);
        }
        for (j = 0; j < c / 8; j++) {
            placer_dame_position(pos, c - 8 - j * 8);
        }
        for (i = 1, j = 1; i < 7 - c % 8 + 1; i++, j++) {
            res = c + i + j * 8;
            if ((int)res > 0 && (int)res < 64)
                placer_dame_position(pos, res);
        }
        for (i = 1, j = 1; i < c % 8 + 1; i++, j++) {
            res = c - i + j * 8;
            if ((int)res > 0 && (int)res < 64)
                placer_dame_position(pos, res);
        }
        for (i = 1, j = 1; i < c % 8 + 1; i++, j++) {
            res = c - i - j * 8;
            if ((int)res > 0 && (int)res < 64)
                placer_dame_position(pos, res);
        }
        for (i = 1, j = 1; i < 7 - c % 8 + 1; i++, j++) {
            res = c + i - j * 8;
            if ((int)res > 0 && (int)res < 64)
                placer_dame_position(pos, res);
        }
    }
    return 1;
}

void generer_tab_cases_attaquees(Position pos) {
    int i;
    Position a;
    for (i = 0; i < 64; i++) {
        init_pos(&a);
        if (est_case_occupee(pos, i))
            calculer_cases_attaquees(&a, i);
        tab_cases_attaquees[i] = a;
    }
}

int est_sans_attaque_mutuelle(Position pos) {
    int i, j;
    int tab[64];
    Position attaques;
    init_pos(&attaques);
    generer_tab_cases_attaquees(pos);
    for (i = 0; i < 64; i++) {
        generer_tableau(tab_cases_attaquees[i], tab);
        for (j = 0; j < 64; j++) {
            if (tab[j]) {
                placer_dame_position(&attaques, j);
            }
        }
    }
    return !(pos & attaques);
}

