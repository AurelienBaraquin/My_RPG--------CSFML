/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** colision_map_village
*/

#include "my.h"

void verif_which_village(char **village_three, int *temp, int fd)
{
    for (int k = 0; k < VILLAGE_THREE_SIZE_Y; k++) {
        if (village_three[temp[4]][k] == '1')
            write(fd, "1", 1);
        if (village_three[temp[4]][k] == '2')
            write(fd, "2", 1);
        if (village_three[temp[4]][k] == '3')
            write(fd, "3", 1);
        if (village_three[temp[4]][k] == '0')
            write(fd, "0", 1);
    }
}

int map_village_colision_three(int *temp, int j, int fd)
{
    if (temp[4] == -1){
        temp[4] = 0;
        temp[5] = j;
    }
    char **village_three =
        get_map_from_file("./map/village/village_three.txt");
    verif_which_village(village_three, temp, fd);
    j += VILLAGE_THREE_SIZE_Y - 1;
    temp[4] += 1;
    free(village_three);
    if (temp[4] == VILLAGE_THREE_SIZE_X - 1){
        temp[4] = -1;
        temp[5] = -1;
    }
    return j;
}

void verif_which_village_two(char **village_two, int *temp, int fd)
{
    for (int k = 0; k < VILLAGE_TWO_SIZE_Y; k++) {
        if (village_two[temp[2]][k] == '1')
            write(fd, "1", 1);
        if (village_two[temp[2]][k] == '2')
            write(fd, "2", 1);
        if (village_two[temp[2]][k] == '3')
            write(fd, "3", 1);
        if (village_two[temp[2]][k] == '0')
            write(fd, "0", 1);
    }
}

int map_village_colision_two(int *temp, int j, int fd)
{
    if (temp[2] == -1){
        temp[2] = 0;
        temp[3] = j;
    }
    char **village_two =
        get_map_from_file("./map/village/village_two.txt");
    verif_which_village_two(village_two, temp, fd);
    j += VILLAGE_TWO_SIZE_Y - 1;
    temp[2] += 1;
    free(village_two);
    if (temp[2] == VILLAGE_TWO_SIZE_X - 1){
        temp[2] = -1;
        temp[3] = -1;
    }
    return j;
}
