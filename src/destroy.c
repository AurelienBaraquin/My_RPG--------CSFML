/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** destroy
*/

#include "my.h"

void destroy_map(map_t *map)
{
    for (int i = 0; i < MAP_SIZE - 1; i++){
        free(map->map[i]);
        free(map->colision[i]);
        free(map->village[i]);
    }
    free(map->map);
    sfRenderTexture_destroy(map->texture);
    sfSprite_destroy(map->sprite);
    sfTexture_destroy(map->flag_texture);
    sfSprite_destroy(map->flag);
    free(map);
    return;
}

void destroy_global(global_t *global)
{
    sfRenderWindow_destroy(global->window);
    destroy_map(global->map);
    return;
}
