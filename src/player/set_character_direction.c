/*
** EPITECH PROJECT, 2019
** set_player_direction.c
** File description:
** set player direction
*/

#include "rpg.h"

void set_character_position(sfSprite *sprite, sfIntRect *rect, dir_t dir)
{
    if (dir == UP)
        set_sprite_vertical(rect, 96);
    if (dir == DOWN)
        set_sprite_vertical(rect, 0);
    if (dir == LEFT)
        set_sprite_vertical(rect, 32);
    if (dir == RIGHT)
        set_sprite_vertical(rect, 64);
    sfSprite_setTextureRect(sprite, *rect);
}

void set_character_dir(dir_t *dir, int value, char type)
{
    if (type == 'x') {
        if (value == -32)
            *dir = LEFT;
        if (value == 32)
            *dir = RIGHT;
    }
    if (type == 'y') {
        if (value == -32)
            *dir = UP;
        if (value == 32)
            *dir = DOWN;
    }
}