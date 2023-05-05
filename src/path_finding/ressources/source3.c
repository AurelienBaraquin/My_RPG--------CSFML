/*
** EPITECH PROJECT, 2023
** source3.c
** File description:
** Find path
*/

#include "path_finding.h"

void init_help(global_t *all)
{
    int p = 0;
    int k = 0;

    all->row = all->pos2.y - all->pos1.y + 1;
    all->cols = all->pos2.x - all->pos1.x + 1;
    HELP = malloc(sizeof(int *) * all->row);
    for (int i = 0; i < all->row; i++)
        HELP[i] = malloc(sizeof(int) * (all->cols));
    for (int f = all->pos1.y; f <= all->pos2.y; f++, p++) {
        k = 0;
        for (int n = all->pos1.x; n <= all->pos2.x; n++, k++) {
            all->map[f][n] == '1' ? HELP[p][k] = 1 : 0;
            all->map[f][n] == '0' ? HELP[p][k] = 0 : 0;
        }
    }
}

int always_pos(int nb)
{
    if (nb < 0)
        return -nb;
    return nb;
}

int cols_nb(char *str)
{
    int size = 0;

    while (str[size])
        size++;

    return size;
}

void inverse_list(list_t *list)
{
    deplacement_t *node = list->first;

    while (node != NULL) {
        node->direction == RIGHT ? node->direction = LEFT,
        node = node->next : 0;
        node->direction == LEFT ? node->direction = RIGHT,
        node = node->next : 0;
        node->direction == UP ? node->direction = DOWN, node = node->next : 0;
        node->direction == DOWN ? node->direction = UP, node = node->next : 0;
        node->direction == 10 ? node = node->next : 0;
    }
}

int the_smallest(int nb1, int nb2, int nb3)
{
    int result = 0;
    if (nb1 == 10)
        return 10;
    if (nb2 == 10)
        return 20;
    if (nb3 == 10)
        return 30;
    nb1 == 1 ? nb1 = INT_MAX : 0;
    nb2 == 1 ? nb2 = INT_MAX : 0;
    nb3 == 1 ? nb3 = INT_MAX : 0;
    nb1 <= nb2 ? result = nb1 : 0;
    nb1 > nb2 ? result = nb2 : 0;
    result >= nb3 ? result = nb3 : 0;
    return result == INT_MAX ? -1 : result == nb1 ? 1 :
    result == nb2 ? 2 : result == nb3 ? 3 : 0;
}
