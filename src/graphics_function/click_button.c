/*
** EPITECH PROJECT, 2018
** click_button.c
** File description:
** detection of click for play and quit game
*/

#include "rpg.h"

void check_mouse_button(game_t *game, sfEvent event)
{
    static sfVector2i mouse;

    if (sfMouse_isButtonPressed(sfMouseLeft))
        click_button(mouse, game);
    mouse = sfMouse_getPositionRenderWindow(game->window);
    if (event.type == sfEvtMouseWheelScrolled) {
        zoom_screen(game, event);
    }
}

void key_events(game_t *game)
{
    sfView const *view = sfRenderWindow_getDefaultView(game->window);
    sfEvent event;
    int opened = 0;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (sfKeyboard_isKeyPressed(sfKeyQ) && game->state == GAME) {
            sfRenderWindow_setView(game->window, view);
            game->state = PAUSE;
        }
        if (sfKeyboard_isKeyPressed(sfKeyI) && opened == 0 && \
        (game->state == GAME || game->state == INVENTORY)) {
            game->state = (game->state == INVENTORY) ? GAME : INVENTORY;
            opened = 1;
        }
        if (sfKeyboard_isKeyPressed(sfKeyE) && game->state == GAME)
            talk_to_pnj(&game->state, game->villagers, \
            game->player->player->pos, game->player->dir);
    }
}

int click_events(game_t *game)
{
    static sfEvent event;

    check_mouse_button(game, event);
    return (0);
}