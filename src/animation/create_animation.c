/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** create_animation
*/

#include "my.h"

animation_list_t *create_animation_list(sfIntRect frame_rect)
{
    sfVector2f zero = {0, 0};
    animation_list_t *animation_list = malloc(sizeof(animation_list_t));
    animation_list->frame_rect = frame_rect;
    animation_list->anim[IS_IDLE] = create_animation(-1, 0, zero);
    animation_list->anim[IS_WALK] = create_animation(-1, 0, zero);
    animation_list->anim[IS_ATTACK] = create_animation(-1, 0, zero);
    animation_list->anim[IS_DIE] = create_animation(-1, 0, zero);
    animation_list->animation_state = IS_IDLE;
    return animation_list;
}

animation_t create_animation(int min, int max, sfVector2f pos)
{
    animation_t animation;
    animation.min = min;
    animation.max = max;
    animation.pos = pos;
    animation.frame_size = 64;
    return animation;
}

void set_animation(entity_t *entity, sfVector2i max_framesize,
sfVector2f pos, int animation_type)
{
    if (entity == NULL)
        return;
    entity->animations->anim[animation_type].max = max_framesize.x;
    entity->animations->anim[animation_type].min = pos.x;
    entity->animations->anim[animation_type].pos = pos;
    entity->animations->anim[animation_type].frame_size = max_framesize.y;
    if (animation_type == IS_DIE)
        entity->animations->anim[animation_type].is_loop = sfFalse;
    else
        entity->animations->anim[animation_type].is_loop = sfTrue;
}

void set_animation_list(entity_t *entity)
{
    if (entity == NULL)
        return;
    entity->animations = create_animation_list(entity->sprite->rect);
}
