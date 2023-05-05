/*
** EPITECH PROJECT, 2023
** find_way.c
** File description:
** Path Find
*/

#include "path_finding.h"

void init_direction(global_t *all)
{
    all->dis.x = all->arr.x - all->dep.x;
    all->dis.y = all->arr.y - all->dep.y;
    all->dis.x < 0 ? all->x_sign = -1 : 0;
    all->dis.x > 0 ? all->x_sign = 1 : 0;
    all->dis.x == 0 ? all->x_sign = 0 : 0;
    all->dis.y < 0 ? all->y_sign = -1 : 0;
    all->dis.y > 0 ? all->y_sign = 1 : 0;
    all->dis.y == 0 ? all->y_sign = 0 : 0;
}

void init_pos(global_t *all)
{
    if (all->dis.x >= 0) {
        all->pos1.x = all->dep.x;
        all->pos2.x = all->arr.x;
    }
    if (all->dis.x < 0) {
        all->pos1.x = all->arr.x;
        all->pos2.x = all->dep.x;
    }
    if (all->dis.y >= 0) {
        all->pos1.y = all->dep.y;
        all->pos2.y = all->arr.y;
    }
    if (all->dis.y < 0) {
        all->pos1.y = all->arr.y;
        all->pos2.y = all->dep.y;
    }
}

void init_situation(global_t *all)
{
    int start = all->pos1.x;
    int stop = all->pos2.x;

    all->is_blocked = 0;
    for (int i = all->pos1.y; i <= all->pos2.y; i++) {
        if (is_there_this_char(all->map[i], '1', start, stop) == -1)
            all->is_blocked = -1;
    }
}

void find_way(global_t *all, list_t *list)
{
    init_direction(all);
    init_pos(all);
    init_situation(all);
    all->is_blocked == 0 ? is_not_blocked(all, list) : 0;
    all->is_blocked == -1 ? is_blocked(all, list) : 0;
}
