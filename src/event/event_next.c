/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** event_next
*/

#include "my.h"

void event_verif(global_t *global, sfEvent event)
{
    switch (event.mouseButton.button) { case sfMouseLeft:
                global->inv->state = PRESS;
                if (get_entity_pos(global->entities->entity).x > 2900)
                    global->state == GAME ?
                    fusion_deplacement(global->entities->entity,
                        path_finding(global->map->temple_collision,
                        (sfVector2f){get_entity_pos(global->entities->entity).x
                        - 3000, get_entity_pos(global->entities->entity).y},
                            (sfVector2f){get_mouse_in_map_f(global->window).x
                            - 3000, get_mouse_in_map_f(global->window).y})) : 0;
                else
                    global->state == GAME ? fusion_deplacement(
                        global->entities->entity,
                        path_finding(global->map->colision,
                        get_entity_pos(global->entities->entity),
                            get_mouse_in_map_f(global->window))) : 0;
                return;
            case sfMouseRight: global->inv->state = REAL; return;
            default: return;
    }
}

void verif_key_pressed(global_t *global, sfEvent event)
{
    switch (event.key.code) { case sfKeyD:
            add_deplacement(global->entities->entity, RIGHT);
            return;
        case sfKeyS:
            add_deplacement(global->entities->entity, DOWN);
            return;
        case sfKeyZ:
            add_deplacement(global->entities->entity, UP);
            return;
        case sfKeyQ:
            add_deplacement(global->entities->entity, LEFT);
            return;
        case sfKeyN:
            int x = get_entity_pos(global->entities->entity).x;
            int y = get_entity_pos(global->entities->entity).y;
            add_random_entity_hostile((sfVector2f){POS(mlrand(x - 5, x + 5)),
            POS(mlrand(y - 5, y + 5))}, global);
            return;
        default: return;
    }
}
