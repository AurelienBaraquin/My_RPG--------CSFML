/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** init_temple
*/

#include "my.h"

void init_temple(global_t *global)
{
    set_sprite_position(global->sprites[TEMPLE], (sfVector2f){POS_Y(3000), 0});
    set_sprite_position(global->sprites[CHEST],
    (sfVector2f){POS_Y(3000) + POS_Y(480), POS_Y(38)});
}
