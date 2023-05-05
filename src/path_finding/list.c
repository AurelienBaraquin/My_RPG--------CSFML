/*
** EPITECH PROJECT, 2023
** list;c
** File description:
** Find Path
*/

#include "path_finding.h"

list_t *init_list(void)
{
    list_t *list = malloc(sizeof(list_t));
    deplacement_t *node = malloc(sizeof(deplacement_t));

    node->next = NULL;
    node->direction = 10;
    node->frame = 0;
    list->first = node;
    return list;
}

void delete_last_node(list_t *list)
{
    deplacement_t *node = list->first;

    while (node->next->next != NULL) {
        node = node->next;
    }
    free(node->next);
    node->next = NULL;
}

void delete_first_node(list_t *list)
{
    deplacement_t *first = list->first;

    list->first = first->next;
    free(first);
}

void add_new_node_first(list_t *list, int direction)
{
    deplacement_t *new_node = malloc(sizeof(deplacement_t));

    new_node->direction = direction;
    new_node->frame = 0;
    new_node->next = list->first;
    list->first = new_node;
}

void add_new_node_last(list_t *list, int direction)
{
    deplacement_t *new_node = malloc(sizeof(deplacement_t));
    deplacement_t *node = list->first;

    new_node->direction = direction;
    new_node->frame = 0;
    new_node->next = NULL;

    while (node->next != NULL)
        node = node->next;
    node->next = new_node;
}
