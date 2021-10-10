/*
** EPITECH PROJECT, 2019
** get_inv_info.c
** File description:
** get inventory informations
*/

#include "rpg.h"

int count_item_in_line(inventory_t *inv, obj_value_t object, int y)
{
    int count = 0;

    for (int x = 0; x < 8; x++) {
        if (inv->obj[y][x].obj != NULL && \
            my_strcmp(sfText_getString(inv->obj[y][x].name), object.name) == 0)
            count++;
    }
    return (count);
}

int count_item_in_inv(inventory_t *inv, obj_value_t object)
{
    int count = 0;

    for (int y = 0; y < 4; y++) {
        count += count_item_in_line(inv, object, y);
    }
    return (count);
}