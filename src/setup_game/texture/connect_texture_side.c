/*
** EPITECH PROJECT, 2019
** connect_texture.c
** File description:
** connect texture
*/

#include "rpg.h"

void get_connection_simple(cell_t ***map, int x, int y, sfTexture *texture[5])
{
    if (map[y][x -1]->type == '0') {
        sfSprite_setTexture(map[y][x]->sprite, texture[0], sfTrue);
        sfSprite_rotate(map[y][x]->sprite, 90);
        return;
    }
    if (map[y][x + 1]->type == '0') {
        sfSprite_setTexture(map[y][x]->sprite, texture[0], sfTrue);
        sfSprite_rotate(map[y][x]->sprite, -90);
        return;
    }
    if (map[y - 1][x]->type == '0') {
        sfSprite_setTexture(map[y][x]->sprite, texture[0], sfTrue);
        sfSprite_rotate(map[y][x]->sprite, 180);
        return;
    }
    if (map[y + 1][x]->type == '0') {
        sfSprite_setTexture(map[y][x]->sprite, texture[0], sfTrue);
        return;
    }
}

void get_connection_corner(cell_t ***map, int x, int y, sfTexture *texture[5])
{
    if (map[y][x -1]->type == '0' && map[y - 1][x]->type == '0') {
        sfSprite_setTexture(map[y][x]->sprite, texture[1], sfTrue);
        sfSprite_rotate(map[y][x]->sprite, 90);
        return;
    }
    if (map[y][x -1]->type == '0' && map[y + 1][x]->type == '0') {
        sfSprite_setTexture(map[y][x]->sprite, texture[1], sfTrue);
        return;
    }
    if (map[y][x + 1]->type == '0' && map[y - 1][x]->type == '0') {
        sfSprite_setTexture(map[y][x]->sprite, texture[1], sfTrue);
        sfSprite_rotate(map[y][x]->sprite, 180);
        return;
    }
    if (map[y][x + 1]->type == '0' && map[y + 1][x]->type == '0') {
        sfSprite_setTexture(map[y][x]->sprite, texture[1], sfTrue);
        sfSprite_rotate(map[y][x]->sprite, -90);
        return;
    }
    get_connection_simple(map, x, y, texture);
}

void get_connection_oppos(cell_t ***map, int x, int y, sfTexture *texture[5])
{
    if (map[y][x -1]->type == '0' && map[y][x + 1]->type == '0') {
        sfSprite_setTexture(map[y][x]->sprite, texture[2], sfTrue);
        sfSprite_rotate(map[y][x]->sprite, 90);
        return;
    }
    if (map[y - 1][x]->type == '0' && map[y + 1][x]->type == '0') {
        sfSprite_setTexture(map[y][x]->sprite, texture[2], sfTrue);
        return;
    }
    get_connection_corner(map, x, y, texture);
}