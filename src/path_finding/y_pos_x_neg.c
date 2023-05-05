/*
** EPITECH PROJECT, 2023
** y_pos_x_neg
** File description:
** Path finding
*/

#include "path_finding.h"

void y_pos_x_neg_front(global_t *all, list_t *list, int *i, int *j)
{
    int f = *i;
    int n = *j;

    f == all->row - 1 && n > 0 && HELP[f][n - 1] > 9 ?
    ANNL(list, LEFT), n-- : 0;
    f == all->row - 1 && n > 0 && HELP[f][n - 1] < 9 ? n = 0 : 0;
    f < all->row - 1 && n == 0 && HELP[f + 1][n] > 9 ?
    ANNL(list, DOWN), f++ : 0;
    f < all->row - 1 && n == 0 && HELP[f + 1][n] < 9 ? n = 0 : 0;

    *i = f;
    *j = n;
}

int y_pos_x_neg_end(list_t *list, int check)
{
    if (check == 10) {
        ANNL(list, LEFT);
        ANNL(list, DOWN);
        return -1;
    }
    if (check == 20) {
        ANNL(list, LEFT);
        return -1;
    }
    if (check == 30) {
        ANNL(list, DOWN);
        return -1;
    }
    return 0;
}

void y_pos_x_neg(global_t *all, list_t *list)
{
    int i = 0;
    int j = (all->pos2.x - all->pos1.x);

    while (i < all->row - 1 || j > 0) {
        if (i < all->row - 1 && j > 0) {
            int check = the_smallest(HELP[i + 1][j - 1],
            HELP[i][j - 1], HELP[i + 1][j]);
            check == 0 ? i = all->row, j = 0 : 0;
            check == -1 && HELP[i + 1][j + 1] > 9 ? ANNL(list, RIGHT),
            ANNL(list, DOWN), i++, j++ : 0;
            check == -1 && HELP[i + 1][j + 1] < 9 ? i = all->row, j = 0 : 0;
            check == 1 ? ANNL(list, LEFT), ANNL(list, DOWN), i++, j-- : 0;
            check == 2 ? ANNL(list, LEFT), j-- : 0;
            check == 3 ? ANNL(list, DOWN), i++ : 0;
            y_pos_x_neg_end(list, check) == -1 ? i = all->row, j = 0 : 0;
        }
        y_pos_x_neg_front(all, list, &i, &j);
    }
}
