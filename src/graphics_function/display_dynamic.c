/*
** EPITECH PROJECT, 2019
** display_dynamic.c
** File description:
** dysplay dynamiclly every sprite
*/

#include "rpg.h"

int get_max_y(cell_t ***ground)
{
    int count = 0;

    while (ground[count] != NULL)
        count++;
    return (ground[count - 1][0]->pos.y);
}

void display_dynamic_decor(sfRenderWindow *window, cell_t **decor, int y)
{
    for (int i = 0; decor[i] != NULL; i++) {
        if (decor[i]->rect.top + decor[i]->rect.height - 32 \
<= y && decor[i]->rect.top + decor[i]->rect.height - 32 \
> y - 31)
            sfRenderWindow_drawSprite(window, decor[i]->sprite, NULL);
    }
}

void display_dynamic_pnj(sfRenderWindow *window, pnj_t **pnj, int y)
{
    for (int i = 0; pnj[i] != NULL; i++) {
        if (pnj[i]->info->pos.y <= y && pnj[i]->info->pos.y > y - 31)
            sfRenderWindow_drawSprite(window, pnj[i]->info->sprite, NULL);
    }
}

void display_dynamic(game_t *game)
{
    int max_y = get_max_y(game->map);

    for (int y = 0; y < max_y; y += 32) {
        display_dynamic_decor(game->window, game->decor, y);
        display_dynamic_pnj(game->window, game->villagers, y);
        if (game->player->player->pos.y <= y && \
game->player->player->pos.y > y - 31)
            sfRenderWindow_drawSprite(game->window, \
game->player->player->s, NULL);
    }
}