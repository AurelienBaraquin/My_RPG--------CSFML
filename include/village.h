/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** village
*/

#ifndef VILLAGE_H_
    #define VILLAGE_H_

    #include "my.h"

    #define VILLAGE_ONE_SIZE_X 33
    #define VILLAGE_ONE_SIZE_Y 33
    #define VILLAGE_THREE_SIZE_X 25
    #define VILLAGE_THREE_SIZE_Y 25
    #define VILLAGE_TWO_SIZE_X 20
    #define VILLAGE_TWO_SIZE_Y 20
    #define PYRAMID_SIZE_X 12
    #define PYRAMID_SIZE_Y 12

typedef struct village {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
} village_t;

typedef struct create_village {
    int fd;
    int size;
    int x_dist;
    int y_dist;
    int x;
    int y;
    char village;
    char **map;
} create_village_t;

#endif /* !VILLAGE_H_ */
