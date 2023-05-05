/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell1-aurelien.baraquin
** File description:
** my_putstr
*/

#include "tools.h"

int my_strlen(char *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++);
    return i;
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}

int my_getnbr(char *str)
{
    if (is_num(str[0]) == 0)
        return (-1);
    int i = 0;
    int nb = 0;
    int neg = 1;
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg = neg * -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + str[i] - '0';
        i++;
    }
    return (nb * neg);
}
