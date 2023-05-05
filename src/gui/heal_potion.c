/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** heal_potion
*/

#include "my.h"

void heal_potion(global_t *global)
{
    if (get_nb_item_by_id(global->inv, 28) <= 0)
        return;
    entity_t *player = get_entity_by_type(global->entities, PLAYER, 1);
    if (player->stats->hp < player->stats->max_hp) {
        player->stats->hp = player->stats->max_hp;
    }
    remove_inv(global->inv, get_item_by_id(global->inv, 28));
}
