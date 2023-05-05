/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** entity
*/

#ifndef ENTITY_H_
    #define ENTITY_H_

    #include "my.h"

typedef enum {
    PLAYERS,
    HOSTILE,
    NEUTRAL,
    FRIENDLY
} ENTITY_STATUS;

    #define PLAYER_ENTITY(list) (list->entity)

typedef enum {
    IS_IDLE,
    IS_WALK,
    IS_ATTACK,
    IS_DIE
} CURRENT_ACTION;

typedef enum {
    UP,
    LEFT,
    DOWN,
    RIGHT
} DIRECTION;

typedef struct stats_s {
    int hp;
    int max_hp;
    int strength;
    int defense;
    int speed;
    int range;
} stats_t;

typedef struct deplacement_s {
    int direction;
    int frame;
    struct deplacement_s *next;
} deplacement_t;

typedef struct animation_s {
    int min;
    int max;
    sfVector2f pos;
    sfBool is_loop;
    int frame_size;
} animation_t;

typedef struct animation_list_s {
    sfIntRect frame_rect;
    int animation_state;
    animation_t anim[4];
} animation_list_t;

typedef struct entity_s {
    sprite_t *sprite;
    sfVector2f pos;
    stats_t *stats;
    int id;
    sfBool is_locked;
    sfRectangleShape *lock_rect;
    int type;
    int direction;
    deplacement_t *deplacement;
    animation_list_t *animations;
} entity_t;

    #define CURRENT_FRAME_SIZE entity->animations->anim\
    [entity->animations->animation_state].frame_size

typedef struct entity_list_s {
    entity_t *entity;
    struct entity_list_s *next;
} entity_list_t;

#endif /* !ENTITY_H_ */
