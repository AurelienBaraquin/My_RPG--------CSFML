/*
** EPITECH PROJECT, 2023
** Menu
** File description:
** RPG
*/

#include "menu.h"

menu_t *set_menu(void)
{
    menu_t *all = malloc(sizeof(menu_t));
    all->play = 0;
    all->sets = 0;
    all->resume = 0;
    all->volume = 50;
    all->src = 0;
    all->change = 0;
    init_menu(all);
    all->clock = sfClock_create();
    sfMusic_play(all->music);
    return all;
}

void main_menu_loop(menu_t *all)
{
    display(all);
}

int main_menu(menu_t *all)
{
    main_menu_loop(all);
    return 0;
}
