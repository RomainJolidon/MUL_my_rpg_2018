/*
** EPITECH PROJECT, 2019
** anime_water.c
** File description:
** anime water in game
*/

#include "rpg.h"

void change_sprite(sfSprite *sprite, int offset, int max_value)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    if (rect.left >= max_value - offset)
        rect.left = 0;
    else
        rect.left += offset;
    sfSprite_setTextureRect(sprite, rect);
}

void is_water(cell_t **map)
{
    for (int x = 0; map[x] != NULL; x++) {
        if (map[x]->type == '0') {
            change_sprite(map[x]->sprite, 32, 160);
        }
    }
}

void anime_water(cell_t ***map, watch_t *clock)
{
    clock->seconds = clock->time.microseconds / 1000000.0;
    if (clock->seconds > 0.5) {
        for (int y = 0; map[y] != NULL; y++) {
            is_water(map[y]);
        }
        sfClock_restart(clock->clock);
    }
}

void anime_villagers(game_t *game)
{
    for (int i = 0; game->villagers[i] != NULL; i++) {
        if (game->villagers[i]->display != true)
            move_villagers(game, game->villagers[i]);
        adjust_villager_position_x(game->villagers[i]);
    }
}

void anime_world(game_t *game, watch_t *clock, watch_t *clock_player)
{
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock_player->time = sfClock_getElapsedTime(clock_player->clock);
    clock_player->seconds = clock_player->time.microseconds / 1000000.0;
    if (clock_player->seconds > 0.03) {
        anime_villagers(game);
        if (game->state == GAME && game->player->is_moving == false)
            move_player(game);
        adjust_player_position_x(game->player);
        sfClock_restart(clock_player->clock);
    }
    target_player(game);
    anime_water(game->map, clock);
    sfClock_getElapsedTime(clock->clock);

}