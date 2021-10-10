/*
** EPITECH PROJECT, 2018
** display_window.c
** File description:
** display window of the gamee
*/

#include "memory.h"

void manage_exp(stats_t *stats)
{
    stats->exp += rand() % 10 + 1;
    if (stats->exp >= 100) {
        stats->level++;
        stats->exp -= 100;
    }
}

void end_combat(game_t *game)
{
    sfRenderWindow_setView(game->window, game->view);
    game->win_fight = true;
    game->state = GAME;
    free_character_tab(game->enemies);
    game->enemies = NULL;
    for (int i = 0; game->characters[i] != NULL; i++) {
        if (game->characters[i]->played != 3) {
            game->characters[i]->played = 0;
            manage_exp(game->characters[i]->stats);
        }
    }
}

int pos_chara(game_t *game, character_t *character)
{
    for (int i = 0; game->enemies[i] != NULL; i++) {
        if (game->enemies[i] == character)
            return (i);
    }
    for (int i = 0; game->characters[i] != NULL; i++) {
        if (game->characters[i] == character)
            return (i);
    }
    return (-1);
}

void death_animation(game_t *game)
{
    sfVector2f pos = {2000, 2000};
    character_t *to_play = game->scene->info_fight->to_play;
    int pos_en = pos_chara(game, to_play);

    sfSprite_setPosition(game->scene->info_fight->to_play->e->s, pos);
    if (game->scene->info_fight->to_play->enemy == true) {
        sfSprite_setPosition(game->scene->action[5]->button[pos_en]->e->s, pos);
        sfText_setPosition(game->scene->action[5]->button_text[pos_en], pos);
    } else {
        sfSprite_setPosition(game->scene->action[7]->button[pos_en]->e->s, pos);
        sfText_setPosition(game->scene->action[7]->button_text[pos_en], pos);
    }
    game->scene->state = 6;
    game->scene->info_fight->to_play->played = 3;
    game->scene->info_fight->animation = NULL;
    game->scene->info_fight->to_play = NULL;
}

int check_death(game_t *game)
{
    for (int i = 0; game->characters[i] != NULL; i++) {
        if (game->characters[i]->played == 2) {
            game->scene->info_fight->to_play = game->characters[i];
            game->scene->info_fight->animation = death_animation;
            return (1);
        }
    }
    for (int i = 0; game->enemies[i] != NULL; i++) {
        if (game->enemies[i]->played == 2) {
            game->scene->info_fight->to_play = game->enemies[i];
            game->scene->info_fight->animation = death_animation;
            return (1);
        }
    }
    return (0);
}