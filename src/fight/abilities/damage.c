/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "rpg.h"

void damage_text(game_t *game, fight_t *info_fight, sfText *damage)
{
    sfVector2f pos = info_fight->target->e->pos;

    pos.y = info_fight->target->e->pos.y - 50;
    pos.x = info_fight->target->e->pos.x + 50;
    sfText_setString(damage, \
    int_to_str(game->scene->info_fight->to_play->stats->atk * -1));
    sfText_setFillColor(damage, sfRed);
    sfText_setFont(damage, game->font[0]);
    sfText_setPosition(damage, pos);
}

void deal_dommage(game_t *game, int attack)
{
    game->scene->info_fight->target->stats->hp -= attack;
    if (game->scene->info_fight->target->stats->hp <= 0)
        game->scene->info_fight->target->played = 2;
}

void end_of_attack(game_t *game)
{
    game->scene->state = 6;
    game->scene->info_fight->animation = NULL;
    game->scene->info_fight->to_play = NULL;
}
