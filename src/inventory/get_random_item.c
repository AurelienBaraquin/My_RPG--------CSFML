/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** get_random_item
*/

#include "my.h"
#include "inventory.h"

    // CONSOMMABLE give health = to stat
    // WEAPON add damage = damage + damage * stat / 10;
    // ARMOR add damage_taken = damage_taken - (damage_taken * stat / 100);

    #define NB_CONSUMABLE 13
    #define NB_WEAPON 14
        

const item_t itm[] = {
    {1, "apple", 2, CONSUMABLE, COMMON, "./assets/items/items.png",
        (sfIntRect){0, 0, 48, 48}, 10},
    {2, "steak", 2, CONSUMABLE, COMMON, "./assets/items/items.png",
        (sfIntRect){48, 0, 48, 48}, 20},
    {3, "cheese", 2, CONSUMABLE, COMMON, "./assets/items/items.png",
        (sfIntRect){96, 0, 48, 48}, 10},
    {4, "fish", 2, CONSUMABLE, COMMON, "./assets/items/items.png",
        (sfIntRect){144, 0, 48, 48}, 20},
    {5, "chicken", 3, CONSUMABLE, COMMON, "./assets/items/items.png",
        (sfIntRect){192, 0, 48, 48}, 20},
    {6, "cake", 10, CONSUMABLE, RARE, "./assets/items/items.png",
        (sfIntRect){240, 0, 48, 48}, 100},
    {7, "blue-berrie", 2, CONSUMABLE, COMMON, "./assets/items/items.png",
        (sfIntRect){288, 0, 48, 48}, 10},
    {8, "carrot", 2, CONSUMABLE, COMMON, "./assets/items/items.png",
        (sfIntRect){336, 0, 48, 48}, 15},
    {9, "poutine", 10, CONSUMABLE, RARE, "./assets/items/items.png",
        (sfIntRect){384, 0, 48, 48}, 100},
    {10, "ice-cream", 4, CONSUMABLE, COMMON, "./assets/items/items.png",
        (sfIntRect){432, 0, 48, 48}, 25},
    {11, "mushroom", 2, CONSUMABLE, COMMON, "./assets/items/items.png",
        (sfIntRect){470, 0, 48, 48}, 15},
    {12, "salad", 3, CONSUMABLE, COMMON, "./assets/items/items.png",
        (sfIntRect){0, 48, 48, 48}, 18},
    {13, "sushi", 4, CONSUMABLE, COMMON, "./assets/items/items.png",
        (sfIntRect){0, 96, 48, 48}, 25},
    {14, "stone sword", 20, WEAPON, COMMON, "./assets/items/items.png",
        (sfIntRect){0, 144, 48, 48}, 10},
    {15, "iron sword", 30, WEAPON, COMMON, "./assets/items/items.png",
        (sfIntRect){48, 144, 48, 48}, 15},
    {16, "heavy sword", 35, WEAPON, COMMON, "./assets/items/items.png",
        (sfIntRect){96, 144, 48, 48}, 20},
    {17, "shadow sword", 400, WEAPON, EPIC, "./assets/items/items.png",
        (sfIntRect){144, 144, 48, 48}, 100},
    {18, "golden heavy sword", 230, WEAPON, RARE, "./assets/items/items.png",
        (sfIntRect){192, 144, 48, 48}, 50},
    {19, "fire sword", 270, WEAPON, RARE, "./assets/items/items.png",
        (sfIntRect){384, 144, 48, 48}, 65},
    {20, "livid saber", 1500, WEAPON, LEGENDARY, "./assets/items/items.png",
        (sfIntRect){470, 144, 48, 48}, 350},
    {21, "murasama", 10000, WEAPON, LEGENDARY, "./assets/items/items.png",
        (sfIntRect){614, 144, 48, 48}, 1000},
    {22, "alien scythe", 255, WEAPON, RARE, "./assets/items/items.png",
        (sfIntRect){470, 192, 48, 48}, 60},
    {23, "leather armor", 50, ARMOR, COMMON, "./assets/items/items.png",
        (sfIntRect){96, 384, 48, 48}, 10},
    {24, "metal armor", 100, ARMOR, RARE, "./assets/items/items.png",
        (sfIntRect){144, 384, 48, 48}, 20},
    {25, "golden armor", 250, ARMOR, RARE, "./assets/items/items.png",
        (sfIntRect){192, 384, 48, 48}, 30},
    {26, "ancient armor", 600, ARMOR, EPIC, "./assets/items/items.png",
        (sfIntRect){240, 384, 48, 48}, 50},
    {27, "livid armor", 2500, ARMOR, LEGENDARY, "./assets/items/items.png",
        (sfIntRect){288, 384, 48, 48}, 80},
    {28, "heal potion", 10, CONSUMABLE, COMMON, "./assets/items/heal_potion.png",
        (sfIntRect){0, 0, 384, 384}, 100},
    {29, "stone dagger", 20, WEAPON, COMMON, "./assets/items/items.png",
        (sfIntRect){0, 192, 48, 48}, 12},
    {30, "iron dagger", 30, WEAPON, COMMON, "./assets/items/items.png",
        (sfIntRect){48, 192, 48, 48}, 22},
    {31, "shadow dagger", 420, WEAPON, EPIC, "./assets/items/items.png",
        (sfIntRect){96, 192, 48, 48}, 110},
    {32, "ancient dagger", 500, WEAPON, EPIC, "./assets/items/items.png",
        (sfIntRect){144, 192, 48, 48}, 135},
    {33, "god of war", 900, WEAPON, EPIC, "./assets/items/items.png",
        (sfIntRect){384, 192, 48, 48}, 260},
    {0, NULL, 0, 0, 0, NULL,
        (sfIntRect) {0, 0, 0, 0}, 0},
};

item_t *get_random_item_by_type(inv_t *inv, int type)
{
    int nb = 0;
    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (itm_const[i].type == type)
            nb++;
    }
    int random = mlrand(0, nb);
    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (random == 0 && itm_const[i].type == type)
            return (&itm_const[i]);
        if (itm_const[i].type == type)
            random--;
    }
    return (NULL);
}

item_t *get_random_item_by_rarity(inv_t *inv, int rarity)
{
    int nb = 0;
    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (itm_const[i].rarity == rarity)
            nb++;
    }
    int random = mlrand(0, nb);
    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (random == 0 && itm_const[i].rarity == rarity)
            return (&itm_const[i]);
        if (itm_const[i].rarity == rarity)
            random--;
    }
    return (NULL);
}

item_t *get_random_item_by_rarity_and_type(inv_t *inv, int rarity, int type)
{
    int nb = 0;
    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (itm_const[i].rarity == rarity && itm_const[i].type == type)
            nb++;
    }
    int random = mlrand(0, nb);
    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (random == 0 && itm_const[i].rarity == rarity
        && itm_const[i].type == type)
            return (&itm_const[i]);
        if (itm_const[i].rarity == rarity && itm_const[i].type == type)
            random--;
    }
    return (NULL);
}

item_t* get_random_item_by_rarity_or_type(inv_t *inv, int rarity, int type)
{
    int nb = 0;
    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (itm_const[i].rarity == rarity || itm_const[i].type == type)
            nb++;
    }
    int random = mlrand(0, nb);
    for (int i = 0; i < (int)(sizeof(itm_const) / sizeof(itm_const[0])); i++) {
        if (random == 0 && itm_const[i].rarity == rarity ||
        itm_const[i].type == type)
            return (&itm_const[i]);
        if (itm_const[i].rarity == rarity || itm_const[i].type == type)
            random--;
    }
    return (NULL);
}
