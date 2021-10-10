/*
** EPITECH PROJECT, 2019
** actions_buttons.c
** File description:
** list of buttons actions
*/

#include "rpg.h"

void begin_game(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->player->player->s);

    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfView_setCenter(game->view, pos);
    game->menu->selection = false;
    game->state = GAME;
}

void start_selection(game_t *game)
{
    game->menu->selection = true;
}

void start_options(game_t *game)
{
    game->state = OPTIONS;
}

void close_game(game_t *game)
{
    sfRenderWindow_close(game->window);
}