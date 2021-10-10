/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for my_rpg project
*/

#include "rpg.h"

void destroy_player(game_t *game)
{
    if (!game->characters)
        return;
    for (int i = 0; game->characters[i] != NULL; i++) {
        sfSprite_destroy(game->characters[i]->e->s);
        sfTexture_destroy(game->characters[i]->e->t);
        free(game->characters[i]->e);
        free(game->characters[i]->stats);
        sfRectangleShape_destroy(game->characters[i]->healthbackground);
        sfRectangleShape_destroy(game->characters[i]->healthbar);
        free(game->characters[i]->name);
        for (int j = 0; game->characters[i]->attack[j] != NULL; j++) {
            free(game->characters[i]->attack[j]->name);
            free(game->characters[i]->attack[j]);
        }
        free(game->characters[i]->attack);
        free(game->characters[i]);
    }
    free(game->characters);
}