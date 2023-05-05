/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** get_item
*/

#include "my.h"
#include "inventory.h"

int get_nb_items_by_rarity(inv_t *inv, int rarity)
{
    if (!inv || !inv->cases)
        return (0);
    int nb = 0;

    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (inv->cases[i].item && inv->cases[i].item->rarity == rarity)
            nb += inv->cases[i].nb;
    }
    return (nb);
}

int get_nb_item_by_type(inv_t *inv, int type)
{
    if (!inv || !inv->cases)
        return (0);
    int nb = 0;

    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (inv->cases[i].item && inv->cases[i].item->type == type)
            nb += inv->cases[i].nb;
    }
    return nb;
}

int get_nb_item_by_id(inv_t *inv, int id)
{
    if (!inv || !inv->cases)
        return (0);
    int nb = 0;

    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (inv->cases[i].item && inv->cases[i].item->id == id)
            nb += inv->cases[i].nb;
    }
    return nb;
}

int get_nb_item_by_name(inv_t *inv, char *name)
{
    if (!inv || !inv->cases)
        return (0);
    int nb = 0;

    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (inv->cases[i].item && my_strcmp
        (inv->cases[i].item->name, name) == 0)
            nb += inv->cases[i].nb;
    }
    return (nb);
}
