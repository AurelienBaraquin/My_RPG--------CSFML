/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** update_entity
*/

#include "my.h"

void update_sprite_of_lock(entity_t *entity, sfRenderWindow *window)
{
    sfRectangleShape_setPosition(entity->lock_rect,
    (sfVector2f){entity->pos.x + sfSprite_getLocalBounds(entity->
    sprite->sprite).width / 4, entity->pos.y +
    sfSprite_getLocalBounds(entity->sprite->sprite).height / 2 - 32});
    sfRenderWindow_drawRectangleShape(window, entity->lock_rect, NULL);
}

void draw_entity(entity_t *entity, sfRenderWindow *window)
{
    if (entity == NULL || window == NULL)
        return;
    sfSprite_setPosition(entity->sprite->sprite, (sfVector2f)
    {entity->pos.x - (entity->animations->anim[entity->animations->
    animation_state].frame_size - entity->sprite->rect.width) / 2,
    entity->pos.y - 32});
    sfSprite_setTextureRect(entity->sprite->sprite, (sfIntRect)
    {entity->animations->frame_rect.left, entity->animations->
    frame_rect.top, CURRENT_FRAME_SIZE, CURRENT_FRAME_SIZE});
    if (entity->type == PLAYER && entity->animations->animation_state
    == IS_ATTACK)
        sfSprite_setTextureRect(entity->sprite->sprite, (sfIntRect)
        {entity->animations->frame_rect.left, entity->animations->
        frame_rect.top + 32, CURRENT_FRAME_SIZE, CURRENT_FRAME_SIZE});
    if (entity->is_locked == sfTrue) {
        update_sprite_of_lock(entity, window);
    }
    sfRenderWindow_drawSprite(window, entity->sprite->sprite, NULL);
}

void update_entity_path(entity_t *entity, char **map, entity_t *player)
{
    if (entity->type == PLAYER)
        return;
    if (get_distance_between_entity(entity, player) > POS(30))
        return;
    if (get_entity_pos(entity).x > 2900)
        entity->deplacement = path_finding(map,
        (sfVector2f){get_entity_pos(entity).x - 3000, get_entity_pos(entity).y},
        (sfVector2f){get_entity_pos(player).x - 3000,
        get_entity_pos(player).y});
    else
        entity->deplacement = path_finding(map,
        (sfVector2f){get_entity_pos(entity).x, get_entity_pos(entity).y},
        (sfVector2f){get_entity_pos(player).x, get_entity_pos(player).y});
}

void verif_entity_pos(entity_t *entity)
{
    if ((int) entity->pos.x % 32 != 16)
        entity->pos.x = entity->pos.x - ((int) entity->pos.x % 32) - 16;
    if ((int) entity->pos.y % 32 != 0)
        entity->pos.y = entity->pos.y - ((int) entity->pos.y % 32);
}

void update_entity(entity_t *entity)
{
    if (entity == NULL)
        return;
    if (entity->stats->hp <= 0)
        entity->animations->animation_state = IS_DIE;
    if (entity->animations->animation_state == IS_DIE)
        entity->direction = DOWN;
    if (entity->type == PLAYER && entity->deplacement == NULL)
        verif_entity_pos(entity);
    set_entity_direction(entity, entity->direction);
    sfSprite_setPosition(entity->sprite->sprite, entity->pos);
    if (entity->is_locked == sfTrue)
        sfRectangleShape_setPosition(entity->lock_rect, entity->pos);
}
