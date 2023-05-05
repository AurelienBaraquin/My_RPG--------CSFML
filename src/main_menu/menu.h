/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** RPG
*/

#pragma once
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <SFML/Audio.h>
#include <string.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <time.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics.h>
#define Window all->settings.window
#define Event all->settings.event
#define Pic all->pictures
#define BAR all->bars
#define SET all->set

typedef struct bar_s{
    sfRectangleShape* shape;
    sfVector2f size;
    sfVector2f position;
    sfColor color;
    int is_clicked;
    sfFont *font;
    sfText *text;
    sfVector2f pos_text;
} bar_t;

typedef struct sets_s{
    sfRectangleShape* shape;
    sfVector2f size;
    sfVector2f position;
    sfColor color;
    int is_clicked;
    sfFont *font;
    sfText *text;
    sfVector2f pos_text;
} sets_t;

typedef struct parametrs {
    sfVideoMode mode;
    sfRenderWindow* window;
    sfEvent event;
} parametrs_t;

typedef struct img {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    sfVector2f size;
} img_t;

typedef struct menu_s {
    parametrs_t settings;
    img_t *pictures;
    sfMusic *music;
    bar_t *bars;
    sets_t *set;
    int play;
    int sets;
    int resume;
    int volume;
    int src;
    sfClock *clock;
    sfTime time1;
    int change;
} menu_t;

void init_menu(menu_t *all);

void init_bars(menu_t *all);

int is_hovered(menu_t *all, sfRectangleShape* shape);

int is_clicked(menu_t *all, sfRectangleShape* shape);

void events(menu_t *all);

void display(menu_t *all);

void init_settings_bars(menu_t *all);

char *int_to_string(int nb);

char *my_strcat_menu(char *src, char *dest);

void init_return_bar(menu_t *all);

void init_screen_bar(menu_t *all);

void menu_bar_events(menu_t *all);

void menu_sets_events(menu_t *all);

void bars_events(menu_t *all);

void sets_events_music(menu_t *all);

void sets_events_screen(menu_t *all);

void animation_background(menu_t *all);

menu_t *set_menu(void);
