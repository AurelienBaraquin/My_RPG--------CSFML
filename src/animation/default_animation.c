/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** default_animation
*/

#include "my.h"

void default_player_animation(entity_t *entity)
{
    if (entity == NULL)
        return;
    entity->animations->animation_state = IS_IDLE;
    set_animation_list(entity);
    set_animation(entity, (sfVector2i){64 * 8, 64},
    (sfVector2f){0, 64 * 8}, IS_WALK);
    set_animation(entity, (sfVector2i){64 * 1, 64},
    (sfVector2f){0, 0}, IS_IDLE);
    set_animation(entity, (sfVector2i){64 * 5, 64},
    (sfVector2f){0, 64 * 18}, IS_DIE);
    set_animation(entity, (sfVector2i){64 * 9, 128},
    (sfVector2f){0, 64 * 29}, IS_ATTACK);
}

void default_hostile_entity_animation(entity_t *entity)
{
    if (entity == NULL)
        return;
    entity->animations->animation_state = IS_IDLE;
    set_animation_list(entity);
    set_animation(entity, (sfVector2i){64 * 8, 64},
    (sfVector2f){0, 64 * 8}, IS_WALK);
    set_animation(entity, (sfVector2i){64 * 1, 64},
    (sfVector2f){0, 0}, IS_IDLE);
    set_animation(entity, (sfVector2i){64 * 5, 64},
    (sfVector2f){0, 64 * 18}, IS_DIE);
    set_animation(entity, (sfVector2i){64 * 5, 64},
    (sfVector2f){0, 64 * 12}, IS_ATTACK);
}

void set_entity_animation_default(entity_t *entity)
{
    if (entity == NULL)
        return;
    entity->animations->animation_state = IS_IDLE;
    set_animation_list(entity);
    switch (entity->sprite->type) {
        case PLAYER:
            default_player_animation(entity);
            break;
        case SKELETON: case ZOMBIE: case ALIEN:
        case JACKOLANTERN: case ROBOT: case ORC:
            default_hostile_entity_animation(entity);
            break;
        case PIG:
            set_animation(entity, (sfVector2i){62 * 2, 62},
            (sfVector2f){0, 2}, IS_IDLE);
            break;
        default:
            break;
    }
}
