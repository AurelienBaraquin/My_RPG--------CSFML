/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** init_global
*/

#include "my.h"

map_t* init_map(void)
{
    map_t *map_struct = malloc(sizeof(map_t));
    map_struct->map = get_map_from_file("./map/map.txt");
    map_struct->size = my_strlen(map_struct->map[0]);
    map_struct->seed = 0;
    map_struct->village = get_map_from_file("./map/villages.txt");
    map_struct->temple_collision = get_map_from_file
    ("./map/temple_collision.txt");
    return map_struct;
}

sfView *init_view(void)
{
    sfView *view = sfView_create();
    sfView_setCenter(view, (sfVector2f){960, 540});
    sfView_setSize(view, (sfVector2f){1920, 1080});
    return view;
}

void init_mini_map(global_t *global)
{
    global->map->flag_texture = sfTexture_createFromFile(
        "./assets/mini_map/flag.png", NULL);
    global->map->flag = sfSprite_create();
    sfSprite_setTexture(global->map->flag, global->map->flag_texture, sfTrue);
    sfSprite_setScale(global->map->flag, (sfVector2f){0.04, 0.04});
}

void set_animation_init(global_t *global)
{
    add_entity_by_precept(PLAYER, (sfVector2f){POS(500), POS_Y(500)}, global);
}

global_t *init_global(void)
{
    global_t *global = malloc(sizeof(global_t));
    global->map = init_map();
    create_map_colision(global);
    global->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "MyIsekai", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(global->window, 60);
    sfRenderWindow_setPosition(global->window, (sfVector2i){0, 0});
    global->sprites = init_sprite_list();
    global->entities = init_entity_list();
    set_animation_init(global);
    global->gui = init_gui();
    global->view = init_view();
    init_mini_map(global);
    global->state = MENU;
    update_mini_map(global);
    global->inv = init_inv();
    init_temple(global);
    global->tuto_texture = sfTexture_createFromFile("./assets/tuto.jpg", NULL);
    global->tuto = sfSprite_create();
    sfSprite_setTexture(global->tuto, global->tuto_texture, sfTrue);
    return global;
}
