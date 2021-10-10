/*
** EPITECH PROJECT, 2019
** free_scenes.c
** File description:
** free all scenes
*/

#include "memory.h"

void free_transition(transition_t *transition)
{
    if (transition == NULL)
        return;
    if (transition->fading != NULL)
        sfRectangleShape_destroy(transition->fading);
    if (transition->clock != NULL)
        free_watch(transition->clock);
}

void free_controls(control_t **controls)
{
    if (controls == NULL)
        return;
    for (int i = 0; controls[i] != NULL; i++) {
        free_entity(controls[i]->e);
        free_text(controls[i]->text);
        free(controls[i]);
    }
    free(controls);
}

void free_pause(pause_t *pause)
{
    if (pause == NULL)
        return;
    free_buttons(pause->button);
    free(pause);
}

void free_options(option_t *options)
{
    if (options == NULL)
        return;
    free_buttons(options->button);
    free(options);
}

void free_dialog_struct(dialog_t *dialog)
{
    if (dialog == NULL)
        return;
    free_entity(dialog->text_bar);
    free_button(dialog->next);
    free(dialog);
}