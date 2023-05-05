/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** display_two
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "inventory.h"
#include "my.h"

void loop_on_inv_disp(inv_t *inv, sfRenderWindow *window,
    sfRectangleShape *rec, sfVector2f mouse);
void character(inv_t *inv, sfRenderWindow *window);
sfRectangleShape *create_rec(sfColor color, sfVector2f size, sfVector2f pos);

void display_item(sfRenderWindow *window, item_t *item, sfVector2f b)
{
    if (item == NULL)
        return;
    sfText *text = sfText_create();
    sfRectangleShape *rec = create_rec(sfColor_fromRGB(180, 180, 180),
        VEC(100, 300), VADD(b, 1030, 690));
    sfFont *font = sfFont_createFromFile("./assets/Betelgeuse.ttf");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, VADD(b, 1035, 690));
    sfText_setColor(text, sfBlack);
    sfText_setString(text, item->name);
    sfRenderWindow_drawRectangleShape(window, rec, NULL);
    sfRenderWindow_drawText(window, text, NULL);
    sfRectangleShape_destroy(rec);
    sfText_destroy(text);
}

void display_inv(global_t *global)
{
    sfRenderWindow *window = global->window;
    inv_t *inv = global->inv;
    display_window(global);
    const sfView *view = sfRenderWindow_getView(window);
    inv->base = sfRenderWindow_mapPixelToCoords(window, (sfVector2i)
        {0, 0}, view);
    check_inv(inv, window);
    sfVector2f mouse = {0, 0};
    mouse = VEC(sfMouse_getPositionRenderWindow(window).x,
        sfMouse_getPositionRenderWindow(window).y);
    sfRectangleShape *rec = create_rec(sfColor_fromRGB(180, 180, 180),
        inv->cases[0].size, VEC(0, 0));
    character(inv, window);
    loop_on_inv_disp(inv, window, rec, mouse);
    sfRectangleShape_destroy(rec);
}
