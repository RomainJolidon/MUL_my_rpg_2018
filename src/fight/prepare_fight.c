/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "player.h"

void load_font(game_t *game)
{
    game->font = malloc(sizeof(*game->font) * 2);
    game->font[1] = NULL;
    game->font[0] = sfFont_createFromFile(PATH_PIXEL_F);
}

int prepare_fight(game_t *game)
{
    load_font(game);
    game->win_fight = false;
    game->enemies = init_enemies_tab();
    if (load_fight_element(game) == ERROR)
        return (ERROR);
    game->scene->info_fight->arrow = \
    sprite_creator("assets/fight/arrow.png", 999, 999);
    game->c = init_cursor();
    return (SUCCESS);
}