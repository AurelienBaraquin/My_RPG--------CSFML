/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** compe
*/

#ifndef COMPE_H_
    #define COMPE_H_

    #include <SFML/Graphics.h>

    #define MAX_COMP 4
    #define MAX_POINT 10

typedef struct comp_s {
    char *name;
    int actual;
} comp_t;

// force, chance, vitesse, defense

typedef struct compl_s {
    comp_t comps[4];
    sfRectangleShape *rect;
    sfRectangleShape *point;
    // sfSprite *plus;
} compl_t;

compl_t *init_comp(void);
void disp_comp(sfRenderWindow *window, sfVector2f pos, compl_t *c, int index);

#endif /* !COMPE_H_ */
