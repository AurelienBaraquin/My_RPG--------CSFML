/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** create_village_map
*/

#include "my.h"

int verif_size(create_village_t *village, int *x_y, int i, int type)
{
    if (type == 0)
        village->size = 20;
    else
        village->size = 40;
    for (int j = 0; j < village->size; j++) {
        if (village->map[x_y[0] + i][x_y[1] + j] != '1' && type == 1)
            return 0;
        if (village->map[x_y[0] + i][x_y[1] + j] != '0' && type == 0)
            return 0;
    }
    return 1;
}

int enought_size(create_village_t *village, int x, int y, int type)
{
    if (x + village->size >= MAP_SIZE || y + village->size >= MAP_SIZE)
        return 0;
    int *x_y = malloc(sizeof(int) * 2);
    for (int i = 0; i < village->size; i++) {
        x_y[0] = x;
        x_y[1] = y;
        if (verif_size(village, x_y, i, type) == 0)
            return 0;
    }
    return 1;
}

int finish_display_struct(create_village_t *village,
int i, create_struct_t *structure, int j)
{
    int a = create_village_next(village, i, structure, j);
    if (a == 1)
        return 1;
    if (village->map[i][j] == '0' && structure->x <= j && structure->y <= i &&
        enought_size(village, i, j, 0) == 1) {
        write(village->fd, "t", 1);
        structure->x = j + structure->x_dist;
        structure->y = i + structure->y_dist;
        structure->x_dist = rand() % 40 + 50;
        structure->y_dist = rand() % 40 + 50;
        return 1;
    }
    return 0;
}

int create_village_two(create_village_t *village, int i,
create_struct_t *structure)
{
    for (int j = 0; j < MAP_SIZE; j++) {
        int random = rand() % 1000;
        if (village->map[i][j] != '3' && random < 5) {
            char c = rand() % 14 + 'A';
            write(village->fd, &c, 1);
        } else
            finish_display_struct(village, i, structure, j);
    }
    village->x = village->x_dist;
    structure->x = structure->x_dist;
    write(village->fd, "\n", 1);
    return 0;
}

int create_villages(int seed)
{
    create_village_t *village = malloc(sizeof(create_village_t));
    create_struct_t *strcture = malloc(sizeof(create_struct_t));
    village->fd = open("./map/villages.txt",
    O_WRONLY | O_CREAT | O_TRUNC, 0644);
    srand(seed);
    village->x_dist = rand() % 40 + 50;
    village->y_dist = rand() % 40 + 50;
    strcture->x_dist = rand() % 40 + 50;
    strcture->y_dist = rand() % 40 + 50;
    continue_init_village(village, strcture);
    village->village = rand() % 3 + '1';
    strcture->structure = rand() % 3 + '1';
    village->map = get_map_from_file("./map/map.txt");
    for (int i = 0; i < MAP_SIZE; i++) {
        create_village_two(village, i, strcture);
    }
    close(village->fd);
    free(village->map);
    free(village);
    return seed;
}
