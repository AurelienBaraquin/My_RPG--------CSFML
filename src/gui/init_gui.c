/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** init_gui
*/

#include "my.h"

void init_gui_text(gui_t *gui)
{
    gui->level_text = sfText_create();
    sfText_setString(gui->level_text, "LEVEL : 1");
    sfText_setFont(gui->level_text, sfFont_createFromFile("assets/font.ttf"));
    sfText_setCharacterSize(gui->level_text, 15);
    sfText_setColor(gui->level_text, sfBlack);
    sfText_setPosition(gui->level_text, (sfVector2f){30, 40});
    gui->nb_potion = sfText_create();
    sfText_setString(gui->nb_potion, "0");
    sfText_setFont(gui->nb_potion, sfFont_createFromFile("assets/font.ttf"));
    sfText_setCharacterSize(gui->nb_potion, 15);
    sfText_setColor(gui->nb_potion, sfBlack);
    sfText_setPosition(gui->nb_potion, (sfVector2f){30, 70});
}

gui_t *init_gui(void)
{
    gui_t *gui = malloc(sizeof(gui_t));
    gui->xp = 0;
    gui->level = 1;
    gui->hp = sfRectangleShape_create();
    sfRectangleShape_setSize(gui->hp, (sfVector2f){200, 20});
    sfRectangleShape_setFillColor(gui->hp, sfGreen);
    gui->max_hp = sfRectangleShape_create();
    sfRectangleShape_setSize(gui->max_hp, (sfVector2f){200, 20});
    sfRectangleShape_setFillColor(gui->max_hp, sfRed);
    gui->xp_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(gui->xp_bar, (sfVector2f){200, 20});
    sfRectangleShape_setFillColor(gui->xp_bar, sfBlue);
    gui->xp_bar_max = sfRectangleShape_create();
    sfRectangleShape_setSize(gui->xp_bar_max, (sfVector2f){200, 20});
    sfRectangleShape_setFillColor(gui->xp_bar_max, sfYellow);
    init_gui_text(gui);
    return gui;
}
