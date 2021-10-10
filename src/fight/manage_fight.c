/*
** EPITECH PROJECT, 2018
** display_window.c
** File description:
** display window of the gamee
*/

#include "fight.h"

void check_life(game_t *game)
{
    float hp_size = 0;

    sfVector2f length;
    length.y = 20;
    for (int i = 0; game->characters[i] != NULL; i++) {
        if (game->characters[i]->stats->hp < 0)
            game->characters[i]->stats->hp = 0;
        hp_size = ((float) (game->characters[i]->stats->hp) / \
        (float) (game->characters[i]->stats->hp_max)) * 200;
        length.x = hp_size;
        if (hp_size < 100)
            sfRectangleShape_setFillColor(game->characters[i]->healthbar, \
            sfYellow);
        else if (hp_size >= 100)
            sfRectangleShape_setFillColor(game->characters[i]->healthbar, \
            sfGreen);
        sfRectangleShape_setSize(game->characters[i]->healthbar, length);
    }
}

void reset_character(game_t *game)
{
    for (int i = 0; game->characters[i] != NULL; i++) {
        if (game->characters[i]->played < 2)
            game->characters[i]->played = 0;
    }
    for (int i = 0; game->enemies[i] != NULL; i++) {
        if (game->enemies[i]->played < 2)
            game->enemies[i]->played = 0;
    }
}

void arrow_position(game_t *game)
{
    if (game->scene->info_fight->to_play == NULL)
        return;
    sfVector2f change_pos = \
game->scene->info_fight->to_play->e->pos;
    change_pos.x += 65;
    change_pos.y += 5;
    sfSprite_setPosition(game->scene->info_fight->arrow->s, change_pos);
    sfRenderWindow_drawSprite(game->window, \
    game->scene->info_fight->arrow->s, NULL);
}

void check_turn(game_t *game)
{
    if (game->scene->info_fight->to_play == NULL) {
        find_next_player(game);
        if (game->scene->info_fight->to_play == NULL) {
            reset_character(game);
            return;
        }
        if (!game->scene->info_fight->to_play->enemy)
            game->scene->state = 0;
        else
            enemy_attack(game);
    }
}

void manage_fight(game_t *game)
{
    event_fight(game);
    check_life(game);
    if (game->scene->info_fight->animation) {
        game->scene->info_fight->animation(game);
        return;
    }
    arrow_position(game);
    if (is_all_heroes_dead(game) == true) {
        game_over(game);
        return;
    }
    if (check_death(game) == 1)
        return;
    check_turn(game);
    if (is_all_enemies_dead(game) == true)
        end_combat(game);
}