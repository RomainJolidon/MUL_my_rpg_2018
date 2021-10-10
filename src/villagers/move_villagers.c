/*
** EPITECH PROJECT, 2019
** move_villagers.c
** File description:
** move villagers in map
*/

#include "rpg.h"

int collision_pnj(game_t *game, int value, pnj_t *villager)
{
    int y = 0;
    int x = -1;

    while (game->map[y] != NULL) {
        x = find_cell(game->map[y], villager->dest);
        if (x > -1)
            break;
        y++;
    }
    if (x == -1 || game->map[y] == NULL)
        return (value);
    if (game->player->player->pos.x == villager->dest.x || \
        game->player->player->pos.y == villager->dest.y)
        return (value);
    if (game->map[y][x]->type != '0' && \
        collide_decor(game, villager->dest) == false)
        return (0);
    return (value);
}

void move_villagers_x(game_t *game, pnj_t *villager)
{
    int size[2] = {-32, 32};
    int rand_move = 0;

    for (int i = 60; i < 100; i++) {
        rand_move = (rand() % i);
        if (rand_move== sfKeyLeft || rand_move == sfKeyRight) {
            villager->dest.x += size[rand_move - sfKeyLeft];
            villager->dest.x += collision_pnj(game, \
            (size[rand_move - sfKeyLeft] * -1), villager);
            villager->info->rect.left = villager->dest.x;
            set_character_dir(&villager->dir, size[rand_move - sfKeyLeft], 'x');
        }
    }
}

void move_villagers_y(game_t *game, pnj_t *villager)
{
    int size[2] = {-32, 32};
    int rand_move = 0;

    if (villager->is_moving == true)
        return;
    for (int i = 60; i < 100; i++) {
        rand_move = (rand() % i);
        if (rand_move== sfKeyUp || rand_move == sfKeyDown) {
            villager->dest.y += size[rand_move - sfKeyUp];
            villager->dest.y += collision_pnj(game, \
            (size[rand_move - sfKeyUp] * -1), villager);
            villager->info->rect.top = villager->dest.y;
            set_character_dir(&villager->dir, size[rand_move - sfKeyUp], 'y');
        }
    }
}

void move_villagers(game_t *game, pnj_t *villager)
{
    if (villager->is_moving == true)
        return;
    if (rand() % 20 != 0)
        return;
    move_villagers_x(game, villager);
    move_villagers_y(game, villager);
}