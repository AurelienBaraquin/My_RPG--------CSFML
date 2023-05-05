/*
** EPITECH PROJECT, 2023
** inventory
** File description:
** display
*/

#include "inventory.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

void display_item(sfRenderWindow *window, item_t *item, sfVector2f b);
void rec_edit(sfVector2f size, sfVector2f pos, sfColor color,
    sfRectangleShape *rec);
sfRectangleShape *create_rec(sfColor color, sfVector2f size, sfVector2f pos);
char *nb_to_str(int nb);

void character(inv_t *inv, sfRenderWindow *window)
{
    sfRectangleShape *rec = create_rec(sfColor_fromRGB(180, 180, 180),
        VEC(765, 670), VADD(inv->base, 1140, 10));
    sfRenderWindow_drawRectangleShape(window, rec, NULL);
    rec_edit(VEC(550, 670), VADD(inv->base, 1140, 10),
        sfColor_fromRGB(100, 100, 100), rec);
    sfRenderWindow_drawRectangleShape(window, rec, NULL);
    sfRectangleShape_destroy(rec);
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("./assets/char.png", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, VADD(inv->base, 1140, 10));
    sfSprite_scale(sprite, (sfVector2f){1.4, 1.4});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void item_disp(inv_t *inv, int i,
    sfRenderWindow *window, sfVector2f b)
{
    static sfSprite *s = NULL;
    // sfTexture *t = sfTexture_createFromImage(inv->cases[i].item->path);
    if (s == NULL) {
        s = sfSprite_create();
    } 
    sfText_setString(inv->text, nb_to_str(inv->cases[i].nb));
    sfText_setPosition(inv->text, VADD(b, 30, 25));
    sfSprite_setPosition(s, b);
    sfSprite_setTexture(s, sfTexture_createFromFile(inv->cases[i].item->path,
        &inv->cases[i].item->rect), sfFalse);
    sfRenderWindow_drawText(window, inv->text, NULL);
    sfRenderWindow_drawSprite(window, s, NULL);
}
