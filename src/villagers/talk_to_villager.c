/*
** EPITECH PROJECT, 2019
** talk_to_villager.c
** File description:
** check if talking to a villager
*/

#include "rpg.h"

bool is_a_player_y(sfVector2f player_pos, sfVector2f pnj_pos, dir_t dir, int y)
{
    if (y == player_pos.y && pnj_pos.x == player_pos.x) {
        if (y == pnj_pos.y - 32 && dir == DOWN)
            return (true);
        else if (y == pnj_pos.y + 32 && dir == UP)
            return (true);
    }
    return (false);
}

bool is_a_player_x(sfVector2f player_pos, sfVector2f pnj_pos, dir_t dir, int x)
{
    if (x == player_pos.x && pnj_pos.y == player_pos.y) {
        if (x == pnj_pos.x - 32 && dir == RIGHT)
            return (true);
        else if (x == pnj_pos.x + 32 && dir == LEFT)
            return (true);
    }
    return (false);
}

bool look_around(sfVector2f player_pos, sfVector2f pnj_pos, dir_t dir)
{
    for (int x = pnj_pos.x - 32; x <= pnj_pos.x + 32; x += 64) {
        if (x == player_pos.x && pnj_pos.y == player_pos.y)
            return (is_a_player_x(player_pos, pnj_pos, dir, x));
    }
    for (int y = pnj_pos.y - 32; y <= pnj_pos.y + 32; y += 64) {
        if (y == player_pos.y && pnj_pos.x == player_pos.x)
            return (is_a_player_y(player_pos, pnj_pos, dir, y));
    }
    return (false);
}

void orientate_villager(pnj_t *villager, dir_t dir)
{
    if (dir == LEFT)
        villager->dir = RIGHT;
    if (dir == RIGHT)
        villager->dir = LEFT;
    if (dir == UP)
        villager->dir = DOWN;
    if (dir == DOWN)
        villager->dir = UP;
}

bool talk_to_pnj(state_t *state, pnj_t **pnj, sfVector2f player_pos, \
dir_t player_dir)
{
    int i = 0;

    for (i = 0; pnj[i] != NULL; i++) {
        if (pnj[i]->info->type == '5' && \
        look_around(player_pos, pnj[i]->info->pos, player_dir) == true) {
            pnj[i]->display = true;
            orientate_villager(pnj[i], player_dir);
            *state = DIALOG;
            return (true);
        }
    }
    return (false);
}