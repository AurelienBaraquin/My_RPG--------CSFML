/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** main
*/

#include "my.h"
#include "../src/main_menu/menu.h"

const black_cock_t opt[] = {
    {GAME, display_window},
    {MAP, display_mini_map},
    {INVENTORY, display_inv},
    {NONE, NULL},
};

static void set_win(global_t *global)
{
    for (int i = 0; opt[i].func != NULL; i++) {
        if (opt[i].STATE == global->state) {
            opt[i].func(global);
            return;
        }
    }
}

static void main_loop(global_t *global, menu_t *all)
{
    if (all->change == 1){
        global->state = GAME;
        all->change = 0;
        sfText_setString(BAR[0].text, "CONTINUE");
        sfText_setString(BAR[0].text, "SAVE");
        global->window = Window;
    }
    if (global->state == MENU){
        main_menu(all);
        events(all);
        global->window = Window;
        return;
    }
    if (all->play == 1) {
        sfRenderWindow_clear(global->window, sfBlack);
        sfRenderWindow_drawSprite(global->window, global->tuto, NULL);
        sfRenderWindow_display(global->window);
        create_villages(create_map(NULL));
        global->map->map = get_map_from_file("./map/map.txt");
        global->map->village = get_map_from_file("./map/villages.txt");
        create_map_colision(global);
        global->map->colision = get_map_from_file("./map/colision.txt");
        all->play = 0;
        update_mini_map(global);
    }
    set_win(global);
    sfRenderWindow_display(global->window);
    update_entity_list_path(global);
    update_entity_list_deplacement(global->entities, global->map->colision);
    update_entity_list(global->entities, global);
    update_temple(global);
    event_loop(global);
}

void game_loop(global_t *global, menu_t *all)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float elapsed_time_anim = 0.1f;
    float elapsed_time_main = 1.0f;
    // sfMusic *music = sfMusic_createFromFile("assets/bo.wav");
    // sfMusic_play(music);
    // sfMusic_setLoop(music, sfTrue);
    sfRenderWindow_setKeyRepeatEnabled(global->window, sfTrue);
    change_animation_state(global->entities->entity, IS_IDLE);
    while (sfRenderWindow_isOpen(global->window)) {
        float elapsed_time = sfTime_asSeconds(sfClock_getElapsedTime(clock));
        if (elapsed_time > elapsed_time_anim) {
            update_animation_state_list(global->entities);
            next_frame_entity_list_animation(global->entities);
            attack_entity_update(global->entities);
            elapsed_time_anim += FPS(10);
        }
        if (elapsed_time > elapsed_time_main) {
            verif_templ(global);
            main_loop(global, all);
            elapsed_time_main += FPS(60);
        }
    }
}

int game(void)
{
    // sfMusic *music = sfMusic_createFromFile("assets/bo.wav");
    global_t *global = init_global();
    menu_t *all = set_menu();
    all->settings.window = global->window;
    global->map->colision = get_map_from_file("./map/colision.txt");
    game_loop(global, all);
    destroy_global(global);
    // sfMusic_destroy(music);
    return 0;
}
