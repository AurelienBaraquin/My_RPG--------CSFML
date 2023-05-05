/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** my
*/

#ifndef MY__
    #define MY__

    #define POS(x) (int) (x * 32) - 16
    #define POS_Y(x) (int) (x * 32)
    #define POS_REV(x) (int) (x + 16) / 32
    #define POS_REV_Y(x) (int) (x) / 32

    #define FPS(x) (1.0f / x)

    #define MAP_SIZE 1000
    #define NOISE_SCALE 0.05 // > 0 && < 1 -> compression (double)
    #define PERSISTENCE 1.8 // > 0 && < 3 -> amplitude (double)
    #define OCTAVES 1 // > 1 && < 5 -> detail (int)
    #define M_PI 3.14159265358979323846
    #define ENT_A entity->animations
    #define ANI_S animation_state

    #define CS(h, m, s, d, sd, r)\
    (stats_t) {\
        h, m , s, d, sd, r\
    }

    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Config.h>
    #include <SFML/Network.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <time.h>
    #include <math.h>
    #include <string.h>

    #include "sprite_list.h"
    #include "entity.h"
    #include "tools.h"
    #include "village.h"
    #include "struct.h"
    #include "inventory.h"

typedef enum {
    NONE,
    GAME,
    MAP,
    INVENTORY,
    MENU,
} CURRENT;


typedef struct map_s {
    char **map;
    char **village;
    char **colision;
    char **temple_collision;
    int size;
    int seed;
    sfSprite *flag;
    sfTexture *flag_texture;
    sfRenderTexture *texture;
    sfSprite *sprite;
} map_t;

typedef struct gui_s {
    int level;
    int xp;
    sfRectangleShape *xp_bar;
    sfRectangleShape *xp_bar_max;
    sfRectangleShape *hp;
    sfRectangleShape *max_hp;
    sfText *level_text;
    sfText *nb_potion;
} gui_t;

typedef struct colider_s {
    int fd;
    int *temp;
    int i;
    int j;
    int a;
} colider_t;


typedef struct global_s {
    sfRenderWindow *window;
    sfView *view;
    sfEvent event;
    map_t *map;
    sprite_t **sprites;
    entity_list_t *entities;
    CURRENT state;
    inv_t *inv;
    gui_t *gui;
    sfSprite *tuto;
    sfTexture *tuto_texture;
} global_t;

typedef struct black_cock_s {
    CURRENT STATE;
    void (*func)(global_t *global);
} black_cock_t;

    #include "prot.h"

    #define CONCAT(dest, src)\
    do {\
        char* p = (dest) + my_strlen(dest);\
        const char* q = (src);\
        while (*q != '\0') {\
            *p++ = *q++;\
        } *p = '\0';\
    } while (0)

#endif /* !MY__ */
