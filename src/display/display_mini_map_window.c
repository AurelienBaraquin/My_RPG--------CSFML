/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** display_mini_map
*/

#include "my.h"

void update_mini_map(global_t *global)
{
    sfView_setCenter(global->view, (sfVector2f){
        MAP_SIZE * 32 / 2, MAP_SIZE * 32 / 2});
    sfView_setSize(global->view, (sfVector2f){MAP_SIZE * 32,
    MAP_SIZE * 32});
    sfView_setViewport(global->view, (sfFloatRect){0.25, 0.1, 0.5, 0.75});
    global->map->texture = sfRenderTexture_create(1920, 1080, sfFalse);
    sfRenderTexture_setView(global->map->texture, global->view);
    sfRenderTexture_clear(global->map->texture, sfWhite);
    sfRenderTexture_display(global->map->texture);
    draw_map_mini(global, MAP_SIZE);
    draw_mini_village(global, MAP_SIZE);
    global->map->sprite = sfSprite_create();
    sfSprite_setTexture(global->map->sprite,
        sfRenderTexture_getTexture(global->map->texture), sfTrue);
    sfSprite_setTextureRect(global->map->sprite, (sfIntRect)
    {480, 108, 960, 810});
}

void display_mini_map(global_t *global)
{
    sfView_setViewport(global->view, (sfFloatRect){0, 0, 1, 1});
    sfView_setSize(global->view, (sfVector2f){1920, 1080});
    sfView_setCenter(global->view, (sfVector2f){ 1920 / 2, 1080 / 2});
    sfRenderWindow_setView(global->window, global->view);
    sfRenderWindow_clear(global->window, sfBlack);
    sfSprite_setPosition(global->map->sprite, (sfVector2f){ 480, 108});
    sfRenderWindow_drawSprite(global->window, global->map->sprite, NULL);
    sfSprite_setPosition(global->map->flag, (sfVector2f){
        get_entity_by_id(global->entities, PLAYER)->pos.x / 33 + 480 - 30,
        get_entity_by_id(global->entities, PLAYER)->pos.y / 40 + 108 - 10 -
        sfSprite_getGlobalBounds(global->map->sprite).top / 2});
    sfRenderWindow_drawSprite(global->window, global->map->flag, NULL);
    sfRenderWindow_display(global->window);
}
