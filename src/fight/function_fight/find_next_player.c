/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** find_next_player
*/

#include "rpg.h"

void find_next_player(game_t *game)
{
    int speed = 0;
    character_t *player = NULL;
    for (int i = 0; game->characters[i] != NULL; i++) {
        if (game->characters[i]->stats->speed > speed \
        && game->characters[i]->played == 0) {
            player = game->characters[i];
            speed = game->characters[i]->stats->speed;
        }
    }
    for (int i = 0; game->enemies[i] != NULL; i++) {
        if (game->enemies[i]->stats->speed > speed \
        && game->enemies[i]->played == 0) {
            player = game->enemies[i];
            speed = game->enemies[i]->stats->speed;
        }
    }
    game->scene->info_fight->to_play = player;
    if (player != NULL)
        player->played = 1;
}