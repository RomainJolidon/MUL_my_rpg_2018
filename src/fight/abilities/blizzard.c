/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for my_rpg project
*/

#include "fight.h"

void blizzard_animation(game_t *game, int *event)
{
    if (game->c->first == NULL) {
        snow_effect(game);
        snow_effect(game);
        snow_effect(game);
    }
    if (event[0] % 2 == 0)
        game->scene->info_fight->target->e->pos.x -= 1000;
    else
        game->scene->info_fight->target->e->pos.x += 1000;
    sfSprite_setPosition(game->scene->info_fight->target->e->s, \
    game->scene->info_fight->target->e->pos);
}

void button_blizzard(game_t *game)
{
    game->scene->info_fight->to_do = do_blizzard;
    game->scene->info_fight->anim = blizzard_animation;
    game->scene->state = 5;
}

void do_blizzard(game_t *game)
{
    static int state = 0;
    static int event = 1;

    sfSprite_setPosition(game->scene->info_fight->to_play->e->s, \
    game->scene->info_fight->to_play->e->pos);
    if (game->scene->info_fight->to_play->enemy == false)
        player_attack(&state, &event, game, 5);
    else
        enemy_hit(&state, &event, game, 5);
    event++;
}