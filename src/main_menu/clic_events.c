/*
** EPITECH PROJECT, 2023
** events.c
** File description:
** Menu_RPG
*/

#include "menu.h"

void menu_bar_events(menu_t *all)
{
    for (int i = 0; i < 4; i++) {
        is_hovered(all, BAR[i].shape) ?
        sfRectangleShape_setFillColor(BAR[i].shape, sfWhite),
        sfText_setColor(BAR[i].text, sfBlack) : 0;
        !(is_hovered(all, BAR[i].shape)) ?
        sfRectangleShape_setFillColor(BAR[i].shape, sfBlack),
        sfText_setColor(BAR[i].text, sfWhite) : 0;
    }
}

void menu_sets_events(menu_t *all)
{
    for (int i = 0; i < 6; i++) {
        is_hovered(all, SET[i].shape) ?
        sfRectangleShape_setFillColor(SET[i].shape, sfWhite),
        sfText_setColor(SET[i].text, sfBlack) : 0;
        !(is_hovered(all, SET[i].shape)) ?
        sfRectangleShape_setFillColor(SET[i].shape, sfBlack),
        sfText_setColor(SET[i].text, sfWhite) : 0;
    }
}

void bars_events(menu_t *all)
{
    is_clicked(all,BAR[0].shape) ? all->play = 1 : 0;
    is_clicked(all,BAR[1].shape) ? all->resume = 1 : 0;
    is_clicked(all,BAR[2].shape) ? all->sets = 1 : 0;
    is_clicked(all,BAR[3].shape) ? sfRenderWindow_close(Window) : 0;
}

void sets_events_music(menu_t *all)
{
    if (is_clicked(all, SET[0].shape)) {
        if (all->volume > 0) {
            sfText_setString(SET[0].text, "MUSIC : OFF");
            sfMusic_setVolume(all->music, 0);
            all->volume = 0;
            return;
        }
        if (all->volume == 0) {
            sfText_setString(SET[0].text, "MUSIC : ON");
            sfMusic_setVolume(all->music, 50);
            all->volume = 50;
            return;
        }
    }
    is_clicked(all, SET[2].shape) && all->volume > 0 ? all->volume -= 10,
    sfMusic_setVolume(all->music, all->volume), sfText_setString(SET[1].text,
    my_strcat_menu("VOLUME : ", int_to_string(all->volume))) : 0;
    is_clicked(all, SET[3].shape) && all->volume < 100 ? all->volume += 10,
    sfMusic_setVolume(all->music, all->volume), sfText_setString(SET[1].text,
    my_strcat_menu("VOLUME : ", int_to_string(all->volume))) : 0;
}

void sets_events_screen(menu_t *all)
{
    if (is_clicked(all, SET[4].shape)) {
        if (all->src == 0){
            sfRenderWindow_close(Window);
            Window = sfRenderWindow_create(all->settings.mode,
            "menu", sfFullscreen, NULL);
            sfText_setString(SET[4].text, "INACTIVE FULL SCREEN");
            sfText_setPosition(SET[4].text, (sfVector2f){770, 160});
            all->src = 1;
        } else {
            sfRenderWindow_close(Window);
            Window = sfRenderWindow_create(all->settings.mode,
            "menu", sfClose, NULL);
            sfText_setString(SET[4].text, "ACTIVE FULL SCREEN");
            sfText_setPosition(SET[4].text, (sfVector2f){790, 160});
            all->src = 0;
        }
    }
    is_clicked(all, SET[5].shape) ? all->sets = 0 : 0;
}
