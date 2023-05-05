/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** create_colision_map
*/

#include "my.h"

void which_village_three(char **village_one, int *temp, int fd)
{
    for (int k = 0; k < VILLAGE_ONE_SIZE_X; k++) {
        if (village_one[temp[0]][k] == '1')
            write(fd, "1", 1);
        if (village_one[temp[0]][k] == '2')
            write(fd, "2", 1);
        if (village_one[temp[0]][k] == '3')
            write(fd, "3", 1);
        if (village_one[temp[0]][k] == '0')
            write(fd, "0", 1);
    }
}

int map_village_colision(int *temp, int j, int fd)
{
    if (temp[0] == -1){
        temp[0] = 0;
        temp[1] = j;
    }
    char **village_one = get_map_from_file("./map/village/village_one.txt");
    which_village_three(village_one, temp, fd);
    j += VILLAGE_ONE_SIZE_X - 1;
    temp[0] += 1;
    free(village_one);
    if (temp[0] == VILLAGE_ONE_SIZE_Y - 1){
        temp[0] = -1;
        temp[1] = -1;
    }
    return j;
}

int *map_y_generation(global_t *global, int fd, int i, int *temp)
{
    int a = 0;
    char *vil = global->map->village[i];
    for (int j = 0; j < MAP_SIZE; j++) {
        if (global->map->map[i][j] == '3'){ write(fd, "1", 1);
            continue;
        } if ((vil[j] == '1' || (temp[0] != -1 && j >= temp[1] && j < temp[1] +
            VILLAGE_ONE_SIZE_X))) { j = map_village_colision(temp, j, fd);
            continue;
        } if ((vil[j] == '2' || (temp[2] != -1 && j >= temp[3] && j < temp[3] +
            VILLAGE_TWO_SIZE_X))) { j = map_village_colision_two(temp, j, fd);
            continue;
        } if ((vil[j] == '3' || (temp[4] != -1 && j >= temp[5] && j < temp[5] +
        VILLAGE_THREE_SIZE_X))) { j = map_village_colision_three(temp, j, fd);
            continue;
        } if ((vil[j] == 't' || (temp[6] != -1 && j >= temp[7] && j < temp[7] +
            PYRAMID_SIZE_X))) { j = map_village_colision_four(temp, j, fd);
            continue;
        } if (vil[j] >= 'A' && vil[j] <= 'N'){
            write(fd, "1", 1); continue;
        } write(fd, "0", 1); } write(fd, "\n", 1); return temp;
}

int create_map_colision(global_t *global)
{
    int fd = open("./map/colision.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int *temp = malloc(sizeof(int) * 8);
    temp[0] = -1;
    temp[1] = -1;
    temp[2] = -1;
    temp[3] = -1;
    temp[4] = -1;
    temp[5] = -1;
    temp[6] = -1;
    temp[7] = -1;
    for (int i = 0; i < MAP_SIZE; i++) {
        temp = map_y_generation(global, fd, i, temp);
    }
    return 0;
}
