/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** get_item_multi_arg
*/

#include "my.h"
#include "inventory.h"

int get_nb_item_by_rarity_and_type(inv_t *inv, int rarity, int type)
{
    if (!inv || !inv->cases)
        return (0);
    int nb = 0;

    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (inv->cases[i].item && inv->cases[i].item->rarity == rarity
        && inv->cases[i].item->type == type)
            nb += inv->cases[i].nb;
    }
    return (nb);
}

int get_nb_item_by_rarity_or_type(inv_t *inv, int rarity, int type)
{
    if (!inv || !inv->cases)
        return (0);
    int nb = 0;

    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (!inv->cases[i].item)
            continue;
        if (inv->cases[i].item->rarity == rarity ||
        inv->cases[i].item->type == type)
            nb += inv->cases[i].nb;
    }
    return (nb);
}
