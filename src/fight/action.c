/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "fight.h"
#include "memory.h"

void fight(game_t *game)
{
    int i = 0;
    for (; game->characters[i] != game->scene->info_fight->to_play; i++);
    game->scene->state = i + 1;
}

void return_action(game_t *game)
{
    game->scene->state = 0;
}

void object(game_t *game)
{
    (void) game;
}

void defend(game_t *game)
{
    (void) game;
}

void flee(game_t *game)
{
    if (rand() % 100 < 50) {
        if (game->scene->info_fight->to_play)
            game->scene->info_fight->to_play->played = 1;
        game->scene->state = 6;
        game->scene->info_fight->animation = NULL;
        game->scene->info_fight->to_play = NULL;
        return;
    }
    sfRenderWindow_setView(game->window, game->view);
    game->state = GAME;
    free_character_tab(game->enemies);
    game->enemies = NULL;
    for (int i = 0; game->characters[i] != NULL; i++) {
        if (game->characters[i]->played != 3)
            game->characters[i]->played = 0;
    }
}