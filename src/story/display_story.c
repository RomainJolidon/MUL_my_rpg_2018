/*
** EPITECH PROJECT, 2019
** display_story.c
** File description:
** display quest info
*/

#include "rpg.h"

void display_quest(sfRenderWindow *window, story_t *story)
{
    for (int i = 0; story->infos[i] != NULL; i++)
        sfRenderWindow_drawText(window, story->infos[i]->str, NULL);
}

void display_story(game_t *game)
{
    sfView const *view = sfRenderWindow_getDefaultView(game->window);

    sfRenderWindow_setView(game->window, view);
    if (game->story[0] == NULL)
        return;
    display_quest(game->window, game->story[0]);
}