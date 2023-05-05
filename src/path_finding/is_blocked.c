/*
** EPITECH PROJECT, 2023
** is_blocked.c
** File description:
** Path find
*/

#include "path_finding.h"

void edit_help_man_opp(global_t *all, int row, int cols)
{
    if (row > 0 && cols < all->cols - 1)
        HELP[row - 1][cols + 1] == 0 || HELP[row - 1][cols + 1] == -1 ?
        HELP[row - 1][cols + 1] = HELP[row][cols] + 1,
        edit_help_man_opp(all, row - 1, cols + 1) : 0;
    if (row > 0)
        HELP[row - 1][cols] == 0 || HELP[row - 1][cols] == -1 ?
        HELP[row - 1][cols] = HELP[row][cols] + 1,
        edit_help_man_opp(all, row - 1, cols) : 0;
    if (cols < all->cols - 1)
        HELP[row][cols + 1] == 0 || HELP[row][cols + 1] == -1 ?
        HELP[row][cols + 1] = HELP[row][cols] + 1,
        edit_help_man_opp(all, row, cols + 1) : 0;
    if (row < all->row - 1)
        HELP[row + 1][cols] == 0 || HELP[row + 1][cols] == -1 ?
        HELP[row + 1][cols] = HELP[row][cols] + 1,
        edit_help_man_opp(all, row + 1, cols) : 0;
    if (cols > 0)
        HELP[row][cols - 1] == 0 || HELP[row][cols - 1] == -1 ?
        HELP[row][cols - 1] = HELP[row][cols] + 1,
        edit_help_man_opp(all, row, cols - 1) : 0;
}

void edit_help_man(global_t *all, int row, int cols)
{
    if (row > 0 && cols > 0)
        HELP[row - 1][cols - 1] == 0 || HELP[row - 1][cols - 1] == -1 ?
        HELP[row - 1][cols - 1] = HELP[row][cols] + 1,
        edit_help_man(all, row - 1, cols - 1) : 0;
    if (row > 0)
        HELP[row - 1][cols] == 0 || HELP[row - 1][cols] == -1 ?
        HELP[row - 1][cols] = HELP[row][cols] + 1,
        edit_help_man(all, row - 1, cols) : 0;
    if (row < all->row - 1)
        HELP[row + 1][cols] == 0 || HELP[row + 1][cols] == -1 ?
        HELP[row + 1][cols] = HELP[row][cols] + 1,
        edit_help_man(all, row + 1, cols) : 0;
    if (cols < all->cols - 1)
        HELP[row][cols + 1] == 0 || HELP[row][cols + 1] == -1 ?
        HELP[row][cols + 1] = HELP[row][cols] + 1,
        edit_help_man(all, row, cols + 1) : 0;
    if (cols > 0)
        HELP[row][cols - 1] == 0 || HELP[row][cols - 1] == -1 ?
        HELP[row][cols - 1] = HELP[row][cols] + 1,
        edit_help_man(all, row, cols - 1) : 0;
}

void check_different_ways_pos(global_t *all, list_t *list)
{
    int last_line = (all->pos2.y - all->pos1.y);
    int first_line = 0;
    int first_cols = 0;
    int last_cols = (all->pos2.x - all->pos1.x);

    if (all->y_sign * all->x_sign > 0) {
        HELP[last_line][last_cols ] = 10;
        HELP[first_line][first_cols] = -1;
        edit_help_man(all, all->row - 1, all->cols - 1);
        if (HELP[0][0] == -1) {
            is_not_blocked(all, list);
            return;
        }
        if (all->x_sign < 0 && all->y_sign < 0 )
            y_neg_x_neg(all, list);
        if (all->x_sign > 0 && all->y_sign > 0 )
            y_pos_x_pos(all, list);
    }
}

void check_different_ways_neg(global_t *all, list_t *list)
{
    int last_line = (all->pos2.y - all->pos1.y);
    int first_line = 0;
    int first_cols = 0;
    int last_cols = (all->pos2.x - all->pos1.x);

    if (all->y_sign * all->x_sign < 0) {
        HELP[last_line][first_cols ] = 10;
        HELP[first_line][last_cols] = -1;
        edit_help_man_opp(all, last_line, first_cols);
        if (HELP[first_line][last_cols] == -1) {
            is_not_blocked(all, list);
            return;
        }
        if (all->y_sign < 0 && all->x_sign > 0)
            y_neg_x_pos(all, list);
        if (all->y_sign > 0 && all->x_sign < 0)
            y_pos_x_neg(all, list);
    }
}

void is_blocked(global_t *all, list_t *list)
{
    if (all->y_sign * all->x_sign == 0) {
        is_not_blocked(all, list);
        return;
    }
    init_help(all);
    check_different_ways_pos(all, list);
    check_different_ways_neg(all, list);
}
