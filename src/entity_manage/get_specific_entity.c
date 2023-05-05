/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** get_specific_entity
*/

#include "my.h"

entity_t* get_entity_by_id(entity_list_t *entity_list, int id)
{
    if (entity_list == NULL)
        return NULL;
    if (get_nb_entity(entity_list) <= 0 || get_nb_entity(entity_list) < id)
        return NULL;
    entity_list_t *tmp = entity_list;
    while (tmp != NULL) {
        if (tmp->entity->id == id)
            return tmp->entity;
        tmp = tmp->next;
    }
    return tmp->entity;
}

entity_t* get_entity_by_type(entity_list_t *entity_list, int type, int index)
{
    if (entity_list == NULL)
        return NULL;
    if (get_nb_entity(entity_list) <= 0)
        return NULL;
    entity_list_t *tmp = entity_list;
    int nb = 0;
    while (tmp != NULL) {
        if (tmp->entity->type == type)
            nb++;
        if (nb == index)
            return tmp->entity;
        tmp = tmp->next;
    }
    if (nb == 0)
        return NULL;
    return tmp->entity;
}

int get_id_of_entity(entity_list_t *entity_list, entity_t *entity)
{
    if (entity_list == NULL || entity == NULL)
        return -1;
    if (get_nb_entity(entity_list) <= 0)
        return -1;
    entity_list_t *tmp = entity_list;
    while (tmp != NULL) {
        if (tmp->entity == entity)
            return tmp->entity->id;
        tmp = tmp->next;
    }
    return -1;
}

entity_t* get_entity_by_sprite_type(entity_list_t
*entity_list, int type, int index)
{
    if (entity_list == NULL)
        return NULL;
    if (get_nb_entity(entity_list) <= 0)
        return NULL;
    entity_list_t *tmp = entity_list;
    int nb = 0;
    while (tmp != NULL) {
        if (tmp->entity->sprite->type == type)
            nb++;
        if (nb == index)
            return tmp->entity;
        tmp = tmp->next;
    }
    if (nb == 0)
        return NULL;
    return tmp->entity;
}

entity_t* get_locked_entity(entity_list_t *entity_list)
{
    if (entity_list == NULL)
        return NULL;
    if (get_nb_entity(entity_list) <= 0)
        return NULL;
    entity_list_t *tmp = entity_list;
    while (tmp != NULL) {
        if (tmp->entity->is_locked == true)
            return tmp->entity;
        tmp = tmp->next;
    }
    return NULL;
}
