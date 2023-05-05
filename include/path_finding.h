/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** path_finding
*/

#ifndef PATH_H_
    #define PATH_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <SFML/System/Vector2.h>
    #define UP 0
    #define RIGHT 3
    #define DOWN 2
    #define LEFT 1
    #define INT_MAX 2147483647
    #define HELP all->help
    #define ANNL add_new_node_last
    #define ROW all->row
    #define COL all->cols

typedef struct deplacement_s {
    int direction;
    int frame;
    struct deplacement_s *next;
} deplacement_t;

typedef struct list_s {
    deplacement_t *first;
} list_t;

typedef struct global_s {
    char **map;
    int **help;
    int x_sign;
    int y_sign;
    int row;
    int cols;
    sfVector2f dep;
    sfVector2f arr;
    sfVector2f pos1;
    sfVector2f pos2;
    sfVector2f dis;
    int is_blocked;
    int size;
} global_t;

char **my_str_to_tab(char *str, char *sep);

list_t *init_list(void);

void add_new_node_last(list_t *list, int direction);

void add_new_node_first(list_t *list, int direction);

void delete_first_node(list_t *list);

void delete_last_node(list_t *list);

int is_there_this_char(char *str, char c, int start, int stop);

int rows_nb(char **tab);

int cols_nb(char *str);

void is_not_blocked(global_t *all, list_t *list);

void find_way(global_t *all, list_t *list);

void is_blocked(global_t *all, list_t *list);

int the_smallest(int nb1, int nb2, int nb3);

void y_pos_x_pos(global_t *all, list_t *list);

void y_neg_x_neg(global_t *all, list_t *list);

void y_neg_x_pos(global_t *all, list_t *list);

void y_pos_x_neg(global_t *all, list_t *list);

int check_right(global_t *all);

int check_left(global_t *all);

int check_up(global_t *all);

int check_down(global_t *all);

void unblock(global_t *all, list_t *list);

int always_pos(int nb);

int is_line_blocked(global_t *all, int cols, int start, int stop);

void inverse_list(list_t *list);

void init_help(global_t *all);

#endif /* !PATH_H_ */
