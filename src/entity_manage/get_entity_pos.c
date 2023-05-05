/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** get_entity_pos
*/

#include "my.h"

sfVector2f get_entity_pos(entity_t *entity)
{
    sfVector2f pos = {POS_REV(entity->pos.x), POS_REV_Y(entity->pos.y)};
    return (pos);
}
