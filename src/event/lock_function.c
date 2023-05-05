/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** lock_function
*/

#include "my.h"

void lock_function(entity_list_t *entity_list)
{
    const int range = POS(20);
    if (get_entity_in_range_by_type(entity_list,
    PLAYER_ENTITY(entity_list), range, HOSTILE) == -1) {
        unlock_all_entity(entity_list);
        return;
    }
    static int index = 0;
    index++;
    if (index > get_nb_entity_by_type(entity_list, HOSTILE))
        index = 1;
    if (get_distance_between_entity(PLAYER_ENTITY(entity_list),
    get_entity_by_type(entity_list, HOSTILE, index)) > range) {
        lock_function(entity_list);
        return;
    }
    unlock_all_entity(entity_list);
    lock_entity(entity_list, get_id_of_entity(entity_list,
    get_entity_by_type(entity_list, HOSTILE, index)));
}
