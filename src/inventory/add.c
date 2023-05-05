/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** add_inv
*/

#include "inventory.h"

#include <stdio.h>

void add_inv(inv_t *inv, item_t *item)
{
    if (item == NULL) return;
    case_t *cases = inv->cases;
    for (int i = 0; i < INV_SIZE; i++) {
        if (cases[i].is_empty == true) {
            continue;
        }
        if (cases[i].item->id == item->id) {
            cases[i].nb += 1;
            return;
        }
    }
    for (int i = 0; i < INV_SIZE; i++) {
        if (cases[i].is_empty == true) {
            cases[i].is_empty = false;
            cases[i].item = item;
            cases[i].nb = 1;
            return;
        }
    }
}

void set_inv(case_t *c, item_t *item, int nb)
{
    if (nb >= INV_SIZE) {
        return;
    }
    c[nb].is_empty = false;
    c[nb].item = item;
}

void update_removed_item(inv_t *inv, int i)
{
    case_t *cases = inv->cases;
    if (cases[i].nb == 0) {
        cases[i].is_empty = true;
        cases[i].item = NULL;
        cases[i].nb = 0;
    }
}

void remove_inv(inv_t *inv, item_t *item)
{
    case_t *cases = inv->cases;
    for (int i = 0; i < INV_SIZE; i++) {
        if (cases[i].is_empty == true) {
            continue;
        }
        if (cases[i].item->id == item->id) {
            cases[i].nb -= 1;
            update_removed_item(inv, i);
            return;
        }
    }
}
