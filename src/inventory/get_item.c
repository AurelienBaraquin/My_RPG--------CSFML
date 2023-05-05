/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** get_item
*/

#include "my.h"
#include "inventory.h"

item_t *get_item_by_id(inv_t *inv, int id)
{
    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (inv->cases[i].item && inv->cases[i].item->id == id)
            return (inv->cases[i].item);
    }
    return (NULL);
}

item_t *get_item_by_name(inv_t *inv, char *name)
{
    if (!inv || !inv->cases || !inv->cases[0].item)
        return (NULL);
    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (inv->cases[i].item && my_strcmp
        (inv->cases[i].item->name, name) == 0)
            return (inv->cases[i].item);
    }
    return (NULL);
}

item_t *get_item_by_rarity(inv_t *inv, int rarity)
{
    if (!inv || !inv->cases || !inv->cases[0].item)
        return (NULL);
    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (inv->cases[i].item && inv->cases[i].item->rarity == rarity)
            return (inv->cases[i].item);
    }
    return (NULL);
}

item_t *get_item_by_type(inv_t *inv, int type)
{
    if (!inv || !inv->cases || !inv->cases[0].item)
        return (NULL);
    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (inv->cases[i].item && inv->cases[i].item->type == type)
            return (inv->cases[i].item);
    }
    return (NULL);
}

item_t *get_item_by_rarity_and_type(inv_t *inv, int rarity, int type)
{
    if (!inv || !inv->cases || !inv->cases[0].item)
        return (NULL);
    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (inv->cases[i].item && inv->cases[i].item->rarity == rarity
        && inv->cases[i].item->type == type)
            return (inv->cases[i].item);
    }
    return (NULL);
}
