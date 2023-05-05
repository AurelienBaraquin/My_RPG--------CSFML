/*
** EPITECH PROJECT, 2023
** source2.c
** File description:
** Find Path
*/

#include "path_finding.h"

int is_there_this_char(char *str, char c, int start, int stop)
{
    int i = start;

    while (i <= stop) {
        if (str[i] == c)
            return -1;
        i++;
    }
    return 0;
}

int rows_nb(char **tab)
{
    int size = 0;

    while (tab[size] != NULL) {
        size++;
    }
    return size;
}
