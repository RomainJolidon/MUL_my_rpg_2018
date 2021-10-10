/*
** EPITECH PROJECT, 2019
** display_particle.c
** File description:
** display particle
*/

#include "rpg.h"

void animate_par(particle_t *par)
{
    switch (par->effect) {
    case FIRE:
        fire_particle(par);
        break;
    case SNOW:
        snow_particle(par);
        break;
    case CURSOR:
        cursor_particle(par);
        break;
    case HEAL_PAR:
        heal_particle(par);
        break;
    default:
        return;
    }
}

void display_particle(game_t *game)
{
    particle_t *browse = malloc(sizeof(*browse));
    particle_t *tmp = malloc(sizeof(*tmp));
    sfRenderStates state = {.blendMode = sfBlendAdd, .shader = NULL, \
.transform = sfTransform_Identity};

    if (!browse || !tmp)
        return;
    tmp = game->p->first;
    for (browse = game->p->first; browse; browse = browse->next) {
        if (sfClock_getElapsedTime(browse->clock).microseconds >= 50) {
            animate_par(browse);
            sfClock_restart(browse->clock);
        }
        if (browse->end == 0) {
            state.texture = browse->texture;
            sfRenderWindow_drawSprite(game->window, browse->sprite, &state);
            tmp = browse;
        }
    }
}