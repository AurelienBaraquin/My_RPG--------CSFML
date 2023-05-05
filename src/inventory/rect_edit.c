/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** rect_edit
*/

#include <SFML/Graphics.h>

sfRectangleShape *create_rec(sfColor color, sfVector2f size, sfVector2f pos)
{
    sfRectangleShape *rec = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(rec, sfBlack);
    sfRectangleShape_setOutlineThickness(rec, 3);
    sfRectangleShape_setFillColor(rec, color);
    sfRectangleShape_setSize(rec, size);
    sfRectangleShape_setPosition(rec, pos);
    return rec;
}

void rec_edit(sfVector2f size, sfVector2f pos, sfColor color,
    sfRectangleShape *rec)
{
    sfRectangleShape_setSize(rec, size);
    sfRectangleShape_setPosition(rec, pos);
    sfRectangleShape_setFillColor(rec, color);
}
