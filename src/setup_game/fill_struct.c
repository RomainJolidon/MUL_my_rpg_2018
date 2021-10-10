/*
** EPITECH PROJECT, 2018
** main_menu.c
** File description:
** main menu of game
*/

#include "rpg.h"

sfVector2i fill_vector_2i(int x, int y)
{
    sfVector2i pos;

    pos.x = x;
    pos.y = y;
    return (pos);
}

sfVector2f fill_vector_2f(float x, float y)
{
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    return (pos);
}

sfIntRect fill_intrect(int top, int left, int height, int width)
{
    sfIntRect size;

    size.top = top;
    size.left = left;
    size.height = height;
    size.width = width;
    return (size);
}

sfIntRect *fill_addr_intrect(int top, int left, int height, int width)
{
    sfIntRect *size = malloc(sizeof(*size));

    size->top = top;
    size->left = left;
    size->height = height;
    size->width = width;
    return (size);
}