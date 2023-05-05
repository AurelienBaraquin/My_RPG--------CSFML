/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** entity_direction
*/

#include "my.h"

int get_direction_between_entity(entity_t *entity1, entity_t *entity2)
{
    if (entity1 == NULL || entity2 == NULL)
        return (0);
    int x_diff = entity2->pos.x - entity1->pos.x;
    int y_diff = entity2->pos.y - entity1->pos.y;
    if (abs(x_diff) >= abs(y_diff)) {
        if (x_diff > 0) {
            return RIGHT;
        } else {
            return LEFT;
        }
    } else {
        if (y_diff > 0) {
            return DOWN;
        } else {
            return UP;
        }
    }
}

int get_direction_between_entity_and_pos(entity_t *entity, sfVector2f pos)
{
    if (entity == NULL)
        return 0;
    int x_diff = pos.x - entity->pos.x;
    int y_diff = pos.y - entity->pos.y;
    if (abs(x_diff) >= abs(y_diff)) {
        if (x_diff > 0) {
            return RIGHT;
        } else {
            return LEFT;
        }
    } else {
        if (y_diff > 0) {
            return DOWN;
        } else {
            return UP;
        }
    }
}

void set_entity_direction(entity_t *entity, int direction)
{
    if (direction < 0 || direction > 3)
        return;
    if (entity == NULL)
        return;
    entity->animations->frame_rect.top = direction *
    entity->animations->anim[entity->animations->animation_state].frame_size +
    entity->animations->anim[entity->animations->animation_state].pos.y;
}
