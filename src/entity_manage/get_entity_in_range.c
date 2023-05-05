/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** get_entity_in_range
*/

#include "my.h"

int get_entity_in_range(entity_list_t *entity_list, entity_t *entity, int range)
{
    if (entity == NULL || entity_list == NULL)
        return -1;
    if (get_nb_entity(entity_list) <= 0)
        return -1;
    entity_list_t *tmp = entity_list;
    while (tmp != NULL) {
        if (tmp->entity != entity &&
        get_distance_between_entity(entity, tmp->entity) <= range)
            return tmp->entity->id;
        tmp = tmp->next;
    }
    return -1;
}

int get_entity_in_range_by_type(entity_list_t *entity_list, entity_t
*entity, int range, int type)
{
    if (entity == NULL || entity_list == NULL)
        return -1;
    if (get_nb_entity(entity_list) <= 0)
        return -1;
    entity_list_t *tmp = entity_list;
    while (tmp != NULL) {
        if (tmp->entity != entity && tmp->entity->type == type &&
        get_distance_between_entity(entity, tmp->entity) <= range)
            return tmp->entity->id;
        tmp = tmp->next;
    }
    return -1;
}
