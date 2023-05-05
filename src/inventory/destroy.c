/*
** EPITECH PROJECT, 2023
** test
** File description:
** destroy
*/

#include "inventory.h"
#include <stdlib.h>

void destroy_inv(inv_t *inv)
{
    free(inv->curr);
    sfText_destroy(inv->text);
    free(inv);
}
