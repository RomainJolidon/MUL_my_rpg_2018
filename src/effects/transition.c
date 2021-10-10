/*
** EPITECH PROJECT, 2019
** transition.c
** File description:
** create and anime transition
*/

#include "rpg.h"

void rester_transition(transition_t *transition)
{
    if (transition->fading != NULL)
        sfRectangleShape_destroy(transition->fading);
    if (transition->clock != NULL)
        sfClock_destroy(transition->clock->clock);
}

void display_transition(sfRenderWindow *window, transition_t *transition)
{
    sfColor color = sfRectangleShape_getFillColor(transition->fading);

    if (color.a == 0 || transition->end == true) {
        if (color.a == 0)
            transition->end = true;
        rester_transition(transition);
        transition->clock = NULL;
        transition->fading = NULL;
        return;
    }
    transition->clock->time = sfClock_getElapsedTime(transition->clock->clock);
    transition->clock->seconds = \
transition->clock->time.microseconds / 1000000.0;
    if (transition->clock->seconds > 0.005) {
        color.a -= 5;
        sfRectangleShape_setFillColor(transition->fading, color);
        sfClock_restart(transition->clock->clock);
    }
    sfRenderWindow_drawRectangleShape(window, transition->fading, NULL);
}

transition_t *create_transition(transition_t *transition)
{
    sfVector2f size = {960, 800};

    if (!transition)
        transition = malloc(sizeof(transition_t));
    if (!transition)
        return (NULL);
    transition->fading = sfRectangleShape_create();
    transition->clock = time_creator();
    sfRectangleShape_setFillColor(transition->fading, sfWhite);
    sfRectangleShape_setSize(transition->fading, size);
    transition->end = false;
    return (transition);
}