/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** player
*/

#include "my.h"

entity_list_t* init_entity_list(void)
{
    entity_list_t *entity_list = malloc(sizeof(entity_list_t));
    entity_list->entity = NULL;
    entity_list->next = NULL;
    return entity_list;
}

void destroy_entity_list(entity_list_t *entity_list)
{
    if (entity_list == NULL)
        return;
    entity_list_t *tmp = entity_list;
    entity_list_t *tmp2 = entity_list;
    while (tmp != NULL) {
        tmp2 = tmp->next;
        destroy_entity(tmp->entity);
        free(tmp);
        tmp = tmp2;
    }
}

void draw_entity_list(entity_list_t *entity_list, sfRenderWindow *window)
{
    if (entity_list == NULL || window == NULL)
        return;
    entity_list_t *tmp = entity_list;
    while (tmp != NULL) {
        draw_entity(tmp->entity, window);
        tmp = tmp->next;
    }
}

void remove_entity(entity_list_t *entity_list, int id)
{
    if (id <= 0)
        return;
    if (entity_list == NULL)
        return;
    entity_list_t *tmp = entity_list;
    entity_list_t *tmp2 = entity_list;
    while (tmp != NULL) {
        if (tmp->entity->id == id) {
            tmp2->next = tmp->next;
            destroy_entity(tmp->entity);
            return;
        }
        tmp2 = tmp;
        tmp = tmp->next;
    }
}

void update_entity_list(entity_list_t *entity_list, global_t *global)
{
    if (entity_list == NULL)
        return;
    entity_list_t *tmp = entity_list;
    while (tmp != NULL) {
        update_entity(tmp->entity);
        tmp = tmp->next;
    }
    die_entity_list(entity_list, global);
}
