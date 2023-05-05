/*
** EPITECH PROJECT, 2023
** prot.h
** File description:
** Prototypes for all functions
*/

#include "my.h"

#include "../src/main_menu/menu.h"

#pragma once

void destroy_global(global_t *global);
void destroy_map(map_t *map);

inv_t *init_inv(void);
void display_inv(global_t *global);
void move_entity(entity_t *entity, sfVector2f pos);
void unlock_all_entity(entity_list_t *entity_list);
void lock_entity(entity_list_t *entity_list, int id);
void add_entity(entity_list_t *entity_list, entity_t *entity);
void destroy_entity(entity_t *entity);
void draw_entity(entity_t *entity, sfRenderWindow *window);
void update_entity(entity_t *entity);
int get_direction_between_entity(entity_t *entity1, entity_t *entity2);
int get_direction_between_entity_and_pos(entity_t *entity, sfVector2f pos);
void set_entity_direction(entity_t *entity, int direction);
int get_distance_between_entity(entity_t *entity1, entity_t *entity2);
int get_distance_between_entity_and_pos(entity_t *entity, sfVector2f pos);
int get_distance_between_pos(sfVector2f pos1, sfVector2f pos2);
int get_nb_entity_in_range(entity_list_t *entity_list,
sfVector2f pos, int range);
entity_list_t* init_entity_list(void);
void destroy_entity_list(entity_list_t *entity_list);
void draw_entity_list(entity_list_t *entity_list, sfRenderWindow *window);
void remove_entity(entity_list_t *entity_list, int id);
void update_entity_list(entity_list_t *entity_list, global_t *global);
int get_entity_in_range(entity_list_t *entity_list, entity_t *entity,
    int range);
int get_nb_entity(entity_list_t *entity_list);
int get_nb_entity_by_type(entity_list_t *entity_list, int type);
entity_t* get_entity_by_id(entity_list_t *entity_list, int id);
entity_t* get_entity_by_type(entity_list_t *entity_list, int type, int index);
int get_id_of_entity(entity_list_t *entity_list, entity_t *entity);
entity_t* create_entity(sfVector2f pos, sprite_t *sprite,
stats_t stats, int type);
int get_entity_in_range_by_type(entity_list_t *entity_list, entity_t
*entity, int range, int type);
void update_entity_deplacement(entity_t *entity, char **map);
sfVector2f get_coord_from_direction(int direction, int speed);
void add_deplacement(entity_t *entity, int direction);
void remove_first_deplacement(entity_t *entity);
entity_t* get_entity_by_sprite_type(entity_list_t *entity_list, int type,
    int index);
int entity_is_character(entity_t *entity);
void next_frame_entity_list_animation(entity_list_t *entity_list);
int get_max_frame_animation(entity_t *entity);
void attack_entity_update(entity_list_t *entity_list);
void set_entity_animation_default(entity_t *entity);
void die_entity(entity_t *entity, entity_list_t *entity_list, global_t *global);
void die_entity_list(entity_list_t *entity_list, global_t *global);
entity_t* get_locked_entity(entity_list_t *entity_list);
void add_entity_by_precept(int type, sfVector2f pos, global_t *global);
void attack_entity_update(entity_list_t *entity_list);
sfVector2f get_entity_pos(entity_t *entity);
void fusion_deplacement(entity_t *entity, deplacement_t *deplacement);
void update_entity_path(entity_t *entity, char **map, entity_t *player);
void update_entity_list_path(global_t *global);
void update_entity_list_deplacement(entity_list_t *entity_list, char **map);
void remove_last_deplacement(entity_t *entity);
void add_random_entity_hostile(sfVector2f pos, global_t *global);
void verif_entity_pos(entity_t *entity);

void event_loop(global_t *global);
void lock_function(entity_list_t *entity_list);

int texture_list_size(void);
sprite_t** init_sprite_list(void);
void draw_sprite(sprite_t *sprite, sfRenderWindow *window);
void destroy_sprite_list(sprite_t **sprite_list);
void set_sprite_position(sprite_t *sprite, sfVector2f position);
void attack_entity(entity_t *entity, entity_t *target);

double noise(int x, int y, int seed);
double smoothNoise(double x, double y, int seed);
double interpolate(double a, double b, double x);
double interpolatedNoise(double x, double y, int seed);
double perlinNoise(double x, double y, int seed);
void print_intensity(double intensity, int fd);
int create_map(char *seed_str);
int create_villages(int seed);
char **get_map_from_file(char *filepath);
char **create_random_array(char min_char,
char max_char, size_t size, size_t str_len);

global_t *init_global(void);

int mlrand(int min, int max);

void display_window(global_t *global);
void display_mini_map(global_t *global);
void draw_map(global_t *global, int size);
int get_sand_type(char c);
int create_map_colision(global_t *global);
int get_village_type(char c);
void draw_village(global_t *global, int size);
void draw_mini_village(global_t *global, int size);
void draw_map_mini(global_t *global, int size);
void update_mini_map(global_t *global);
int map_village_colision_three(int *temp, int j, int fd);
int map_village_colision_two(int *temp, int j, int fd);
animation_list_t *create_animation_list(sfIntRect frame_rect);
animation_t create_animation(int min, int max, sfVector2f pos);
void set_animation(entity_t *entity, sfVector2i max_framesize, sfVector2f pos,
    int animation_type);
void set_animation_list(entity_t *entity);
void next_frame_entity_animation(entity_t *entity);
void update_animation_list(animation_list_t *animation_list,
    int animation_state);
void change_animation_state(entity_t *entity, int animation_state);
void get_animation_state(entity_t *entity);
void update_animation_state_list(entity_list_t *entity_list);
int create_village_next(create_village_t *village,
int i, create_struct_t *structure, int j);
void print_intensity(double intensity, int fd);
int enought_size(create_village_t *village, int x, int y, int type);
int verif_size(create_village_t *village, int *x_y, int i, int type);
double perlinnoise(double x, double y, int seed);
int map_village_colision_four(int *temp, int j, int fd);
void continue_init_village(create_village_t *village,
create_struct_t *strcture);
int get_cactus_type(char c);

stats_t* copy_stats(stats_t stats);
int get_stats_value(entity_t *entity, char *type);

sfVector2f get_mouse_pos_f(sfRenderWindow *window);
sfVector2i get_mouse_pos_i(sfRenderWindow *window);
sfVector2i get_mouse_in_map(sfRenderWindow *window);
sfVector2f get_mouse_in_map_f(sfRenderWindow *window);

gui_t *init_gui(void);
void draw_gui(sfRenderWindow *window, gui_t *gui,
entity_t *player, global_t *global);
void update_gui(gui_t *gui, entity_t *player,
sfRenderWindow *window, global_t *global);

deplacement_t* path_finding(char **map, sfVector2f pos_start,
sfVector2f pos_end);

void add_level(global_t *global, int level);
void add_xp(global_t *global, int xp);
void heal_potion(global_t *global);

void display_temple(global_t *global);
sfVector2f enter_temple(global_t *global, sfVector2f entry, int option);
void init_temple(global_t *global);
void update_temple(global_t *global);

item_t *get_item_by_id(inv_t *inv, int id);
item_t *get_item_by_name(inv_t *inv, char *name);
item_t *get_item_by_rarity(inv_t *inv, int rarity);
item_t *get_item_by_type(inv_t *inv, int type);
item_t *get_item_by_rarity_and_type(inv_t *inv, int rarity, int type);
int get_nb_items_by_rarity(inv_t *inv, int rarity);
int get_nb_item_by_type(inv_t *inv, int type);
int get_nb_item_by_id(inv_t *inv, int id);
int get_nb_item_by_name(inv_t *inv, char *name);
int get_nb_item_by_rarity_and_type(inv_t *inv, int rarity, int type);
int get_nb_item_by_rarity_or_type(inv_t *inv, int rarity, int type);
item_t *get_random_item_by_type(inv_t *inv, int type);
item_t *get_random_item_by_rarity(inv_t *inv, int rarity);
int add_rand_nb_item_by_rarity_and_type(inv_t *inv, int nb,
int rarity, int type);
int add_rand_nb_item_by_rarity(inv_t *inv, int nb, int rarity);
int add_rand_nb_item_by_rarity_or_type(inv_t *inv, int nb,
int rarity, int type);
int add_rand_nb_item_by_type(inv_t *inv, int nb, int type);
item_t *get_random_item_by_rarity_and_type(inv_t *inv, int rarity, int type);
item_t *get_random_item_by_rarity_or_type(inv_t *inv, int rarity, int type);

int main_menu(menu_t *all);
void verif_templ(global_t *global);
void event_verif(global_t *global, sfEvent event);
void verif_key_pressed(global_t *global, sfEvent event);
