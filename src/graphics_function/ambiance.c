/*
** EPITECH PROJECT, 2018
** main_menu.c
** File description:
** main menu of game
*/

#include "rpg.h"

void destroy_music_tab(game_t *game)
{
    for (int i = 0; game->music[i] != NULL; i++)
        sfMusic_destroy(game->music[i]);
}

void create_music_tab(game_t *game)
{
    game->music = malloc(sizeof(sfMusic *) * 8);
    game->music[0] = music_creator("assets/music/city_music.ogg", 25, true);
    game->music[1] = music_creator("assets/music/combat_music.ogg", 35, true);
    game->music[2] = music_creator("assets/music/menu_music.ogg", 35, true);
    game->music[3] = \
music_creator("assets/sound_effects/hit_se.ogg", 100, false);
    game->music[4] = \
music_creator("assets/sound_effects/click_se.ogg", 100, false);
    game->music[5] = \
music_creator("assets/sound_effects/fire_se.ogg", 100, false);
    game->music[6] = \
music_creator("assets/sound_effects/healing_se.ogg", 50, false);
    game->music[7] = NULL;
}

void stop_playing_current_music(game_t *game)
{
    for (int i = 0; game->music[i] != NULL; i++) {
        if (sfMusic_getStatus(game->music[i]) == sfPlaying)
            sfMusic_stop(game->music[i]);
    }
}

void change_current_music_volume(game_t *game, bool volume)
{
    float current_volume = 0;

    for (int i = 0; game->music[i] != NULL; i++) {
        current_volume = sfMusic_getVolume(game->music[i]);
        if (current_volume + 5 >= 0 && current_volume + 5 <= 100 && \
            volume == true)
            sfMusic_setVolume(game->music[i], (current_volume + 5));
        if (current_volume - 5 >= 0 && current_volume - 5 <= 100 && \
            volume == false)
            sfMusic_setVolume(game->music[i], (current_volume - 5));
    }
}

void music_manager(game_t *game)
{
    if (game->state == MENU && \
    sfMusic_getStatus(game->music[2]) == sfStopped) {
        stop_playing_current_music(game);
        sfMusic_play(game->music[2]);
    }
    if (game->state == GAME && \
    sfMusic_getStatus(game->music[0]) == sfStopped) {
        stop_playing_current_music(game);
        sfMusic_play(game->music[0]);
    }
    if (game->state == FIGHT && \
    sfMusic_getStatus(game->music[1]) == sfStopped) {
        stop_playing_current_music(game);
        sfMusic_play(game->music[1]);
    }
}