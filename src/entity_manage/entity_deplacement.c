/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** entity_deplacement
*/

#include "my.h"

void update_entity_deplacement(entity_t *entity, char **map)
{
    if (entity == NULL)
        return;
    if (entity->deplacement == NULL)
        return;
    if (entity->deplacement->frame >= 32 / entity->stats->speed) {
        move_entity(entity, get_coord_from_direction
        (entity->deplacement->direction, 32 % entity->stats->speed));
        sfMusic_play(sfMusic_createFromFile("assets/marche.m4a"));
        remove_first_deplacement(entity);
    } else {
        entity->deplacement->frame += 1;
        move_entity(entity, get_coord_from_direction
        (entity->deplacement->direction, entity->stats->speed));
    }
}

void add_deplacement(entity_t *entity, int direction)
{
    if (entity == NULL)
        return;
    if (direction < 0 || direction > 3)
        return;
    deplacement_t *new_deplacement = malloc(sizeof(deplacement_t));
    new_deplacement->direction = direction;
    new_deplacement->frame = 0;
    new_deplacement->next = NULL;
    if (entity->deplacement == NULL) {
        entity->deplacement = new_deplacement;
        return;
    }
    deplacement_t *tmp = entity->deplacement;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new_deplacement;
}

void remove_first_deplacement(entity_t *entity)
{
    if (entity->deplacement == NULL)
        return;
    deplacement_t *tmp = entity->deplacement;
    entity->deplacement = entity->deplacement->next;
    free(tmp);
}

void fusion_deplacement(entity_t *entity, deplacement_t *deplacement)
{
    if (entity == NULL)
        return;
    if (deplacement == NULL)
        return;
    if (entity->deplacement == NULL) {
        entity->deplacement = deplacement;
        return;
    }
    entity->deplacement->next = deplacement;
}

void remove_last_deplacement(entity_t *entity)
{
    if (entity == NULL)
        return;
    if (entity->deplacement == NULL)
        return;
    if (entity->deplacement->next == NULL) {
        return;
    }
    deplacement_t *tmp = entity->deplacement;
    deplacement_t *tmp2 = entity->deplacement;
    while (tmp->next != NULL) {
        tmp2 = tmp;
        tmp = tmp->next;
    }
    tmp2->next = NULL;
    free(tmp);
}
