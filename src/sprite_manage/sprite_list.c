/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** sprite_list
*/

#include "my.h"

const texture_element_t texture_list[] = {
    {"assets/characters/player.png", (sfIntRect){0, 0, 64, 64}},
    {"assets/tyles/sands.png", (sfIntRect){0, 0, 32, 32}},
    {"assets/tyles/sands.png", (sfIntRect){0, 32, 32, 32}},
    {"assets/tyles/sands.png", (sfIntRect){0, 64, 32, 32}},
    {"assets/tyles/water_full.png", (sfIntRect){0, 0, 32, 32}},
    {"assets/village/village_one.png", (sfIntRect){0, 0, 1024, 1024}},
    {"assets/village/village_two.png", (sfIntRect){0, 0, 640, 576}},
    {"assets/village/village_three.png", (sfIntRect){0, 0, 800, 800}},
    {"assets/characters/skeleton.png", (sfIntRect){0, 0, 64, 64}},
    {"assets/characters/animals/pig.png", (sfIntRect){0, 0, 62, 62}},
    {"assets/structures/pyramid_two.png", (sfIntRect){0, 0, 320, 320}},
    {"assets/characters/zombie.png", (sfIntRect){0, 0, 64, 64}},
    {"assets/items/heal_potion.png", (sfIntRect){0, 0, 384, 384}},
    {"assets/labyrinth/temple.png", (sfIntRect){0, 0, 3072, 4160}},
    {"assets/environment/cactus_one_by_one.png", (sfIntRect){0, 0, 32, 32}},
    {"assets/environment/cactus_one_by_one.png", (sfIntRect){32, 0, 32, 32}},
    {"assets/environment/cactus_one_by_one.png", (sfIntRect){64, 0, 32, 32}},
    {"assets/environment/cactus_one_by_one.png", (sfIntRect){96, 0, 32, 32}},
    {"assets/environment/cactus_one_by_one.png", (sfIntRect){128, 0, 32, 32}},
    {"assets/environment/cactus_one_by_one.png", (sfIntRect){160, 0, 32, 32}},
    {"assets/environment/cactus_one_by_one.png", (sfIntRect){192, 0, 32, 32}},
    {"assets/environment/cactus_one_by_one.png", (sfIntRect){224, 0, 32, 32}},
    {"assets/environment/cactus_one_by_one.png", (sfIntRect){256, 0, 32, 32}},
    {"assets/environment/cactus_one_by_one.png", (sfIntRect){288, 0, 32, 32}},
    {"assets/environment/cactus_one_by_one.png", (sfIntRect){320, 0, 32, 32}},
    {"assets/environment/cactus_one_by_one.png", (sfIntRect){352, 0, 32, 32}},
    {"assets/environment/cactus_one_by_one.png", (sfIntRect){384, 0, 32, 32}},
    {"assets/environment/cactus_one_by_one.png", (sfIntRect){416, 0, 32, 32}},
    {"assets/labyrinth/chest.png", (sfIntRect){0, 0, 96, 96}},
    {"assets/characters/alien.png", (sfIntRect){0, 0, 64, 64}},
    {"assets/characters/jackolantern.png", (sfIntRect){0, 0, 64, 64}},
    {"assets/characters/robot.png", (sfIntRect){0, 0, 64, 64}},
    {"assets/characters/orc.png", (sfIntRect){0, 0, 64, 64}}
};

int texture_list_size(void)
{
    return sizeof(texture_list) / sizeof(texture_list[0]);
}

sprite_t** init_sprite_list(void)
{
    sprite_t **sprite_list = malloc(sizeof(sprite_t *) * texture_list_size());
    for (int i = 0; i < texture_list_size(); i++) {
        sprite_list[i] = malloc(sizeof(sprite_t));
        sprite_list[i]->texture = sfTexture_createFromFile
        (texture_list[i].filepath, NULL);
        sprite_list[i]->sprite = sfSprite_create();
        sprite_list[i]->type = i;
        sprite_list[i]->rect = texture_list[i].rect;
        sprite_list[i]->base_pos = (sfVector2f){texture_list[i].rect.left,
        texture_list[i].rect.top};
        sfSprite_setTexture(sprite_list[i]->sprite,
            sprite_list[i]->texture, sfTrue);
        sfSprite_setTextureRect(sprite_list[i]->sprite, sprite_list[i]->rect);
        sfSprite_setPosition(sprite_list[i]->sprite, (sfVector2f){0, 0});
    }
    return sprite_list;
}

void destroy_sprite_list(sprite_t **sprite_list)
{
    for (int i = 0; i < texture_list_size(); i++) {
        sfSprite_destroy(sprite_list[i]->sprite);
        sfTexture_destroy(sprite_list[i]->texture);
        free(sprite_list[i]);
    }
    free(sprite_list);
}

void draw_sprite(sprite_t *sprite, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
}

void set_sprite_position(sprite_t *sprite, sfVector2f position)
{
    sfSprite_setPosition(sprite->sprite, position);
}
