/*
** EPITECH PROJECT, 2018
** display_window.c
** File description:
** display window of the gamee
*/

#include "rpg.h"

bool is_all_enemies_dead(game_t *game)
{
    for (int i = 0; game->enemies[i] != NULL; i++) {
        if (game->enemies[i]->played != 3)
            return (false);
    }
    return (true);
}

bool is_all_heroes_dead(game_t *game)
{
    for (int i = 0; game->characters[i] != NULL; i++) {
        if (game->characters[i]->played != 3)
            return (false);
    }
    return (true);
}

void game_over(game_t *game)
{
    end_combat(game);
    sfRenderWindow_close(game->window);
}