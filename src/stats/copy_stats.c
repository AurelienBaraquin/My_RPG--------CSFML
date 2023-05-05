/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** copy_stats
*/

#include "my.h"

stats_t* copy_stats(stats_t stats)
{
    stats_t *new_stats = malloc(sizeof(stats_t));
    new_stats->hp = stats.hp;
    new_stats->max_hp = stats.max_hp;
    new_stats->defense = stats.defense;
    new_stats->speed = stats.speed;
    new_stats->strength = stats.strength;
    new_stats->range = stats.range;
    return new_stats;
}

stats_t init_base_stats(void)
{
    stats_t stats;
    stats.hp = 100;
    stats.max_hp = 100;
    stats.defense = 10;
    stats.speed = 10;
    stats.strength = 10;
    stats.range = POS(2);
    return stats;
}

int get_stats_value(entity_t *entity, char *type)
{
    if (entity == NULL || type == NULL)
        return -1;
    if (my_strcmp(type, "hp") == 0)
        return entity->stats->hp;
    if (my_strcmp(type, "max_hp") == 0)
        return entity->stats->max_hp;
    if (my_strcmp(type, "defense") == 0)
        return entity->stats->defense;
    if (my_strcmp(type, "speed") == 0)
        return entity->stats->speed;
    if (my_strcmp(type, "strength") == 0)
        return entity->stats->strength;
    if (my_strcmp(type, "range") == 0)
        return entity->stats->range;
    return -1;
}
