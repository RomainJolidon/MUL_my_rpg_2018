/*
** EPITECH PROJECT, 2019
** connect_texture.c
** File description:
** connect texture
*/

#include "rpg.h"

void get_connection_3_4_v(cell_t ***map, int x, int y, sfTexture *texture[5])
{
    if (map[y - 1][x]->type == '0' && map[y + 1][x]->type == '0' && \
    map[y][x - 1]->type == '0') {
        sfSprite_setTexture(map[y][x]->sprite, texture[3], sfTrue);
        sfSprite_rotate(map[y][x]->sprite, 90);
        return;
    }
    if (map[y - 1][x]->type == '0' && map[y + 1][x]->type == '0' && \
    map[y][x + 1]->type == '0') {
        sfSprite_setTexture(map[y][x]->sprite, texture[3], sfTrue);
        sfSprite_rotate(map[y][x]->sprite, -90);
        return;
    }
    get_connection_oppos(map, x, y, texture);
}

void get_connection_3_4_h(cell_t ***map, int x, int y, sfTexture *texture[5])
{
    if (map[y][x -1]->type == '0' && map[y][x + 1]->type == '0' && \
    map[y - 1][x]->type == '0') {
        sfSprite_setTexture(map[y][x]->sprite, texture[3], sfTrue);
        sfSprite_rotate(map[y][x]->sprite, 180);
        return;
    }
    if (map[y][x -1]->type == '0' && map[y][x + 1]->type == '0' && \
    map[y + 1][x]->type == '0') {
        sfSprite_setTexture(map[y][x]->sprite, texture[3], sfTrue);
        return;
    }
    get_connection_3_4_v(map, x, y, texture);
}

void get_connection_full(cell_t ***map, int x, int y, sfTexture *texture[5])
{
    if (map[y + 1] == NULL || map[y][x + 1] == NULL || \
        x - 1 < 0 || y - 1 < 0 || map[y][x]->type != '1')
        return;
    if (map[y][x -1]->type == '0' && map[y][x + 1]->type == '0' && \
    map[y - 1][x]->type == '0' && map[y + 1][x]->type == '0') {
        sfSprite_setTexture(map[y][x]->sprite, texture[4], sfTrue);
        return;
    }
    get_connection_3_4_h(map, x, y, texture);
}

void connect_texture(cell_t ***map)
{
    sfTexture *texture[5];

    texture[0] = sfTexture_createFromFile("assets/connected_tiles/\
side_grass.png", NULL);
    texture[1] = sfTexture_createFromFile("assets/connected_tiles/\
extern_side_grass_bl.png", NULL);
    texture[2] = sfTexture_createFromFile("assets/connected_tiles/\
opposite_side_grass.png", NULL);
    texture[3] = sfTexture_createFromFile("assets/connected_tiles/\
3_4_side_grass_bottom.png", NULL);
    texture[4] = sfTexture_createFromFile("assets/connected_tiles/\
full_side_grass.png", NULL);
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != NULL; x++) {
            get_connection_full(map, x, y, texture);
        }
    }
}