/*
** EPITECH PROJECT, 2018
** display_window.c
** File description:
** display window of the gamee
*/

#include "fight.h"
#include "player.h"

void events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        key_events(game);
    }
}

void screen_reloading_hud(game_t *game)
{
    if (game->state == INVENTORY) {
        game_state(game);
        display_inventory(game, game->inv);
    }
    if (game->state == PAUSE) {
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        display_pause(game);
    }
    if (game->state == OPTIONS) {
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        display_option(game);
    }
    if (game->state == HOW_TO_PLAY) {
        display_ctrl(game);
    }
}

void screen_reloading(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    if (game->state == DIALOG) {
        game_state(game);
        game_dialog(game);
    }
    if (game->state == MENU) {
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        display_menu(game);
    }
    if (game->state == FIGHT)
        game_fight(game);
    if (game->state == GAME) {
        game_state(game);
        display_story(game);
    }
    screen_reloading_hud(game);
    display_particle(game);
    sfRenderWindow_display(game->window);
}

int gaming(game_t *game)
{
    watch_t *clock = time_creator();
    watch_t *clock_player = time_creator();

    game_preparation(game);
    while (sfRenderWindow_isOpen(game->window)) {
        music_manager(game);
        screen_reloading(game);
        anime_world(game, clock, clock_player);
        update_quest(game);
        events(game);
    }
    destroy_music_tab(game);
    destroy_inv(game->inv);
    return (SUCCESS);
}