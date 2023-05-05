/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** colision_map_temple
*/

#include "my.h"

void verif_which_village_temple(char **village_four, int *temp, int fd)
{
    for (int k = 0; k < PYRAMID_SIZE_X; k++) {
        if (village_four[temp[6]][k] == '1')
            write(fd, "1", 1);
        if (village_four[temp[6]][k] == '2')
            write(fd, "2", 1);
        if (village_four[temp[6]][k] == '3')
            write(fd, "3", 1);
        if (village_four[temp[6]][k] == '0')
            write(fd, "0", 1);
    }
}

int map_village_colision_four(int *temp, int j, int fd)
{
    if (temp[6] == -1){
        temp[6] = 0;
        temp[7] = j;
    }
    char **village_four =
        get_map_from_file("./map/village/pyramid.txt");
    verif_which_village_temple(village_four, temp, fd);
    j += PYRAMID_SIZE_Y - 1;
    temp[6] += 1;
    free(village_four);
    if (temp[6] == PYRAMID_SIZE_Y - 1){
        temp[6] = -1;
        temp[7] = -1;
    }
    return j;
}
