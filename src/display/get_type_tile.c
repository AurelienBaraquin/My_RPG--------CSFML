/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** get_type_tile
*/

#include "my.h"

int get_village_type(char c)
{
    if (c == '1')
        return VILLAGE_ONE;
    if (c == '2')
        return VILLAGE_TWO;
    if (c == '3')
        return VILLAGE_THREE;

    return VILLAGE_ONE;
}

int get_sand_type(char c)
{
    if (c <= '0')
        return SANDS_ARID;
    if (c == '1')
        return SANDS_SEC;
    if (c == '2')
        return SANDS_HUMID;
    if (c >= '3')
        return WATER;

    return SANDS_SEC;
}

int get_cactus_next(char c)
{
    switch (c) {
        case 'F':
            return CACTUS_6;
        case 'G':
            return CACTUS_7;
        case 'H':
            return CACTUS_8;
        case 'I':
            return CACTUS_9;
        case 'J':
            return CACTUS_10;
        case 'K':
            return CACTUS_11;
        case 'L':
            return CACTUS_12;
        case 'M':
            return CACTUS_13;
        case 'N':
            return CACTUS_14;
    }
}

int get_cactus_type(char c)
{
    switch (c) {
        case 'A':
            return CACTUS_1;
        case 'B':
            return CACTUS_2;
        case 'C':
            return CACTUS_3;
        case 'D':
            return CACTUS_4;
        case 'E':
            return CACTUS_5;
    }
    return get_cactus_next(c);
}
