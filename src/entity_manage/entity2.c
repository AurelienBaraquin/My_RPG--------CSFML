/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** entity2
*/

#include "my.h"

void move_entity(entity_t *entity, sfVector2f pos)
{
    if (pos.x == 0 && pos.y == 0)
        return;
    if (entity == NULL)
        return;
    entity->direction = get_direction_between_entity_and_pos(entity,
    (sfVector2f){entity->pos.x + pos.x, entity->pos.y + pos.y});
    entity->pos.x += pos.x;
    entity->pos.y += pos.y;
}

void unlock_all_entity(entity_list_t *entity_list)
{
    if (entity_list == NULL)
        return;
    entity_list_t *tmp = entity_list;
    while (tmp != NULL) {
        tmp->entity->is_locked = sfFalse;
        tmp = tmp->next;
    }
}

void lock_entity(entity_list_t *entity_list, int id)
{
    if (entity_list == NULL)
        return;
    entity_list_t *tmp = entity_list;
    while (tmp != NULL) {
        if (tmp->entity->id == id)
            tmp->entity->is_locked = sfTrue;
        tmp = tmp->next;
    }
}

int entity_is_character(entity_t *entity)
{
    if (entity == NULL)
        return 0;
    if (entity->type == PLAYER || entity->type == SKELETON)
        return 1;
    return 0;
}
