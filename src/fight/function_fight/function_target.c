/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "rpg.h"

void choose_target_one(game_t *game)
{
    if (game->enemies[0]->played > 1)
        return;
    game->scene->info_fight->target = game->enemies[0];
    game->scene->state = 6;
    game->scene->info_fight->animation = game->scene->info_fight->to_do;
}

void choose_target_two(game_t *game)
{
    if (game->enemies[1]->played > 1)
        return;
    game->scene->info_fight->target = game->enemies[1];
    game->scene->state = 6;
    game->scene->info_fight->animation = game->scene->info_fight->to_do;
}

void choose_target_three(game_t *game)
{
    if (game->enemies[2]->played > 1)
        return;
    game->scene->info_fight->target = game->enemies[2];
    game->scene->state = 6;
    game->scene->info_fight->animation = game->scene->info_fight->to_do;
}