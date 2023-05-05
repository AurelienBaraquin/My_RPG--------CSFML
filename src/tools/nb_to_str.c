/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** nb_to_str
*/

#include "my.h"

char *nb_to_str(int nb)
{
    char *str = malloc(sizeof(char) * 10);
    int i = 0, tmp = 0;
    if (nb == 0) {
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    while (nb > 0) {
        tmp = nb % 10;
        nb = nb / 10;
        str[i] = tmp + 48;
        i++;
    }
    str[i] = '\0';
    for (int k = 0; k < i / 2; k++) {
        tmp = str[k];
        str[k] = str[i - k - 1];
        str[i - k - 1] = tmp;
    }
    return str;
}
