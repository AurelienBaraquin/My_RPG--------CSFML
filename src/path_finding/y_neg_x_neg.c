/*
** EPITECH PROJECT, 2023
** y_neg_x_neg
** File description:
** Path finding
*/

#include "path_finding.h"

int y_neg_x_neg_end(list_t *list, int check)
{
    if (check == 10) {
        ANNL(list, LEFT);
        ANNL(list, UP);
        return -1;
    }
    if (check == 20) {
        ANNL(list, LEFT);
        return -1;
    }
    if (check == 30) {
        ANNL(list, UP);
        return -1;
    }
    return 0;
}

void y_neg_x_neg(global_t *all, list_t *list)
{
    int i = (all->pos2.y - all->pos1.y);
    int j = (all->pos2.x - all->pos1.x);
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0) {
            int check = the_smallest(HELP[i - 1][j - 1],
            HELP[i][j - 1], HELP[i - 1][j]);
            check == 0 ? i = 0, j = 0 : 0;
            check == -1 && HELP[i - 1][j + 1] > 9 ?
            ANNL(list, RIGHT), ANNL(list, UP), i--, j++ : 0;
            check == -1 && HELP[i - 1][j + 1] < 9 ? i = 0, j = 0 : 0;
            check == 1 ? ANNL(list, LEFT), ANNL(list, UP), i--, j-- : 0;
            check == 2 ? ANNL(list, LEFT), j-- : 0;
            check == 3 ? ANNL(list, UP), i-- : 0;
            y_neg_x_neg_end(list, check) == -1 ? i = 0, j = 0 : 0;
        }
        i == 0 && j > 0 && HELP[i][j - 1] > 9 ? ANNL(list, LEFT), j-- : 0;
        i == 0 && j > 0 && HELP[i][j - 1] < 9 ? i = 0, j = 0 : 0;
        i > 0 && j == 0 && HELP[i - 1][j] > 9 ? ANNL(list, UP), i-- : 0;
        i > 0 && j == 0 && HELP[i - 1][j] < 9 ? i = 0, j = 0 : 0;
    }
}
