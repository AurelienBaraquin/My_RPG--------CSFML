/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** event
*/

#include "my.h"

item_t *get_random_item_by_type(inv_t *inv, int type);

static void moove_event(sfEvent event, global_t *global)
{
    if (event.type == sfEvtKeyPressed) {
        verif_key_pressed(global, event);
        switch (event.key.code) {
            case sfKeyP:
                global->gui->xp += 10;
                return;
            case sfKeyH:
                heal_potion(global);
                return;
            case sfKeyY:
                enter_temple(global, get_entity_pos(
                    global->entities->entity), 0);
                return;
            case sfKeyB:
                global->inv->add(global->inv, get_random_item_by_type(global->inv, ARMOR));
            default:
                return;
        }
    }
}

static void game_state(sfEvent event, global_t *global)
{
    if (event.type == sfEvtKeyPressed) {
        switch (event.key.code) {
            case sfKeyM:
                global->state = global->state == MAP ? GAME : MAP;
                return;
            case sfKeyTab:
                global->state = global->state == INVENTORY ? GAME : INVENTORY;
                return;
            default:
                return;
        }
    }
}

static void animation_event(sfEvent event, global_t *global)
{
    if (event.type == sfEvtKeyPressed) {
        switch (event.key.code) {
            case sfKeySpace:
                change_animation_state(global->entities->entity, IS_DIE);
                return;
            case sfKeyR:
                change_animation_state(global->entities->entity, IS_IDLE);
                return;
            default:
                return;
        }
    }
}

static void mouse_event(sfEvent event, global_t *global)
{
    global->inv->state = OPEN;
    if (event.type == sfEvtMouseButtonPressed) {
        event_verif(global, event);
    }
}

void event_loop(global_t *global)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(global->window, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
            event.key.code == sfKeyEscape)) {
            sfRenderWindow_close(global->window);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL) {
            lock_function(global->entities);
        }
        game_state(event, global);
        if (global->state == GAME) {
            moove_event(event, global);
        }
        animation_event(event, global);
        mouse_event(event, global);
    }
}
