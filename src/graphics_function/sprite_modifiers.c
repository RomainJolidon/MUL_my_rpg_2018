/*
** EPITECH PROJECT, 2018
** sprite_modifier.c
** File description:
** modification for sprites
*/

#include "rpg.h"

void set_sprite_vertical(sfIntRect *rect, int value)
{
    rect->top = value;
}

void change_sprite_horizontale(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left >= max_value - offset)
        rect->left = 0;
    else
        rect->left += offset;
}
