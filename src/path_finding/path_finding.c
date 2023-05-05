/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** Path find
*/

#include "path_finding.h"

int verify_positions(global_t *all)
{
    int y_dep = all->dep.y;
    int x_dep = all->dep.x;
    int y_arr = all->arr.y;
    int x_arr = all->arr.x;

    if (y_arr < 0 || x_arr < 0)
        return -1;
    if (y_arr > 999 || x_arr > 999)
        return -1;
    if (all->map[y_arr][x_arr] == '1')
        return -1;
    return 0;
}

deplacement_t* path_finding(char **map, sfVector2f start, sfVector2f end)
{
    global_t all;
    all.map = map;
    list_t *list = init_list();
    all.dep = start;
    all.arr = end;
    if (verify_positions(&all) == -1)
        return NULL;
    find_way(&all, list);
    if (list->first->next == NULL)
        return NULL;
    if (list->first->direction == 10)
        delete_first_node(list);
    else
        delete_last_node(list);
    return list->first;
}
