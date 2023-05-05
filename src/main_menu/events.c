/*
** EPITECH PROJECT, 2023
** events.c
** File description:
** Menu_RPG
*/

#include "menu.h"

void animation_background(menu_t *all)
{
    all->time1 = sfClock_getElapsedTime(all->clock);
    if (all->time1.microseconds / 100000.0 > 0.05) {
        Pic[0].pos.y -= 5;
        Pic[1].pos.y -= 5;
        Pic[2].pos.y -= 5;
        if (Pic[0].pos.y <= -2160)
            Pic[0].pos.y = 0;
        if (Pic[1].pos.y <= -1080)
            Pic[1].pos.y = 1080;
        if (Pic[2].pos.y <= 0)
            Pic[2].pos.y = 2160;
        sfSprite_setPosition(Pic[0].sprite, Pic[0].pos);
        sfSprite_setPosition(Pic[1].sprite, Pic[1].pos);
        sfSprite_setPosition(Pic[2].sprite, Pic[2].pos);
        sfClock_restart(all->clock);
    }
}

void events(menu_t *all)
{
    while (sfRenderWindow_pollEvent(Window, &Event)) {
        if (Event.type == sfEvtResized)
            sfRenderWindow_setView(Window, sfView_createFromRect((sfFloatRect)
            {0, 0, Event.size.width, Event.size.height}));
        if (Event.type == sfEvtClosed)
            sfRenderWindow_close(Window);
        if (Event.type == sfEvtKeyPressed && Event.key.code == sfKeyEscape)
            sfRenderWindow_close(Window);
        if (all->play == 0 && all->resume == 0 && all->sets == 0) {
            menu_bar_events(all);
            Event.type == sfEvtMouseButtonPressed ? bars_events(all) : 0;
        }
        if (all->play == 0 && all->resume == 0 && all->sets == 1) {
            menu_sets_events(all);
            Event.type == sfEvtMouseButtonPressed ? sets_events_screen(all),
            sets_events_music(all) : 0;
        }
        all->play == 1 || all->resume == 1 ? all->change = 1 : 0;
    }
}
