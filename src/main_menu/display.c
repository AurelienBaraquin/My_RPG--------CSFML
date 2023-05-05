/*
** EPITECH PROJECT, 2023
** display.c
** File description:
** RPG menu
*/

#include "menu.h"

void display(menu_t *all)
{
    sfRenderWindow_clear(Window, sfWhite);
    animation_background(all);
    if (all->play == 0 && all->resume == 0 && all->sets == 0) {
        for (int s = 0; s < 3; s++)
            sfRenderWindow_drawSprite(Window, Pic[s].sprite, NULL);
        for (int i = 0; i < 4; i++) {
            sfRenderWindow_drawRectangleShape(Window, BAR[i].shape, NULL);
            sfRenderWindow_drawText(Window, BAR[i].text, NULL);
        }
    }
    if (all->play == 0 && all->resume == 0 && all->sets == 1) {
        for (int s = 0; s < 3; s++)
            sfRenderWindow_drawSprite(Window, Pic[s].sprite, NULL);
        for (int i = 0; i < 6; i++) {
            sfRenderWindow_drawRectangleShape(Window, SET[i].shape, NULL);
            sfRenderWindow_drawText(Window, SET[i].text, NULL);
        }
    }
    sfRenderWindow_display(Window);
}
