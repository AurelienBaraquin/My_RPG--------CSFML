/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** get_rand_nb_rand_item
*/

#include "my.h"
#include "inventory.h"

int add_rand_nb_item_by_type(inv_t *inv, int nb, int type)
{
    for (int i = 0; i < nb; i++) {
        item_t *item = get_random_item_by_type(inv, type);
        if (item == NULL)
            return (0);
        add_inv(inv, item);
    }
    return (1);
}

int add_rand_nb_item_by_rarity(inv_t *inv, int nb, int rarity)
{
    for (int i = 0; i < nb; i++) {
        item_t *item = get_random_item_by_rarity(inv, rarity);
        if (item == NULL)
            return (0);
        add_inv(inv, item);
    }
    return (1);
}

int add_rand_nb_item_by_rarity_and_type(inv_t *inv,
int nb, int rarity, int type)
{
    for (int i = 0; i < nb; i++) {
        item_t *item = get_random_item_by_rarity_and_type(inv, rarity, type);
        if (item == NULL)
            return (0);
        add_inv(inv, item);
    }
    return (1);
}

int add_rand_nb_item_by_rarity_or_type(inv_t *inv, int nb, int rarity, int type)
{
    for (int i = 0; i < nb; i++) {
        item_t *item = get_random_item_by_rarity_or_type(inv, rarity, type);
        if (item == NULL)
            return (0);
        add_inv(inv, item);
    }
    return (1);
}
