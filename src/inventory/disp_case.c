/*
** EPITECH PROJECT, 2023
** test
** File description:
** disp_case
*/

#include "inventory.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

char *nb_to_str(int nb);
void loop_on_inv_disp(inv_t *inv, sfRenderWindow *window,
    sfRectangleShape *rec, sfVector2f mouse);
void item_disp(inv_t *inv, int i,
    sfRenderWindow *window, sfVector2f b);

static void hover_color(inv_t *inv, sfRectangleShape *rec, int i)
{
    if (inv->cases[i].state == HOVER) {
            sfRectangleShape_setFillColor(rec,
                sfColor_fromRGBA(255, 255, 255, 125));
    } else {
        sfRectangleShape_setFillColor(rec,
            sfColor_fromRGBA(180, 180, 180, 255));
    }
}

void update_loop_inv_disp(inv_t *inv, sfRenderWindow *window,
    int i, sfVector2f b)
{
        if (inv->cases[i].item != NULL) {
            item_disp(inv, i, window, b);
            if (inv->cases[i].state == HOVER) {
                display_item(window, inv->cases[i].item, inv->base);
            }
        }
}

void loop_on_inv_disp(inv_t *inv, sfRenderWindow *window,
    sfRectangleShape *rec, sfVector2f mouse)
{
    sfSprite *s = sfSprite_create();
    sfSprite_setTexture(s, sfTexture_createFromFile("./assets/items/items.png",
        NULL), sfFalse);
    sfVector2f b = {0, 0};
    for (int i = 0; i < INV_SIZE; i++) {
        b = ADDV(inv->base, inv->cases[i].pos);
        if (inv->cases[i].item != NULL) {
            sfSprite_setPosition(s, b);
            sfSprite_setTextureRect(s, inv->cases[i].item->rect);
            sfRenderWindow_drawSprite(window, s, NULL);
        }
        hover_color(inv, rec, i);
        sfRectangleShape_setPosition(rec, b);
        sfRenderWindow_drawRectangleShape(window, rec, NULL);
        update_loop_inv_disp(inv, window, i, b);
    }
    if (inv->curr->curr[0].item != NULL) {
        sfSprite_setPosition(s, ADDV(mouse, inv->base));
        sfSprite_setTextureRect(s, inv->curr->curr[0].item->rect);
        sfRenderWindow_drawSprite(window, s, NULL);
        sfText_setPosition(inv->text, ADDV(mouse, inv->base));
        sfText_setString(inv->text, nb_to_str(inv->curr->curr[0].nb));
        sfRenderWindow_drawText(window, inv->text, NULL);
    }
}
