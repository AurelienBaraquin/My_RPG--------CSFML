/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** entity
*/

#include "my.h"

void add_entity(entity_list_t *entity_list, entity_t *entity)
{
    if (entity == NULL || entity_list == NULL)
        return;
    if (get_nb_entity(entity_list) > 50)
        return;
    entity_list_t *new = malloc(sizeof(entity_list_t));
    entity_list_t *tmp = entity_list;
    new->entity = entity;
    new->next = NULL;
    if (entity_list->entity == NULL) {
        entity_list->entity = entity;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}

sfRectangleShape* create_entity_lock_rect(entity_t *entity,
sfFloatRect rect, sfVector2f pos)
{
    sfRectangleShape *new = sfRectangleShape_create();
    sfRectangleShape_setSize(new,
    (sfVector2f){rect.width, rect.height});
    sfRectangleShape_setPosition(new, (sfVector2f){pos.x, pos.y + rect.height});
    sfRectangleShape_setFillColor(new, sfTransparent);
    sfRectangleShape_setOutlineColor(new, sfRed);
    sfRectangleShape_setOutlineThickness(new, 2);
    return new;
}

entity_t* create_entity(sfVector2f pos, sprite_t *sprite,
stats_t stats, int type)
{
    entity_t *entity = malloc(sizeof(entity_t));
    entity->pos = pos;
    sfSprite_setPosition(sprite->sprite, pos);
    entity->sprite = sprite;
    entity->stats = copy_stats(stats);
    entity->type = type;
    entity->direction = DOWN;
    entity->is_locked = sfFalse;
    entity->deplacement = NULL;
    entity->animations = create_animation_list(entity->sprite->rect);
    sfFloatRect rect = sfSprite_getLocalBounds(sprite->sprite);
    rect = (sfFloatRect){rect.left, rect.top, rect.width / 2, rect.height / 2};
    entity->lock_rect = create_entity_lock_rect(entity, rect, pos);
    set_entity_animation_default(entity);
    static int id = 0;
    entity->id = id;
    id++;
    return entity;
}

void destroy_entity(entity_t *entity)
{
    if (entity == NULL)
        return;
    free(entity->stats);
    free(entity);
}
