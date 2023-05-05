/*
** EPITECH PROJECT, 2023
** is-not_blocked
** File description:
** Path Finding
*/

#include "path_finding.h"

void is_not_blocked(global_t *all, list_t *list)
{
    sfVector2f dis;
    int row = all->dep.y;
    int cols = all->dep.x;
    int check = 0;

    dis.x = all->arr.x - all->dep.x;
    dis.y = all->arr.y - all->dep.y;
    while (dis.x != 0 || dis.y != 0) {
        check = 0;
        dis.y > 0 && all->map[row + 1][cols] == '0' ?
        add_new_node_last(list, DOWN), row++, dis.y -= 1, check++ : 0;
        dis.y < 0 && all->map[row - 1][cols] == '0' ?
        add_new_node_last(list, UP), row--, dis.y += 1, check++ : 0;
        dis.x > 0 && all->map[row][cols + 1] == '0' ?
        add_new_node_last(list, RIGHT), cols++, dis.x -= 1, check++ : 0;
        dis.x < 0 && all->map[row][cols - 1] == '0' ?
        add_new_node_last(list, LEFT), cols--, dis.x += 1, check++ : 0;
        if (check == 0)
            break;
    }
}
