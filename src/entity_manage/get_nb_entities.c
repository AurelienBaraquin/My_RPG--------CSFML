/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** get_nb_entities
*/

#include "my.h"

int get_nb_entity(entity_list_t *entity_list)
{
    if (entity_list == NULL)
        return 0;
    entity_list_t *tmp = entity_list;
    int nb = 0;
    while (tmp != NULL) {
        nb++;
        tmp = tmp->next;
    }
    return nb;
}

int get_nb_entity_by_type(entity_list_t *entity_list, int type)
{
    if (entity_list == NULL)
        return 0;
    entity_list_t *tmp = entity_list;
    int nb = 0;
    while (tmp != NULL) {
        if (tmp->entity->type == type)
            nb++;
        tmp = tmp->next;
    }
    return nb;
}

int get_nb_entity_in_range(entity_list_t *entity_list,
sfVector2f pos, int range)
{
    if (entity_list == NULL)
        return 0;
    entity_list_t *tmp = entity_list;
    int nb = 0;
    while (tmp != NULL) {
        if (get_distance_between_entity_and_pos(tmp->entity, pos) <= range)
            nb++;
        tmp = tmp->next;
    }
    return nb;
}
