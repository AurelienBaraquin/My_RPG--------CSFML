/*
** EPITECH PROJECT, 2023
** inventory
** File description:
** check
*/

#include "inventory.h"
#include <SFML/Graphics.h>
#include <stdio.h>

void set_inv(case_t *c, item_t *item, int nb);

void switch_item(inv_t *inv, int i, bool from)
{
    if (from) {
        if (inv->cases[i].item == NULL)
            return;
        inv->curr->curr[0].item = inv->cases[i].item;
        inv->curr->curr[0].nb = inv->cases[i].nb;
        inv->curr->prev = i;
        inv->cases[i].is_empty = true;
        inv->curr->curr[0].is_empty = false;
        inv->cases[i].item = NULL;
    } else {
        if (inv->cases[i].item != NULL)
            return;
        inv->cases[i].item = inv->curr->curr[0].item;
        inv->cases[i].nb = inv->curr->curr[0].nb;
        inv->curr->prev = -1;
        inv->curr->curr[0].is_empty = true;
        inv->cases[i].is_empty = false;
        inv->curr->curr->item = NULL;
    }
}

void check_inv(inv_t *inv, sfRenderWindow *window)
{
    sfVector2i mouse = {0, 0};
    if (inv->state == CLOSE) {
        return;
    }
    mouse = sfMouse_getPositionRenderWindow(window);
    for (int i = 0; i < INV_SIZE; i++) {
        inv->cases[i].state = inv->cases[i].is_hover(inv->cases[i].pos,
            inv->cases[i].size, mouse) ? HOVER : OPEN;
    }
    for (int i = 0; i < INV_SIZE; i++) {
        if (inv->cases[i].state == HOVER && inv->state == PRESS) {
            switch_item(inv, i, inv->curr->curr->is_empty);
            inv->state = OPEN;
        }
    }
}
