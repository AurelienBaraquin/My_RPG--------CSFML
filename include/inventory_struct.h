/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** inventory
*/

#ifndef INVENTORY_STRUCT_H_
    #define INVENTORY_STRUCT_H_

    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include "item.h"

    #define INV_SIZE 40

typedef enum {
    CLOSE,
    OPEN,
    HOVER,
    HOLD,
    PRESS,
    REAL,
    RIGHT_CLICK,
    LEFT_CLICK,
    DROP,
} INV_STATE;

typedef struct case_s {
    bool is_empty;
    item_t *item;
    ssize_t nb;
    sfVector2f pos;
    sfVector2f size;
    bool (*is_hover)(sfVector2f pos, sfVector2f size, sfVector2i mouse);
    INV_STATE state;
} case_t;

typedef struct curr_s {
    case_t curr[1];
    int prev;
} curr_t;

typedef struct inv_s inv_t;
typedef struct inv_s {
    INV_STATE state;
    case_t cases[INV_SIZE];
    curr_t *curr;
    sfText *text;
    sfVector2f base;
    sfRectangleShape *back;
    void (*add)(inv_t *inv, item_t *item);
    void (*toggle)(inv_t *inv);
    void (*display)(inv_t *inv, sfRenderWindow *window);
    void (*check)(inv_t *inv, sfRenderWindow *window);
} inv_t;

#endif /* INVENTORY_STRCUT_H */
