/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** xp
*/

#include "my.h"

void add_xp(global_t *global, int xp)
{
    if (!global)
        return;
    global->gui->xp += xp;
}

void add_level(global_t *global, int level)
{
    if (!global)
        return;
    global->gui->level += level;
}
