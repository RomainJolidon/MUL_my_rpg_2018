/*
** EPITECH PROJECT, 2019
** display_dialogs.c
** File description:
** display villagers dialogs
*/

#include "rpg.h"

void display_dialog(game_t *game, int status, int i)
{
    if (game->villagers[i]->text[status] == NULL) {
        if (game->villagers[i]->goal != NULL) {
            game->villagers[i]->goal(game, game->villagers[i]->object);
            game->villagers[i]->object = NONE_ITEM;
        }
        game->dialog->status_read = 0;
        game->villagers[i]->display = false;
        if (game->state == DIALOG)
            game->state = GAME;
    } else {
        sfRenderWindow_drawText(game->window, \
        game->villagers[i]->text[status]->str, NULL);
    }
}

void display_villagers(game_t *game, int status)
{
    for (int i = 0; game->villagers[i] != NULL; i++) {
        if (game->villagers[i]->display == true)
            display_dialog(game, status, i);
    }
}