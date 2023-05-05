/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** inventory
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#include "inventory.h"
#include "item.h"

void init(inv_t *inv);

bool case_hover(sfVector2f pos, sfVector2f size, sfVector2i mouse)
{
    if (mouse.x < pos.x)
        return false;
    if (mouse.x > pos.x + size.x)
        return false;
    if (mouse.y < pos.y)
        return false;
    if (mouse.y > pos.y + size.y)
        return false;
    return true;
}

void set_func(inv_t *inv)
{
    inv->add = &add_inv;
    inv->check = &check_inv;
}

static void init_case(case_t *ca, int i)
{
    ca->is_empty = true;
    ca->item = NULL;
    ca->pos = (sfVector2f) {1140 + (70 * (i % 11)), 690 + (85 * (i / 11))};
    ca->size = (sfVector2f) {65, 80};
    ca->is_hover = &case_hover;
}

static void init_equip(case_t *ca, int i)
{
    ca->is_empty = true;
    ca->item = NULL;
    ca->is_hover = &case_hover;
    ca->size = (sfVector2f) {100, 100};
    if (i < 38) {
        ca->pos = (sfVector2f) {1150, 45 + 130 * (i % 33)};
    } else {
        ca->pos = (sfVector2f) {1510 + 100, 20 + 100 * (i % 38)};
    }
}

inv_t *init_inv(void)
{
    inv_t *inv = malloc(sizeof(inv_t));
    for (int i = 0; i < INV_SIZE; i++) {
        if (i < 33)
            init_case(&inv->cases[i], i);
        else
            init_equip(&inv->cases[i], i);
    }
    inv->curr = malloc(sizeof(curr_t));
    inv->curr->prev = -1;
    inv->curr->curr->item = NULL;
    inv->curr->curr->state = 0;
    inv->curr->curr->nb = 0;
    inv->curr->curr->pos = (sfVector2f) {0, 0};
    inv->curr->curr->size = (sfVector2f) {0, 0};
    inv->curr->curr->is_hover = NULL;
    inv->state = CLOSE;
    inv->curr->curr->is_empty = true;
    set_func(inv);
    init(inv);
    return inv;
}
