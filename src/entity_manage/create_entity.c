/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** create_entity
*/

#include "my.h"

void hostile_precept2(int type, sfVector2f pos, global_t *global)
{
    switch (type) {
        case JACKOLANTERN:
            add_entity(global->entities, create_entity(pos,
            global->sprites[JACKOLANTERN], CS(20, 20, 40, 15, mlrand(4, 6),
            POS(2)), HOSTILE));
            break;
        case ROBOT:
            add_entity(global->entities, create_entity(pos,
            global->sprites[ROBOT], CS(100, 100, 10, 16, mlrand(1, 2),
            POS(2)), HOSTILE));
            break;
        case ORC:
            add_entity(global->entities, create_entity(pos,
            global->sprites[ORC], CS(80, 80, 50, 2, mlrand(1, 2),
            POS(2)), HOSTILE));
            break;
    }
}

void hostile_precept(int type, sfVector2f pos, global_t *global)
{
    switch (type) {
        case SKELETON:
            add_entity(global->entities, create_entity(pos,
            global->sprites[SKELETON], CS(20, 20, 10, 30, mlrand(1, 3),
            POS(3)), HOSTILE));
            break;
        case ZOMBIE:
            add_entity(global->entities, create_entity(pos,
            global->sprites[ZOMBIE], CS(40, 40, 15, 20, mlrand(2, 4),
            POS(2)), HOSTILE));
            break;
        case ALIEN:
            add_entity(global->entities, create_entity(pos,
            global->sprites[ALIEN], CS(100, 100, 20, 20, mlrand(1, 2),
            POS(2)), HOSTILE));
            break;
    }
    hostile_precept2(type, pos, global);
}

void add_entity_by_precept(int type, sfVector2f pos, global_t *global)
{
    switch (type) {
        case PLAYER:
            add_entity(global->entities, create_entity(pos,
            global->sprites[PLAYER], CS(200, 200, 20, 50, 10, POS(4)),
            PLAYER));
            break;
        case PIG:
            add_entity(global->entities, create_entity(pos,
            global->sprites[PIG], CS(50, 50, 0, 0, 10, 0),
            NEUTRAL));
            break;
    }
    hostile_precept(type, pos, global);
}

void add_random_entity_hostile(sfVector2f pos, global_t *global)
{
    int rand = mlrand(0, 5);
    int types[6] = {SKELETON, ZOMBIE, ALIEN, JACKOLANTERN, ROBOT, ORC};
    add_entity_by_precept(types[rand], pos, global);
}
