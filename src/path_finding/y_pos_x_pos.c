/*
** EPITECH PROJECT, 2023
** init_commands.c
** File description:
** Path find
*/

#include "path_finding.h"

void y_pos_x_pos_front(global_t *all, list_t *list, int *i, int *j)
{
    int f = *i;
    int n = *j;

    f == ROW - 1 && n < COL - 1 && HELP[f][n + 1] > 9 ?
    ANNL(list, RIGHT), n++ : 0;
    f == ROW - 1 && n < COL - 1 && HELP[f][n + 1] < 9 ?
    f = ROW, n = COL : 0;
    f < ROW - 1 && n == COL - 1 && HELP[f + 1][n] > 9 ?
    ANNL(list, DOWN), f++ : 0;
    f < ROW - 1 && n == COL - 1 && HELP[f + 1][n] < 9 ?
    f = ROW, n = COL : 0;

    *i = f;
    *j = n;
}

int y_pos_x_pos_end(list_t *list, int check)
{
    if (check == 10) {
        ANNL(list, RIGHT);
        ANNL(list, DOWN);
        return -1;
    }
    if (check == 20) {
        ANNL(list, RIGHT);
        return -1;
    }
    if (check == 30) {
        ANNL(list, DOWN);
        return -1;
    }
    return 0;
}

void y_pos_x_pos(global_t *all, list_t *list)
{
    int i = 0;
    int j = 0;
    while (i < ROW - 1 || j < COL - 1) {
        if (i < ROW - 1 && j < COL - 1) {
            int check = the_smallest(HELP[i + 1][j + 1],
            HELP[i][j + 1], HELP[i + 1][j]);
            check == 0 ? i = ROW, j = COL : 0;
            check == -1 && HELP[i + 1][j - 1] > 9 ?
            ANNL(list, LEFT), ANNL(list, DOWN), i++, j-- : 0;
            check == -1 && HELP[i + 1][j - 1] < 9 ? i = ROW, j = COL : 0;
            check == 1 ? ANNL(list, RIGHT), ANNL(list, DOWN), i++, j++ : 0;
            check == 2 ? ANNL(list, RIGHT), j++ : 0;
            check == 3 ? ANNL(list, DOWN), i++ : 0;
            y_pos_x_pos_end(list, check) == -1 ? i = ROW, j = COL : 0;
        }
        y_pos_x_pos_front(all, list, &i, &j);
    }
}
