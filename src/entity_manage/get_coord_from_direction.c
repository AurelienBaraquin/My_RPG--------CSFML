/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** get_coord_from_direction
*/

#include "my.h"

sfVector2f get_coord_from_direction(int direction, int speed)
{
    if (direction < 0 || direction > 3)
        return ((sfVector2f) {0, 0});
    if (speed < 0)
        return ((sfVector2f) {0, 0});
    sfVector2f coord = {0, 0};
    if (direction == UP)
        coord.y = -speed;
    if (direction == RIGHT)
        coord.x = speed;
    if (direction == DOWN)
        coord.y = speed;
    if (direction == LEFT)
        coord.x = -speed;
    return coord;
}
