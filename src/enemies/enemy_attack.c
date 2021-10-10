/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "rpg.h"

character_t *choose_target(character_t **characters)
{
    int target = 0;
    character_t *to_return = NULL;
    srand(time(NULL));

    while (to_return == NULL) {
        target = rand() % 4;
        if (characters[target]->stats->hp > 0)
            to_return = characters[target];
    }
    return (to_return);
}

void enemy_attack(game_t *game)
{
    int power;
    srand(time(NULL));
    power = rand() % 3;
    game->scene->info_fight->target = choose_target(game->characters);
    game->scene->info_fight->to_play->attack[power]->button_funct(game);
    game->scene->info_fight->animation = game->scene->info_fight->to_do;
    game->scene->state = 6;
}