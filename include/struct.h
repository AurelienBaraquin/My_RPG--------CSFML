/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include "my.h"

    #define STRUCT_ONE_SIZE_X 10
    #define STRUCT_ONE_SIZE_Y 10

typedef struct create_structure {
    int size;
    int x_dist;
    int y_dist;
    int x;
    int y;
    char structure;
} create_struct_t;


#endif /* !STRUCT_H_ */
