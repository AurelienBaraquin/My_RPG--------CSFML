/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** entity_distance
*/

#include "my.h"

int get_distance_between_entity(entity_t *entity1, entity_t *entity2)
{
    if (entity1 == NULL || entity2 == NULL)
        return (0);
    int x = entity1->pos.x - entity2->pos.x;
    int y = entity1->pos.y - entity2->pos.y;
    return sqrt(pow(x, 2) + pow(y, 2));
}

int get_distance_between_entity_and_pos(entity_t *entity, sfVector2f pos)
{
    if (entity == NULL)
        return (0);
    int x = entity->pos.x - pos.x;
    int y = entity->pos.y - pos.y;
    return sqrt(pow(x, 2) + pow(y, 2));
}

int get_distance_between_pos(sfVector2f pos1, sfVector2f pos2)
{
    int x = pos1.x - pos2.x;
    int y = pos1.y - pos2.y;
    return sqrt(pow(x, 2) + pow(y, 2));
}
