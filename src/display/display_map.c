/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** display_map
*/

#include "my.h"

void draw_map_tyle(global_t *global, int pos_x, int pos_y)
{
    sfSprite_setPosition(global->sprites[get_sand_type(
        global->map->map[pos_y][pos_x])]->sprite,
        (sfVector2f){pos_x * 32, pos_y * 32});
    sfRenderWindow_drawSprite(global->window,
    global->sprites[
        get_sand_type(global->map->map[pos_y][pos_x])]->sprite, NULL);
}

void draw_map(global_t *global, int size)
{
    entity_t *player = get_entity_by_type(global->entities, PLAYER, 1);
    int i = player->pos.y / 32 - size;
    int j = player->pos.x / 32 - size;
    if (i < 0)
        i = 0;
    for (; i < global->map->size && i <= player->pos.y / 32 + size; i++) {
        j = player->pos.x / 32 - size;
        if (j < 0)
            j = 0;
        for (; j < global->map->size && j <= player->pos.x / 32 + size; j++) {
            draw_map_tyle(global, j, i);
        }
    }
}

void draw_village_sprite(char c, global_t *global, int pos_x, int pos_y)
{
    if (c >= '1' && c != 't' && (c < 'A' || c > 'N')) {
        sfSprite_setPosition(global->sprites[get_village_type(c)]->sprite,
        (sfVector2f){pos_x * 32, pos_y * 32});
        sfRenderWindow_drawSprite(global->window, global->sprites
        [get_village_type(c)]->sprite, NULL);
    }
    if (c == 't'){
        sfSprite_setPosition(global->sprites[PYRAMID]->sprite,
        (sfVector2f){pos_x * 32, pos_y * 32});
        sfRenderWindow_drawSprite(global->window, global->sprites
        [PYRAMID]->sprite, NULL);
    }
    if (c >= 'A' && c <= 'N'){
        sfSprite_setPosition(global->sprites[get_cactus_type(c)]->sprite,
        (sfVector2f){pos_x * 32, pos_y * 32});
        sfRenderWindow_drawSprite(global->window, global->sprites
        [get_cactus_type(c)]->sprite, NULL);
    }
}

void draw_village(global_t *global, int size)
{
    entity_t *player = get_entity_by_type(global->entities, PLAYER, 1);
    int i = player->pos.y / 32 - size;
    int j = player->pos.x / 32 - size;
    if (i < 0)
        i = 0;
    for (; i < global->map->size && i <= player->pos.y / 32 + size; i++) {
        j = player->pos.x / 32 - size;
        if (j < 0)
            j = 0;
        for (; j < global->map->size && j <= player->pos.x / 32 + size; j++) {
            draw_village_sprite(global->map->village[i][j], global, j, i);
        }
    }
}
