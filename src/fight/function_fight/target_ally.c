/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "rpg.h"

void choose_ally_one(game_t *game)
{
    if (game->characters[0]->played > 1)
        return;
    game->scene->info_fight->target = game->characters[0];
    game->scene->state = 6;
    game->scene->info_fight->animation = game->scene->info_fight->to_do;
}

void choose_ally_two(game_t *game)
{
    if (game->characters[1]->played > 1)
        return;
    game->scene->info_fight->target = game->characters[1];
    game->scene->state = 6;
    game->scene->info_fight->animation = game->scene->info_fight->to_do;
}

void choose_ally_three(game_t *game)
{
    if (game->characters[2]->played > 1)
        return;
    game->scene->info_fight->target = game->characters[2];
    game->scene->state = 6;
    game->scene->info_fight->animation = game->scene->info_fight->to_do;
}

void choose_ally_four(game_t *game)
{
    if (game->characters[3]->played > 1)
        return;
    game->scene->info_fight->target = game->characters[3];
    game->scene->state = 6;
    game->scene->info_fight->animation = game->scene->info_fight->to_do;
}