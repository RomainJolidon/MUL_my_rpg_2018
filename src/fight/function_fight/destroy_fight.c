/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "memory.h"

void destroy_fight(scene_t *scene)
{
    if (scene == NULL)
        return;
    for (int i = 0; scene->action[i] != NULL; i++) {
        for (int j = 0; scene->action[i]->button[j] != NULL; j++)
            free_button(scene->action[i]->button[j]);
        for (int j = 0; scene->action[i]->button_text[j] != NULL; j++)
            sfText_destroy(scene->action[i]->button_text[j]);
        free(scene->action[i]);
    }
    free(scene->action);
}