/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** entity_animation
*/

#include "my.h"

void next_frame_entity_list_animation(entity_list_t *entity_list)
{
    if (entity_list == NULL)
        return;
    entity_list_t *tmp = entity_list;
    while (tmp != NULL) {
        next_frame_entity_animation(tmp->entity);
        tmp = tmp->next;
    }
}

int get_max_frame_animation(entity_t *entity)
{
    if (entity == NULL)
        return -1;
    if (ENT_A == NULL || ENT_A->ANI_S < 0 || ENT_A->ANI_S > 3)
        return -1;
    if (ENT_A->anim[ENT_A->ANI_S].min == -1)
        return -1;
    if (ENT_A->anim[ENT_A->ANI_S].frame_size == 0)
        return -1;
    return ENT_A->anim[ENT_A->ANI_S].max - ENT_A->anim[ENT_A->ANI_S].min;
}

void next_frame_entity_animation(entity_t *entity)
{
    if (entity == NULL)
        return;
    if (ENT_A->ANI_S < 0 || ENT_A->ANI_S > 3)
        return;
    if (ENT_A->anim[ENT_A->ANI_S].min == -1)
        return;
    if (ENT_A->frame_rect.left >= get_max_frame_animation(entity)) {
        if (ENT_A->ANI_S == IS_ATTACK)
            change_animation_state(entity, IS_IDLE);
        if (ENT_A->anim[ENT_A->ANI_S].is_loop == sfFalse)
            return;
        else
            ENT_A->frame_rect.left = ENT_A->anim[ENT_A->ANI_S].min;
    } else {
        ENT_A->frame_rect.left += ENT_A->anim[ENT_A->ANI_S].frame_size;
    }
}

void update_animation_list(animation_list_t *animation_list, int ANI_S)
{
    if (animation_list == NULL)
        return;
    if (animation_list->ANI_S == ANI_S)
        return;
    animation_list->ANI_S = ANI_S;
    animation_list->frame_rect.left = animation_list->anim[ANI_S].min;
    animation_list->frame_rect.top = animation_list->anim[ANI_S].pos.y;
}
