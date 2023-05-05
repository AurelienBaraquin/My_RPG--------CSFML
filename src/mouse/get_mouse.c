/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** get_mouse
*/

#include "my.h"

sfVector2f get_mouse_pos_f(sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_pos_f = {mouse_pos.x, mouse_pos.y};
    return mouse_pos_f;
}

sfVector2i get_mouse_pos_i(sfRenderWindow *window)
{
    sfView *view = sfRenderWindow_getView(window);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_pos_f = {mouse_pos.x, mouse_pos.y};
    if (view != NULL)
        mouse_pos_f = sfRenderWindow_mapPixelToCoords(window, mouse_pos, view);
    return (sfVector2i){mouse_pos_f.x, mouse_pos_f.y};
}

sfVector2i get_mouse_in_map(sfRenderWindow *window)
{
    sfVector2i pos = get_mouse_pos_i(window);
    return (sfVector2i){POS_REV(pos.x), POS_REV(pos.y)};
}

sfVector2f get_mouse_in_map_f(sfRenderWindow *window)
{
    sfVector2i pos = get_mouse_pos_i(window);
    return (sfVector2f){POS_REV(pos.x - 16), POS_REV(pos.y - 16)};
}
