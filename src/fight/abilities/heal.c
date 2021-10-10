/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "fight.h"

void heal_animation(game_t *game, int *event)
{
    if (game->c->first == NULL)
        heal_effect(game, game->scene->info_fight->target->e->pos.x \
        , game->scene->info_fight->target->e->pos.y);
    if (event[0] % 2 == 0)
        game->scene->info_fight->target->e->pos.x -= 1000;
    else
        game->scene->info_fight->target->e->pos.x += 1000;
    sfSprite_setPosition(game->scene->info_fight->target->e->s, \
    game->scene->info_fight->target->e->pos);
}

void deal_heal(game_t *game)
{
    int heal = game->scene->info_fight->target->stats->hp_max \
    * 20 / 100;
    game->scene->info_fight->target->stats->hp += (int) heal;
    if (game->scene->info_fight->target->stats->hp > \
    game->scene->info_fight->target->stats->hp_max) {
        game->scene->info_fight->target->stats->hp = \
        game->scene->info_fight->target->stats->hp_max;
    }
}

void player_heal(int *state, int *event, game_t *game, int sound)
{
    if (state[0] == 0) {
        game->scene->info_fight->to_play->e->pos.x -= 1;
        if (game->scene->info_fight->to_play->e->pos.x == 730) {
            state[0] = 1;
            deal_heal(game);
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

void button_heal(game_t *game)
{
    game->scene->info_fight->to_do = do_heal;
    game->scene->info_fight->anim = heal_animation;
    game->scene->state = 7;
}

void do_heal(game_t *game)
{
    static int state = 0;
    static int event = 1;

    sfSprite_setPosition(game->scene->info_fight->to_play->e->s, \
    game->scene->info_fight->to_play->e->pos);
    player_heal(&state, &event, game, 6);
    event++;
}