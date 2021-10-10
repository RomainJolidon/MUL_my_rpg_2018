/*
** EPITECH PROJECT, 2019
** actions_effect.c
** File description:
** actions effect
*/

#include "rpg.h"

int heal_effect(game_t *game, float x, float y)
{
    particle_t *par = create_particle(HEAL_VALUE(x, y));

    particle(game, par);
    display_particle(game);
    return (0);
}

int fire_effect(game_t *game, float x, float y)
{
    particle_t *par = create_particle(FIRE_VALUE(x, y));

    particle(game, par);
    return (0);
}

int snow_effect(game_t *game)
{
    particle_t *par = NULL;

    for (int i = 0; i != 3; i++) {
        par = create_particle(SNOW_VALUE);
        particle(game, par);
    }
    return (0);
}