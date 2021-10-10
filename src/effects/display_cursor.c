/*
** EPITECH PROJECT, 2019
** display_cursor.c
** File description:
** display cursor
*/

#include "rpg.h"

int animate_sprite(cursor_t *cur, int move, int max)
{
    int top = sfSprite_getTextureRect(cur->sprite).top;
    int left = sfSprite_getTextureRect(cur->sprite).left + move;
    int width = sfSprite_getTextureRect(cur->sprite).width;
    int height = sfSprite_getTextureRect(cur->sprite).height;

    if (left >= max) {
        left = 1;
        cur->end = 1;
        return (0);
    }
    cur->rect.top = top;
    cur->rect.left = left;
    cur->rect.width = width;
    cur->rect.height = height;
    sfSprite_setTextureRect(cur->sprite, cur->rect);
    return (1);
}

void display_cursor(game_t *game)
{
    cursor_t *browse;

    for (browse = game->c->first; browse; browse = browse->next) {
        if (sfClock_getElapsedTime(browse->clock).microseconds >= 50000) {
            animate_sprite(browse, 189, 2800);
            sfClock_restart(browse->clock);
        }
        if (browse->end == 0) {
            sfRenderWindow_drawSprite(game->window, browse->sprite, NULL);
        } else {
            game->c->first = NULL;
        }
    }
}