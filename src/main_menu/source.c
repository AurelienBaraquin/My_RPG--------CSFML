/*
** EPITECH PROJECT, 2023
** source.c
** File description:
** Menu RPG
*/

#include "menu.h"

int is_hovered(menu_t *all, sfRectangleShape* shape)
{
    sfVector2f mouse_pos =
    (sfVector2f){sfMouse_getPositionRenderWindow(Window).x,
    sfMouse_getPositionRenderWindow(Window).y};
    sfFloatRect bar_bounds = sfRectangleShape_getGlobalBounds(shape);
    if (sfFloatRect_contains(&bar_bounds, mouse_pos.x, mouse_pos.y))
        return 1;
    return 0;
}

int my_compute_power_rec(int nb, int power)
{
    int result = 1;
    if ( power == 0)
        return 1;
    else if ( power < 0 )
        return 0;
    else
        result = nb * my_compute_power_rec(nb, power - 1);
    return result;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
    return 0;
}

char *int_to_string2(int nb, char *string, int i)
{
    int k = 1;
    int place = i - 1;
    int temp = 0;
    while (k <= i) {
        if (k == 1)
            temp = nb % 10;
        if ( k > 1)
            temp = ((nb % my_compute_power_rec(10, k)) - (nb %
        my_compute_power_rec(10, k - 1))) / my_compute_power_rec(10, k - 1);
        string[place] = temp + '0';
        k++;
        place--;
    }
    return string;
}

char *int_to_string(int nb)
{
    int s = nb;
    int i = 1;
    while (s >= 10) {
        s = s / 10;
        i += 1;
    }
    char *string = malloc(sizeof(char) * (i + 1));
    string[i] = '\0';
    if (i == 1)
        string[0] = nb + '0';
    else
        string = int_to_string2( nb, string, i);
    return string;
}
