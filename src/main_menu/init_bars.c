/*
** EPITECH PROJECT, 2023
** init_bars
** File description:
** Menu RPG
*/

#include "menu.h"

void init_exit_bar(menu_t *all)
{
    BAR[3].shape = sfRectangleShape_create();
    BAR[3].size = (sfVector2f) {400, 80};
    BAR[3].position = (sfVector2f) {760, 660};
    BAR[3].color = sfBlack;
    BAR[3].is_clicked = 0;
    sfRectangleShape_setSize(BAR[3].shape, BAR[3].size);
    sfRectangleShape_setPosition(BAR[3].shape, BAR[3].position);
    sfRectangleShape_setFillColor(BAR[3].shape, BAR[3].color);
    BAR[3].font = sfFont_createFromFile("./src/main_menu/photos/font.TTF");
    BAR[3].text = sfText_create();
    sfText_setString(BAR[3].text, "EXIT");
    sfText_setFont(BAR[3].text, BAR[3].font);
    BAR[3].pos_text = (sfVector2f){910, 675};
    sfText_setColor(BAR[3].text, sfWhite);
    sfText_setCharacterSize(BAR[3].text, 40);
    sfText_setPosition(BAR[3].text, BAR[3].pos_text);
}

void init_settings_bar(menu_t *all)
{
    BAR[2].shape = sfRectangleShape_create();
    BAR[2].size = (sfVector2f) {400, 80};
    BAR[2].position = (sfVector2f) {760, 530};
    BAR[2].color = sfBlack;
    BAR[2].is_clicked = 0;
    sfRectangleShape_setSize(BAR[2].shape, BAR[2].size);
    sfRectangleShape_setPosition(BAR[2].shape, BAR[2].position);
    sfRectangleShape_setFillColor(BAR[2].shape, BAR[2].color);
    BAR[2].font = sfFont_createFromFile("./src/main_menu/photos/font.TTF");
    BAR[2].text = sfText_create();
    sfText_setString(BAR[2].text, "SETTINGS");
    sfText_setFont(BAR[2].text, BAR[2].font);
    BAR[2].pos_text = (sfVector2f){860, 550};
    sfText_setColor(BAR[2].text, sfWhite);
    sfText_setCharacterSize(BAR[2].text, 35);
    sfText_setPosition(BAR[2].text, BAR[2].pos_text);
}

void init_resume_bar(menu_t *all)
{
    BAR[1].shape = sfRectangleShape_create();
    BAR[1].size = (sfVector2f) {400, 80};
    BAR[1].position = (sfVector2f) {760, 400};
    BAR[1].color = sfBlack;
    BAR[1].is_clicked = 0;
    sfRectangleShape_setSize(BAR[1].shape, BAR[1].size);
    sfRectangleShape_setPosition(BAR[1].shape, BAR[1].position);
    sfRectangleShape_setFillColor(BAR[1].shape, BAR[1].color);
    BAR[1].font = sfFont_createFromFile("./src/main_menu/photos/font.TTF");
    BAR[1].text = sfText_create();
    sfText_setString(BAR[1].text, "RESUME");
    sfText_setFont(BAR[1].text, BAR[1].font);
    BAR[1].pos_text = (sfVector2f){880, 420};
    sfText_setColor(BAR[1].text, sfWhite);
    sfText_setCharacterSize(BAR[1].text, 35);
    sfText_setPosition(BAR[1].text, BAR[1].pos_text);
}

void init_start_bar(menu_t *all)
{
    BAR[0].shape = sfRectangleShape_create();
    BAR[0].size = (sfVector2f) {400, 80};
    BAR[0].position = (sfVector2f) {760, 270};
    BAR[0].color = sfBlack;
    BAR[0].is_clicked = 0;
    sfRectangleShape_setSize(BAR[0].shape, BAR[0].size);
    sfRectangleShape_setPosition(BAR[0].shape, BAR[0].position);
    sfRectangleShape_setFillColor(BAR[0].shape, BAR[0].color);
    BAR[0].font = sfFont_createFromFile("./src/main_menu/photos/font.TTF");
    BAR[0].text = sfText_create();
    sfText_setString(BAR[0].text, "START");
    sfText_setFont(BAR[0].text, BAR[0].font);
    BAR[0].pos_text = (sfVector2f){880, 290};
    sfText_setColor(BAR[0].text, sfWhite);
    sfText_setCharacterSize(BAR[0].text, 35);
    sfText_setPosition(BAR[0].text, BAR[0].pos_text);
}

void init_bars(menu_t *all)
{
    BAR = malloc(sizeof(bar_t) * 4);
    init_start_bar(all);
    init_resume_bar(all);
    init_settings_bar(all);
    init_exit_bar(all);
    init_settings_bars(all);
}
