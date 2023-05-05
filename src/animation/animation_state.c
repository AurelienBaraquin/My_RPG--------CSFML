/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** animation_state
*/

#include "my.h"

void change_animation_state(entity_t *entity, int ANI_S)
{
    if (entity == NULL)
        return;
    update_animation_list(ENT_A, ANI_S);
}

void get_animation_state(entity_t *entity)
{
    if (entity == NULL)
        return;
    if (ENT_A->ANI_S == IS_DIE || ENT_A->ANI_S == IS_ATTACK)
        return;
    if (entity->deplacement == NULL)
        change_animation_state(entity, IS_IDLE);
    else
        change_animation_state(entity, IS_WALK);
}

void update_animation_state_list(entity_list_t *entity_list)
{
    if (entity_list == NULL)
        return;
    entity_list_t *tmp = entity_list;
    while (tmp != NULL) {
        get_animation_state(tmp->entity);
        tmp = tmp->next;
    }
}
