/*
** EPITECH PROJECT, 2023
** init_sets_SET.c
** File description:
** Menu settings RPG
*/

#include "menu.h"

void init_volume_up_bar(menu_t *all)
{
    SET[3].shape = sfRectangleShape_create();
    SET[3].size = (sfVector2f) {150, 80};
    SET[3].position = (sfVector2f) {1170, 400};
    SET[3].color = sfBlack;
    SET[3].is_clicked = 0;
    sfRectangleShape_setSize(SET[3].shape, SET[3].size);
    sfRectangleShape_setPosition(SET[3].shape, SET[3].position);
    sfRectangleShape_setFillColor(SET[3].shape, SET[3].color);
    SET[3].font = sfFont_createFromFile("./src/main_menu/photos/font.TTF");
    SET[3].text = sfText_create();
    sfText_setString(SET[3].text, "UP");
    sfText_setFont(SET[3].text, SET[3].font);
    SET[3].pos_text = (sfVector2f){1220, 420};
    sfText_setColor(SET[3].text, sfWhite);
    sfText_setCharacterSize(SET[3].text, 35);
    sfText_setPosition(SET[3].text, SET[3].pos_text);
}

void init_volume_down_bar(menu_t *all)
{
    SET[2].shape = sfRectangleShape_create();
    SET[2].size = (sfVector2f) {150, 80};
    SET[2].position = (sfVector2f) {600, 400};
    SET[2].color = sfBlack;
    SET[2].is_clicked = 0;
    sfRectangleShape_setSize(SET[2].shape, SET[2].size);
    sfRectangleShape_setPosition(SET[2].shape, SET[2].position);
    sfRectangleShape_setFillColor(SET[2].shape, SET[2].color);
    SET[2].font = sfFont_createFromFile("./src/main_menu/photos/font.TTF");
    SET[2].text = sfText_create();
    sfText_setString(SET[2].text, "DOWN");
    sfText_setFont(SET[2].text, SET[2].font);
    SET[2].pos_text = (sfVector2f){620, 420};
    sfText_setColor(SET[2].text, sfWhite);
    sfText_setCharacterSize(SET[2].text, 35);
    sfText_setPosition(SET[2].text, SET[2].pos_text);
}

void init_volume_bar(menu_t *all)
{
    SET[1].shape = sfRectangleShape_create();
    SET[1].size = (sfVector2f) {400, 80};
    SET[1].position = (sfVector2f) {760, 400};
    SET[1].color = sfBlack;
    SET[1].is_clicked = 0;
    sfRectangleShape_setSize(SET[1].shape, SET[1].size);
    sfRectangleShape_setPosition(SET[1].shape, SET[1].position);
    sfRectangleShape_setFillColor(SET[1].shape, SET[1].color);
    SET[1].font = sfFont_createFromFile("./src/main_menu/photos/font.TTF");
    SET[1].text = sfText_create();
    sfText_setString(SET[1].text, "VOLUME : 50");
    sfText_setFont(SET[1].text, SET[1].font);
    SET[1].pos_text = (sfVector2f){830, 420};
    sfText_setColor(SET[1].text, sfWhite);
    sfText_setCharacterSize(SET[1].text, 35);
    sfText_setPosition(SET[1].text, SET[1].pos_text);
}

void init_music_bar(menu_t *all)
{
    SET[0].shape = sfRectangleShape_create();
    SET[0].size = (sfVector2f) {400, 80};
    SET[0].position = (sfVector2f) {760, 270};
    SET[0].color = sfBlack;
    SET[0].is_clicked = 0;
    sfRectangleShape_setSize(SET[0].shape, SET[0].size);
    sfRectangleShape_setPosition(SET[0].shape, SET[0].position);
    sfRectangleShape_setFillColor(SET[0].shape, SET[0].color);
    SET[0].font = sfFont_createFromFile("./src/main_menu/photos/font.TTF");
    SET[0].text = sfText_create();
    sfText_setString(SET[0].text, "MUSIC : ON");
    sfText_setFont(SET[0].text, SET[0].font);
    SET[0].pos_text = (sfVector2f){850, 290};
    sfText_setColor(SET[0].text, sfWhite);
    sfText_setCharacterSize(SET[0].text, 35);
    sfText_setPosition(SET[0].text, SET[0].pos_text);
}

void init_settings_bars(menu_t *all)
{
    SET = malloc(sizeof(sets_t) * 6);
    init_music_bar(all);
    init_volume_bar(all);
    init_volume_down_bar(all);
    init_volume_up_bar(all);
    init_screen_bar(all);
    init_return_bar(all);
}
