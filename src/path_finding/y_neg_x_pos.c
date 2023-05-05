/*
** EPITECH PROJECT, 2023
** y_neg_x_pos
** File description:
** Path finding
*/

#include "path_finding.h"

void y_neg_x_pos_front(global_t *all, list_t *list, int *i, int *j)
{
    int f = *i;
    int n = *j;

    f == 0 && n < all->cols - 1 && HELP[f][n + 1] > 9 ?
    ANNL(list, RIGHT), n++ : 0;
    f == 0 && n < all->cols - 1 && HELP[f][n + 1] < 9 ?
    f = 0, n = all->cols - 1 : 0;
    f > 0 && n == all->cols - 1 && HELP[f - 1][n] > 9 ?
    ANNL(list, UP), f-- : 0;
    f > 0 && n == all->cols - 1 && HELP[f - 1][n] < 9 ?
    f = 0, n = all->cols - 1 : 0;

    *i = f;
    *j = n;
}

int y_neg_x_pos_end(list_t *list, int check)
{
    if (check == 10) {
        ANNL(list, RIGHT);
        ANNL(list, UP);
        return -1;
    }
    if (check == 20) {
        ANNL(list, RIGHT);
        return -1;
    }
    if (check == 30) {
        ANNL(list, UP);
        return -1;
    }
    return 0;
}

void y_neg_x_pos(global_t *all, list_t *list)
{
    int i = (all->pos2.y - all->pos1.y);
    int j = 0;
    while (i > 0 || j < all->cols - 1) {
        if (i > 0 && j < all->cols - 1) {
            int check = the_smallest(HELP[i - 1][j + 1],
            HELP[i][j + 1], HELP[i - 1][j]);
            check == 0 ? i = 0, j = all->cols - 1 : 0;
            check == -1 && (HELP[i - 1][j - 1] > 9) ? ANNL(list, LEFT),
            ANNL(list, UP), i--, j-- : 0;
            check == -1 && (HELP[i - 1][j - 1] < 9) ?
            i = 0, j = all->cols - 1 : 0;
            check == 1 ? ANNL(list, RIGHT), ANNL(list, UP), i--, j++ : 0;
            check == 2 ? ANNL(list, RIGHT), j++ : 0;
            check == 3 ? ANNL(list, UP), i-- : 0;
            y_neg_x_pos_end(list, check) == -1 ? i = 0, j = all->cols - 1 : 0;
        }
        y_neg_x_pos_front(all, list, &i, &j);
    }
}
