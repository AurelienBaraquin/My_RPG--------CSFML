/*
** EPITECH PROJECT, 2023
** source4.c
** File description:
** Path finding
*/

#include "path_finding.h"

int is_line_blocked(global_t *all, int cols, int start, int stop)
{
    for (int i = start; i <= stop; i++) {
        if (all->map[i][cols] != '0')
            return -1;
    }
    return 0;
}

int check_right(global_t *all)
{
    int cols = all->dep.x;
    int start = all->pos1.y;
    int stop = all->pos2.y;
    int right = 0;

    all->cols = cols_nb(all->map[0]);

    while (cols < all->cols) {
        if (is_line_blocked(all, cols, start, stop) == -1) {
            right++;
            cols++;
        }
        if (is_line_blocked(all, cols, start, stop) != -1)
            break;
    }
    return right;
}

int check_left(global_t *all)
{
    int cols = all->dep.x;
    int start = all->pos1.y;
    int stop = all->pos2.y;
    int left = 0;

    while (cols >= 0) {
        if (is_line_blocked(all, cols, start, stop) == -1) {
            left++;
            cols--;
        }
        if (is_line_blocked(all, cols, start, stop) != -1)
            break;
    }
    return left;
}

int check_up(global_t *all)
{
    int row = all->dep.y;
    int start = all->pos1.x;
    int stop = all->pos2.x;
    int up = 0;

    while (row >= 0) {
        if (is_there_this_char(all->map[row], '1', start, stop) == -1) {
            row--;
            up++;
        }
        if (is_there_this_char(all->map[row], '1', start, stop) != -1)
            break;
    }
    return up;
}

int check_down(global_t *all)
{
    int row = all->dep.y;
    int start = all->pos1.x;
    int stop = all->pos2.x;
    int down = 0;

    while (all->map[row] != NULL) {
        if (is_there_this_char(all->map[row], '1', start, stop) == -1) {
            row++;
            down++;
        }
        if (is_there_this_char(all->map[row], '1', start, stop) != -1)
            break;
    }
    return down;
}
