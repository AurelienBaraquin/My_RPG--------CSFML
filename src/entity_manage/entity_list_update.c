/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** entity_list_update
*/

#include "my.h"

void update_entity_list_path(global_t *global)
{
    entity_list_t *tmp = global->entities;
    while (tmp != NULL) {
        if (get_entity_pos(global->entities->entity).x > 2900)
            update_entity_path(tmp->entity,
            global->map->temple_collision, global->entities->entity);
        else
            update_entity_path(tmp->entity,
            global->map->colision, global->entities->entity);
        tmp = tmp->next;
    }
}

void update_entity_list_deplacement(entity_list_t *entity_list, char **map)
{
    if (entity_list == NULL)
        return;
    entity_list_t *tmp = entity_list;
    while (tmp != NULL) {
        update_entity_deplacement(tmp->entity, map);
        tmp = tmp->next;
    }
}
