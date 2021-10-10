/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "rpg.h"

void display_character(game_t *game)
{
    for (int i = 0; game->characters[i] != NULL; i++) {
        sfRenderWindow_drawSprite(game->window, \
        game->characters[i]->e->s, NULL);
    }
    for (int i = 0; game->enemies[i] != NULL; i++) {
        sfRenderWindow_drawSprite(game->window, \
        game->enemies[i]->e->s, NULL);
    }
}

void display_hud(action_t *action, game_t *game)
{
    for (int i = 0; action->button[i] != NULL; i++)
        draw_button_game(game, action->button[i]);
    for (int i = 0; action->button_text[i] != NULL; i++)
        sfRenderWindow_drawText(game->window, action->button_text[i], NULL);
    for (int i = 0; game->characters[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(game->window, \
        game->characters[i]->healthbackground, NULL);
        sfRenderWindow_drawRectangleShape(game->window, \
        game->characters[i]->healthbar, NULL);
        sfRenderWindow_drawSprite(game->window, \
        game->characters[i]->icon->s, NULL);
    }
}

void display_entity(entity_t *entity, game_t *game)
{
    sfRenderWindow_drawSprite(game->window, entity->s, NULL);
}

void display_fight(game_t *game)
{
    display_entity(game->scene->bckgrnd, game);
    display_entity(game->scene->front, game);
    display_character(game);
    display_hud(game->scene->action[game->scene->state], game);
}
