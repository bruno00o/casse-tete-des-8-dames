/**
 * @file Test.c
 * @author Bruno SEILLIEBERT
 * @brief Fichier contenant les fonctions de tests
 * @date 2022-03-29
 */

#include "Test.h"

int test_est_case_occupee() {
    Position pos;
    Case c;
    int res;
    c = 0;
    init_pos(&pos);
    res = est_case_occupee(pos, c);
    if (res) {
        return 0;
    }
    pos = 1ULL << 0;
    res = est_case_occupee(pos, c);
    if (!res) {
        return 0;
    }
    return 1;
}

int test_placer_dame_position() {
    Position pos;
    Case c;
    int res;
    c = 0;
    init_pos(&pos);
    res = placer_dame_position(&pos, c);
    if (!res) {
        return 0;
    }
    res = est_case_occupee(pos, c);
    if (!res) {
        return 0;
    }
    return 1;
}

int test_retirer_dame_position() {
    Position pos;
    Case c;
    int res;
    c = 0;
    init_pos(&pos);
    placer_dame_position(&pos, c);
    res = retirer_dame_position(&pos, c);
    if (!res) {
        return 0;
    }
    res = est_case_occupee(pos, c);
    if (res) {
        return 0;
    }
    return 1;
}

int test_init_pos() {
    Position pos;
    init_pos(&pos);
    if ((int)pos != 0) {
        return 0;
    }
    return 1;
}

int test() {
    int res;
    res = test_est_case_occupee();
    if (!res) {
        printf("erreur : test_est_case_occupee\n");
        return 0;
    }
    res = test_placer_dame_position();
    if (!res) {
        printf("erreur : test_placer_dame_position\n");
        return 0;
    }
    res = test_retirer_dame_position();
    if (!res) {
        printf("erreur : test_retirer_dame_position\n");
        return 0;
    }
    res = test_init_pos();
    if (!res) {
        printf("erreur : test_init_pos\n");
        return 0;
    }
    return 1;
}