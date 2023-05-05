/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** display_temple
*/

#include "my.h"

void display_temple(global_t *global)
{
    draw_sprite(global->sprites[TEMPLE], global->window);
    draw_sprite(global->sprites[CHEST], global->window);
}

void verif_templ(global_t *global)
{
    if (get_entity_pos(global->entities->entity).y > 0 &&
        global->map->colision[
            (int)get_entity_pos(global->entities->entity).y - 1][
                (int)get_entity_pos(global->entities->entity).x] == '3')
            enter_temple(global, get_entity_pos(global->entities->entity), 0);
}
