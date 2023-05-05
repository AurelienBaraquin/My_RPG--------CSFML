/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-lemin-alexis.belmonte
** File description:
** is_num
*/

#include "tools.h"

int is_num(char str)
{
    if (str < '0' || str > '9')
        return (0);
    return (1);
}

int is_char(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < 'a' || str[i] > 'z')
            return (0);
        i++;
    }
    return (1);
}
