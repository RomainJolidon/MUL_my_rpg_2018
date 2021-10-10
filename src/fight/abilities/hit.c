/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "fight.h"

void hit_animation(game_t *game, int *event)
{
    if (game->c->first == NULL)
        cursor(game, game->scene->info_fight->target->e->pos.x + 60, \
        game->scene->info_fight->target->e->pos.y + 60, 2);
    if (event[0] % 2 == 0)
        game->scene->info_fight->target->e->pos.x -= 1000;
    else
        game->scene->info_fight->target->e->pos.x += 1000;
    sfSprite_setPosition(game->scene->info_fight->target->e->s, \
    game->scene->info_fight->target->e->pos);
}

void button_hit(game_t *game)
{
    game->scene->info_fight->to_do = do_hit;
    game->scene->info_fight->anim = hit_animation;
    game->scene->state = 5;
}

void do_hit(game_t *game)
{
    static int state = 0;
    static int event = 1;

    sfSprite_setPosition(game->scene->info_fight->to_play->e->s, \
    game->scene->info_fight->to_play->e->pos);
    if (game->scene->info_fight->to_play->enemy == false)
        player_attack(&state, &event, game, 3);
    else
        enemy_hit(&state, &event, game, 3);
    event++;
}