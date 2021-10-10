/*
** EPITECH PROJECT, 2019
** setup_inventory.c
** File description:
** setup inventory
*/

#include "rpg.h"

void set_status_xp(inventory_t *inv, character_t **characters)
{
    int count = 0;
    int pos_x[4] = {585, 630, 680, 725};

    inv->stats_xp = malloc(sizeof(text_t *) * 17);
    if (!inv->stats_xp)
        return;
    for (int i = 0; characters[i] != NULL; i++) {
        inv->stats_xp[count] = text_creator("/100", "assets/font/pixel.ttf", \
        fill_vector_2i(540, pos_x[i]), 20);
        inv->stats_xp[count + 1] = \
        text_creator("lvl", "assets/font/pixel.ttf", \
        fill_vector_2i(590, pos_x[i]), 20);
        inv->stats_xp[count + 2] = \
        text_creator(int_to_str(characters[i]->stats->exp), \
        "assets/font/pixel.ttf", fill_vector_2i(520, pos_x[i]), 20);
        inv->stats_xp[count + 3] = \
        text_creator(int_to_str(characters[i]->stats->level), \
        "assets/font/pixel.ttf", fill_vector_2i(630, pos_x[i]), 20);
        count += 4;
    }
    inv->stats_xp[16] = NULL;
}

sfVector2i find_place_in_inv(inventory_t *inv)
{
    sfVector2i pos = {0, 0};

    while (pos.y < 4) {
        while (pos.x < 8 && inv->obj[pos.y][pos.x].obj != NULL)
            pos.x++;
        if (inv->obj[pos.y][pos.x].obj == NULL)
            return (pos);
        pos.y++;
        pos.x = 0;
    }
    pos.x = -1;
    pos.y = -1;
    return (pos);
}

void setup_inventory(inventory_t *inv)
{
    add_new_object(HEAL_POTION, find_place_in_inv(inv), inv);
    add_new_object(MANA_POTION, find_place_in_inv(inv), inv);
    add_new_object(GOLD, find_place_in_inv(inv), inv);
    add_new_object(SILVER, find_place_in_inv(inv), inv);
    add_new_object(COPPER, find_place_in_inv(inv), inv);
    add_new_object(BOW, find_place_in_inv(inv), inv);
    add_new_object(SWORD, find_place_in_inv(inv), inv);
    add_new_object(RING, find_place_in_inv(inv), inv);
    add_new_object(STAFF, find_place_in_inv(inv), inv);
    add_new_object(SHIELD, find_place_in_inv(inv), inv);
}