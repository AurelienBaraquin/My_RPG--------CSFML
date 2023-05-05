/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** entity_die
*/

#include "my.h"

void entity_loot(entity_t *entity, entity_list_t *entity_list, global_t *global)
{
    add_xp(global, entity->stats->max_hp / 10);
    if (mlrand(0, 2) == 0)
        global->entities->entity->stats->hp += 10;
    if (global->entities->entity->stats->max_hp <
    global->entities->entity->stats->hp)
        global->entities->entity->stats->hp =
        global->entities->entity->stats->max_hp;
    remove_entity(entity_list, entity->id);
}

void die_entity(entity_t *entity, entity_list_t *entity_list, global_t *global)
{
    if (entity == NULL)
        return;
    if (entity->stats->hp > 0)
        return;
    if (entity->type == PLAYER && get_max_frame_animation(entity) <=
    entity->animations->frame_rect.left) {
        entity->pos = (sfVector2f){POS(500), POS_Y(500)};
        entity->stats->hp = entity->stats->max_hp;
        change_animation_state(entity, IS_IDLE);
        return;
    }
    if (get_max_frame_animation(entity) <=
    entity->animations->frame_rect.left) {
        entity_loot(entity, entity_list, global);
    }
}

void die_entity_list(entity_list_t *entity_list, global_t *global)
{
    if (entity_list == NULL)
        return;
    entity_list_t *tmp = entity_list;
    while (tmp != NULL) {
        die_entity(tmp->entity, entity_list, global);
        tmp = tmp->next;
    }
}
