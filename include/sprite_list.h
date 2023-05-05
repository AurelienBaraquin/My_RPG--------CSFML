/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** sprite_list
*/

#ifndef SPRITE_LIST_H_
    #define SPRITE_LIST_H_

    #include "my.h"

enum character_type {
    PLAYER,
    SKELETON,
};

    #define PLAYER 0
    #define SANDS_SEC 1
    #define SANDS_HUMID 2
    #define SANDS_ARID 3
    #define WATER 4
    #define VILLAGE_ONE 5
    #define VILLAGE_TWO 6
    #define VILLAGE_THREE 7
    #define SKELETON 8
    #define PIG 9
    #define PYRAMID 10
    #define ZOMBIE 11
    #define HEAL_POTION 12
    #define TEMPLE 13
    #define CACTUS_1 14
    #define CACTUS_2 15
    #define CACTUS_3 16
    #define CACTUS_4 17
    #define CACTUS_5 18
    #define CACTUS_6 19
    #define CACTUS_7 20
    #define CACTUS_8 21
    #define CACTUS_9 22
    #define CACTUS_10 23
    #define CACTUS_11 24
    #define CACTUS_12 25
    #define CACTUS_13 26
    #define CACTUS_14 27
    #define CHEST 28
    #define ALIEN 29
    #define JACKOLANTERN 30
    #define ROBOT 31
    #define ORC 32

typedef struct texture_element_s {
    char *filepath;
    sfIntRect rect;
} texture_element_t;

typedef struct sprite_s {
    sfSprite *sprite;
    sfIntRect rect;
    sfTexture *texture;
    sfVector2f base_pos;
    int type;
} sprite_t;

#endif /* !SPRITE_LIST_H_ */
