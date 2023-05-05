/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** print_gui
*/

#include "my.h"

void draw_gui(sfRenderWindow *window, gui_t *gui,
entity_t *player, global_t *global)
{
    update_gui(gui, player, window, global);
    sfRenderWindow_drawRectangleShape(window, gui->max_hp, NULL);
    sfRenderWindow_drawRectangleShape(window, gui->hp, NULL);
    sfRenderWindow_drawRectangleShape(window, gui->xp_bar_max, NULL);
    sfRenderWindow_drawRectangleShape(window, gui->xp_bar, NULL);
    sfRenderWindow_drawText(window, gui->level_text, NULL);
    sfSprite_setScale(global->sprites[12]->sprite, (sfVector2f){0.2, 0.2});
    sfSprite_setPosition(global->sprites[12]->sprite,
    (sfVector2f){sfText_getPosition(gui->nb_potion).x,
    sfText_getPosition(gui->nb_potion).y - 30});
    sfRenderWindow_drawSprite(window, global->sprites[12]->sprite, NULL);
    sfSprite_setScale(global->sprites[12]->sprite, (sfVector2f){1, 1});
    sfRenderWindow_drawText(window, gui->nb_potion, NULL);
}
