/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** display_window
*/

#include "my.h"

void display_window(global_t *global)
{
    sfView_setCenter(global->view, (sfVector2f){
        get_entity_by_id(global->entities, PLAYER)->pos.x,
        get_entity_by_id(global->entities, PLAYER)->pos.y});
    sfView_setSize(global->view, (sfVector2f){1920, 1080});
    sfView_setViewport(global->view, (sfFloatRect){0, 0, 1, 1});
    sfRenderWindow_setView(global->window, global->view);
    sfRenderWindow_clear(global->window, sfBlack);
    draw_map(global, 32);
    draw_village(global, 64);
    display_temple(global);
    draw_entity_list(global->entities, global->window);
    draw_gui(global->window, global->gui,
    get_entity_by_id(global->entities, PLAYER), global);
}
