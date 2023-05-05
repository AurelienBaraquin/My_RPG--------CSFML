/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** temple
*/

#include "my.h"

sfVector2f enter_temple(global_t *global, sfVector2f new_entry, int option)
{
    static sfVector2f entry = {0, 0};
    if (option == 1)
        return entry;
    entry = (sfVector2f){new_entry.x, new_entry.y + POS_Y(2)};
    set_sprite_position(global->sprites[TEMPLE], (sfVector2f){POS_Y(3000), 0});
    global->entities->entity->deplacement = NULL;
    global->entities->entity->direction = UP;
    global->entities->entity->pos = (sfVector2f
    ){POS(49) + POS_Y(3000), POS_Y(126)};
    return (sfVector2f){0, 0};
}

int end_temple(global_t *global, double difficulty)
{
    set_sprite_position(global->sprites[CHEST],
    (sfVector2f){POS_Y(3000) + POS_Y(48), POS_Y(38)});
    if (get_distance_between_entity_and_pos(global->entities->entity,
    (sfVector2f){POS_Y(3000) + POS_Y(48), POS_Y(38)}) <= POS_Y(2)) {
        add_rand_nb_item_by_rarity(global->inv, (int) 5 * difficulty, COMMON);
        add_rand_nb_item_by_rarity(global->inv, (int) 1 * difficulty, RARE);
        if (mlrand(1, 100) >= 70)
            add_rand_nb_item_by_rarity
            (global->inv, (int) 1 * difficulty, EPIC);
        if (mlrand(1, 100) >= 95)
            add_rand_nb_item_by_rarity
            (global->inv, (int) 1 * difficulty, LEGENDARY);
        global->entities->entity->pos = enter_temple
        (global, (sfVector2f){0, 0}, 1);
        global->entities->entity->deplacement = NULL;
        return (0);
    }
    return (100);
}

int is_in_temple(sfVector2f pos)
{
    if (pos.x < 2900 || pos.x > 3196 || pos.y < 0 || pos.y > 196)
        return (0);
    return (1);
}

void add_temple_entity(global_t *global, int wave, double difficulty)
{
    for (int i = 0; i < 3 * difficulty * (wave / 2); i++) {
        add_random_entity_hostile((sfVector2f){POS(3000) +
        POS_Y(mlrand(40, 56)), POS_Y(mlrand(40, 56))}, global);
    }
}

void update_temple(global_t *global)
{
    if (is_in_temple(get_entity_pos(global->entities->entity)) == 0)
        return;
    static int wave = 0;
    static double difficulty = 1;
    if (wave >= 10) {
        wave = end_temple(global, difficulty);
        return;
    }
    set_sprite_position(global->sprites[CHEST], (sfVector2f)
    {POS_Y(3000) + POS_Y(480), POS_Y(38)});
    if (wave == 0) {
        wave = 1;
        difficulty += 0.25;
    }
    if (get_nb_entity_in_range(global->entities,
    global->entities->entity->pos, POS(100)) == 1) {
        add_temple_entity(global, wave, difficulty);
        wave++;
    }
}
