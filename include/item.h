/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** item
*/

#ifndef ITEM_H
    #define ITEM_H

    #include <sys/types.h>
    #include <SFML/Graphics.h>

    // #define LCOMMON 15
    // #define LRARE 6
    // #define LEPIC 3
    // #define LLEGENDARY 2

typedef enum {
    NONE_RARE,
    COMMON,
    RARE,
    EPIC,
    LEGENDARY
} RARITY;

typedef enum {
    NONE_TYPE,
    CONSUMABLE,
    WEAPON,
    ARMOR,
    MISC
} TYPE;

typedef struct item_s {
    ssize_t id;
    char *name;
    ssize_t price;
    TYPE type;
    RARITY rarity;
    char *path;
    const sfIntRect rect;
    int stat;
} item_t;

#endif /* !ITEM_H */
