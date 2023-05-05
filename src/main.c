/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    if (open("./map/map.txt", O_RDONLY) == -1)
        create_villages(create_map(NULL));
    return game();
    (void) av;
    (void) ac;
}
