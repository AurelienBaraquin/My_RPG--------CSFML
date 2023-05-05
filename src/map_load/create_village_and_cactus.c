/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** create_village_and_cactus
*/

#include "my.h"

int create_village_next(create_village_t *village,
int i, create_struct_t *structure, int j)
{
    if (((village->map[i][j] != '1' && village->map[i][j] != '0') ||
    (village->x > j || village->y > i) ||
        enought_size(village, i, j, 1) == 0) && (((structure->x > j ||
        structure->y > i) ||
        enought_size(village, i, j, 0) == 0))) {
        write(village->fd, "0", 1);
        return 1;
    }
    if (village->map[i][j] == '1' && village->x <= j && village->y <= i &&
    enought_size(village, i, j, 1) == 1) {
        write(village->fd, &village->village, 1);
        village->village = rand() % 3 + '1';
        village->x = j + village->x_dist;
        village->y = i + village->y_dist;
        village->x_dist = rand() % 40 + 50;
        village->y_dist = rand() % 40 + 50;
        return 1;
    }
    return 0;
}
