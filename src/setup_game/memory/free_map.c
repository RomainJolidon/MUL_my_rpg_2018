/*
** EPITECH PROJECT, 2019
** free_map.c
** File description:
** free all related to map
*/

#include "memory.h"

void free_cell(cell_t *cell)
{
    if (cell != NULL) {
        sfSprite_destroy(cell->sprite);
        free(cell);
    }
}

void free_story(story_t **story)
{
    if (story == NULL)
        return;
    for (int i = 0; story[i] != NULL; i++) {
        free_dialogues(story[i]->infos);
        free(story[i]);
    }
    free(story);
}

void free_villagers(pnj_t **villagers)
{
    if (villagers == NULL)
        return;
    for (int i = 0; villagers[i] != NULL; i++) {
        free_cell(villagers[i]->info);
        free_dialogues(villagers[i]->text);
        free(villagers[i]);
    }
    free(villagers);
}

void free_decor(cell_t **decor)
{
    if (decor == NULL)
        return;
    for (int i = 0; decor[i] != NULL; i++)
        free(decor[i]);
    free(decor);
}

void free_map(cell_t ***map)
{
    if (map == NULL)
        return;
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != NULL; x++)
            free_cell(map[y][x]);
        free(map[y]);
    }
    free(map);
}