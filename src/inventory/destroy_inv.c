/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018d
** File description:
** destroy_inv
*/

#include "memory.h"

void free_object(object_t obj)
{
    if (obj.obj != NULL)
        free_entity(obj.obj);
    if (obj.name != NULL) {
        sfText_destroy(obj.name);
        sfText_destroy(obj.detail);
    }
}

void destroy_inv(inventory_t *inv)
{
    free_entity(inv->hud);
    free_entity(inv->pointer);
    free_entity(inv->info->infobox);
    free_entity(inv->info->layer);
    for (int y = 0; y != 4; y++) {
        for (int x = 0; x != 8; x++) {
            free_object(inv->obj[y][x]);
        }
    }
    free(inv->info);
    free(inv);
}