/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "fight.h"

void player_attack(int *state, int *event, game_t *game, int sound)
{
    damage_text(game, game->scene->info_fight, game->scene->info_fight->damage);
    if (state[0] == 0) {
        game->scene->info_fight->to_play->e->pos.x -= 1;
        if (game->scene->info_fight->to_play->e->pos.x == 730) {
            state[0] = 1;
            deal_dommage(game, game->scene->info_fight->to_play->stats->atk);
            sfMusic_play(game->music[sound]);
        }
    }
    else if (state[0] == 1) {
        sfRenderWindow_drawText(game->window, \
        game->scene->info_fight->damage, NULL);
        game->scene->info_fight->anim(game, event);
        game->scene->info_fight->to_play->e->pos.x += 1;
        if (game->scene->info_fight->to_play->e->pos.x == 750) {
            state[0] = 0;
            end_of_attack(game);
        }
    }
}

void enemy_back(game_t *game, int *event)
{
    sfRenderWindow_drawText(game->window, \
    game->scene->info_fight->damage, NULL);
    game->scene->info_fight->to_play->e->pos.x -= 1;
    game->scene->info_fight->anim(game, event);
}

void enemy_hit(int *state, int *event, game_t *game, int sound)
{
    static int base_pos = 0;

    damage_text(game, game->scene->info_fight, game->scene->info_fight->damage);
    if (game->scene->info_fight->to_play->e->pos.x == 150 \
|| game->scene->info_fight->to_play->e->pos.x == 300)
        base_pos = game->scene->info_fight->to_play->e->pos.x;
    if (state[0] == 0) {
        game->scene->info_fight->to_play->e->pos.x += 1;
        if (game->scene->info_fight->to_play->e->pos.x == (base_pos + 20)) {
            state[0] = 1;
            deal_dommage(game, game->scene->info_fight->to_play->stats->atk);
            sfMusic_play(game->music[sound]);
        }
    } else if (state[0] == 1) {
        enemy_back(game, event);
        if (game->scene->info_fight->to_play->e->pos.x == base_pos) {
            state[0] = 0;
            end_of_attack(game);
            base_pos = 0;
        }
    }
}