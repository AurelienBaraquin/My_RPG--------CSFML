/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** entity_attack
*/

#include "my.h"

void attack_entity(entity_t *entity, entity_t *target)
{
    if (entity == NULL || target == NULL || entity == target
    || entity->type == target->type)
        return;
    if (get_distance_between_entity(entity, target) > entity->stats->range)
        return;
    int damage;
    if (ENT_A->ANI_S == IS_ATTACK && get_max_frame_animation(entity)
    <= entity->animations->frame_rect.left) {
        damage = entity->stats->strength -
        (entity->stats->strength * target->stats->defense / 100);
        if (damage < 0)
            damage = 1;
        target->stats->hp -= damage;
    }
    if (target->stats->hp <= 0) {
        change_animation_state(target, IS_DIE);
        target->stats->hp = 0;
    }
}

void attack_target_in_range(entity_t *entity,
entity_list_t *entity_list, int range)
{
    if (entity == NULL || entity_list == NULL || range < 0)
        return;
    entity_list_t *tmp2 = entity_list;
    while (tmp2 != NULL) {
        if (entity->type != tmp2->entity->type &&
        get_max_frame_animation(entity)
        <= entity->animations->frame_rect.left && entity != tmp2->entity &&
        get_distance_between_entity(entity, tmp2->entity) <= range) {
            attack_entity(entity, tmp2->entity);
        }
        tmp2 = tmp2->next;
    }
}

void attack_entity_loop_update(entity_list_t *entity_list,
entity_list_t *tmp, entity_t *target)
{
    if (tmp->entity->type == HOSTILE && get_distance_between_entity
    (entity_list->entity, tmp->entity) <=
    get_stats_value(tmp->entity, "range")) {
        change_animation_state(tmp->entity, IS_ATTACK);
        tmp->entity->direction = get_direction_between_entity
        (tmp->entity, entity_list->entity);
    }
    if (get_entity_by_id(entity_list, 0)->animations->ANI_S != IS_DIE &&
    target != NULL && get_distance_between_entity(entity_list->entity, target)
    <= get_stats_value(entity_list->entity, "range")) {
        change_animation_state(entity_list->entity, IS_ATTACK);
        entity_list->entity->direction = get_direction_between_entity
        (entity_list->entity, target);
    }
    if (tmp->entity->animations->ANI_S == IS_ATTACK &&
    get_max_frame_animation(tmp->entity) <=
    tmp->entity->animations->frame_rect.left) {
        attack_target_in_range(tmp->entity, entity_list,
        get_stats_value(tmp->entity, "range"));
    }
}

void attack_entity_update(entity_list_t *entity_list)
{
    if (entity_list == NULL)
        return;
    entity_list_t *tmp = entity_list;
    entity_t* target = get_locked_entity(entity_list);
    while (tmp != NULL) {
        if (tmp->entity->animations->ANI_S == IS_DIE) {
            tmp = tmp->next;
            continue;
        }
        attack_entity_loop_update(entity_list, tmp, target);
        tmp = tmp->next;
    }
    if (target && target->stats->hp == 0)
        lock_function(entity_list);
}
