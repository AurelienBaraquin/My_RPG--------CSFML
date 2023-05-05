/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** update_gui
*/

#include "my.h"

void update_gui_next(global_t *global, gui_t *gui, sfVector2f pos)
{
    sfRectangleShape_setPosition(gui->xp_bar,
    (sfVector2f){pos.x + 10, pos.y + 40});
    sfRectangleShape_setPosition(gui->xp_bar_max,
    (sfVector2f){pos.x + 10, pos.y + 40});
    sfRectangleShape_setSize(gui->xp_bar, (sfVector2f){gui->xp, 20});
    sfRectangleShape_setSize(gui->xp_bar_max, (sfVector2f){200, 20});
    char *lvl_txt = malloc(sizeof(char) * 20);
    lvl_txt = my_strcpy(lvl_txt, "LEVEL : ");
    CONCAT(lvl_txt, nb_to_str(gui->level));
    sfText_setString(gui->level_text, lvl_txt);
    sfText_setPosition(gui->level_text, (sfVector2f){pos.x + 30, pos.y + 40});
    free(lvl_txt);
    sfText_setString(gui->nb_potion,
    nb_to_str(get_nb_item_by_id(global->inv, 28)));
    sfText_setPosition(gui->nb_potion, (sfVector2f){pos.x + 30, pos.y + 70});
}

void update_gui(gui_t *gui, entity_t *player,
sfRenderWindow *window, global_t *global)
{
    sfView *view = sfRenderWindow_getView(window);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(window,
    (sfVector2i){0, 0}, view);
    sfRectangleShape_setPosition(gui->hp, (sfVector2f){pos.x + 10, pos.y + 10});
    sfRectangleShape_setPosition(gui->max_hp,
    (sfVector2f){pos.x + 10, pos.y + 10});
    sfRectangleShape_setSize(gui->hp,
    (sfVector2f){get_stats_value(player, "hp") * 2, 20});
    sfRectangleShape_setSize(gui->max_hp,
    (sfVector2f){get_stats_value(player, "max_hp") * 2, 20});
    if (gui->xp >= 200) {
        gui->xp = 0;
        gui->level++;
    }
    update_gui_next(global, gui, pos);
}
