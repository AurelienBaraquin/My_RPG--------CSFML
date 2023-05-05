/*
** EPITECH PROJECT, 2023
** source2
** File description:
** RPG- Menu
*/

#include "menu.h"

int is_clicked(menu_t *all, sfRectangleShape* shape)
{
    if (Event.mouseButton.button == sfMouseLeft) {
        sfVector2f mouse_pos = (sfVector2f) {Event.mouseButton.x,
        Event.mouseButton.y};
        sfFloatRect bar_bounds = sfRectangleShape_getGlobalBounds(shape);
        if (sfFloatRect_contains(&bar_bounds, mouse_pos.x, mouse_pos.y))
            return 1;
    }
    return 0;
}

int my_strlen_menu(char *str)
{
    int i = 0;

    while (str[i])
        i++;

    return i;
}

char *my_strcat_menu(char *src, char *dest)
{
    int i = 0;
    int f = 0;
    int size = my_strlen_menu(src) + my_strlen_menu(dest);
    char *result = malloc(sizeof(char) * (size + 1));

    result[size] = '\0';
    while (i < size) {
        while (i < my_strlen_menu(src)) {
            result[i] = src[i];
            i++;
        }
        result[i] = dest[f];
        i++;
        f++;
    }
    return result;
}
