/*
** EPITECH PROJECT, 2023
** Menu
** File description:
** RPG
*/

#include "menu.h"

void init_window(menu_t *all)
{
    all->settings.mode.bitsPerPixel = 30;
    all->settings.mode.height = 1080;
    all->settings.mode.width = 1920;
}

void init_music(menu_t *all)
{
    all->music = sfMusic_createFromFile
    ("./src/main_menu/photos/egypt_sound.ogg");
}

void init_sprite2(menu_t *all)
{
    sfSprite_setTexture(Pic[1].sprite, Pic[1].texture, sfTrue);
    sfSprite_setScale(Pic[1].sprite, Pic[1].scale);
    sfSprite_setPosition(Pic[1].sprite, Pic[1].pos);
    Pic[2].texture = sfTexture_createFromFile
    ("././src/main_menu/photos/BG1.jpg", NULL);
    Pic[2].scale.x = 1.2;
    Pic[2].scale.y = 1.2;
    Pic[2].pos.x = 0;
    Pic[2].pos.y = 2160;
    Pic[2].sprite = sfSprite_create();
    sfSprite_setTexture(Pic[2].sprite, Pic[2].texture, sfTrue);
    sfSprite_setScale(Pic[2].sprite, Pic[2].scale);
    sfSprite_setPosition(Pic[2].sprite, Pic[2].pos);
}

void init_sprite(menu_t *all)
{
    int n = 3;
    Pic = malloc(sizeof(img_t) * n);
    Pic[0].texture = sfTexture_createFromFile
    ("././src/main_menu/photos/BG2.jpg", NULL);
    Pic[0].scale.x = 1.2;
    Pic[0].scale.y = 1.2;
    Pic[0].pos.x = 0;
    Pic[0].pos.y = 0;
    Pic[0].sprite = sfSprite_create();
    sfSprite_setTexture(Pic[0].sprite, Pic[0].texture, sfTrue);
    sfSprite_setScale(Pic[0].sprite, Pic[0].scale);
    sfSprite_setPosition(Pic[0].sprite, Pic[0].pos);
    Pic[1].texture = sfTexture_createFromFile
    ("././src/main_menu/photos/BG2.jpg", NULL);
    Pic[1].scale.x = 1.2;
    Pic[1].scale.y = 1.2;
    Pic[1].pos.x = 0;
    Pic[1].pos.y = 1080;
    Pic[1].sprite = sfSprite_create();
}

void init_menu(menu_t *all)
{
    init_window(all);
    init_music(all);
    init_bars(all);
    init_sprite(all);
    init_sprite2(all);
}
