/*
** EPITECH PROJECT, 2019
** display_scenes.c
** File description:
** display list of scenes
*/

#include "fight.h"
#include "player.h"

void game_dialog(game_t *game)
{
    sfView const *view;

    view = sfRenderWindow_getDefaultView(game->window);
    sfRenderWindow_setView(game->window, view);
    sfRenderWindow_drawSprite(game->window, game->dialog->text_bar->s, NULL);
    draw_button_game(game, game->dialog->next);
    display_villagers(game, game->dialog->status_read);
}

void game_fight(game_t *game)
{
    display_fight(game);
    if (game->transition->end != true) {
        display_transition(game->window, game->transition);
        return;
    }
    if (game->enemies)
        manage_fight(game);
    display_cursor(game);
}

void game_state(game_t *game)
{
    sfRenderWindow_setView(game->window, game->view);
    for (int y = 0; game->map[y] != NULL; y++) {
        for (int x = 0; game->map[y][x] != NULL; x++) {
            sfRenderWindow_drawSprite(game->window, \
            game->map[y][x]->sprite, NULL);
        }
    }
    display_dynamic(game);
}