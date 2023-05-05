/*
** EPITECH PROJECT, 2023
** init_sets_SET.c
** File description:
** Menu settings RPG
*/

#include "menu.h"

void init_return_bar(menu_t *all)
{
    SET[5].shape = sfRectangleShape_create();
    SET[5].size = (sfVector2f) {200, 80};
    SET[5].position = (sfVector2f) {20, 20};
    SET[5].color = sfBlack;
    SET[5].is_clicked = 0;
    sfRectangleShape_setSize(SET[5].shape, SET[5].size);
    sfRectangleShape_setPosition(SET[5].shape, SET[5].position);
    sfRectangleShape_setFillColor(SET[5].shape, SET[5].color);
    SET[5].font = sfFont_createFromFile("./src/main_menu/photos/font.TTF");
    SET[5].text = sfText_create();
    sfText_setString(SET[5].text, "HOME");
    sfText_setFont(SET[5].text, SET[5].font);
    SET[5].pos_text = (sfVector2f){65, 45};
    sfText_setColor(SET[5].text, sfWhite);
    sfText_setCharacterSize(SET[5].text, 28);
    sfText_setPosition(SET[5].text, SET[5].pos_text);
}

void init_screen_bar(menu_t *all)
{
    SET[4].shape = sfRectangleShape_create();
    SET[4].size = (sfVector2f) {400, 80};
    SET[4].position = (sfVector2f) {760, 140};
    SET[4].color = sfBlack;
    SET[4].is_clicked = 0;
    sfRectangleShape_setSize(SET[4].shape, SET[4].size);
    sfRectangleShape_setPosition(SET[4].shape, SET[4].position);
    sfRectangleShape_setFillColor(SET[4].shape, SET[4].color);
    SET[4].font = sfFont_createFromFile("./src/main_menu/photos/font.TTF");
    SET[4].text = sfText_create();
    sfText_setString(SET[4].text, "ACTIVE FULL SCREEN");
    sfText_setFont(SET[4].text, SET[4].font);
    SET[4].pos_text = (sfVector2f){790, 160};
    sfText_setColor(SET[4].text, sfWhite);
    sfText_setCharacterSize(SET[4].text, 28);
    sfText_setPosition(SET[4].text, SET[4].pos_text);
}
