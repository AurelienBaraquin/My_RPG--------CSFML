/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** event
*/

#ifndef EVENT_H_
    #define EVENT_H_

    #include <SFML/Graphics.h>

typedef enum {
    MOUSE_NONE,
    MOUSE_LEFT
} MOUSE_STATE;

typedef enum {
    KEY_NONE,
    KEY_M,
    KEY_L
} KEY_STATE;

typedef struct event_s {
    sfEvent event;
    sfVector2i mouse_pos;
    MOUSE_STATE mouse;
    KEY_STATE key;
} event_t;

#endif /* !EVENT_H_ */
