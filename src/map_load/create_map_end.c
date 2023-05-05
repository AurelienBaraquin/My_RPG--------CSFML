/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** create_map.end
*/

#include "my.h"

void print_intensity(double intensity, int fd)
{
    int index = (int) (intensity * 10) + 2;
    char c = index + '0';
    if (c < 48)
        c = 0;
    else
        c -= 48;
    c /= 2;
    c += 48;
    if (c > '3')
        c = '3';
    write(fd, &c, 1);
}

int create_map(char *seed_str)
{
    srand(time(NULL));
    int seed = 0;
    if (seed_str != NULL)
        seed = my_getnbr(seed_str);
    else
        seed = rand();

    int fd = open("./map/map.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            print_intensity(perlinnoise(i,j, seed), fd);
        }
        write(fd, "\n", 1);
    }
    close(fd);
    my_putstr("Map Seed : ");
    my_put_nbr(seed);
    my_putchar('\n');
    return seed;
}

void continue_init_village(create_village_t *village,
create_struct_t *strcture)
{
    village->size = 40;
    strcture->size = 20;
    village->x = village->x_dist;
    village->y = village->y_dist;
    strcture->x = strcture->x_dist;
    strcture->y = strcture->y_dist;
}
