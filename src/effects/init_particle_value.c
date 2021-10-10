/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_particle_value
*/

#include "rpg.h"
#include "define.h"

particle_value_t init_snow_value(void)
{
    particle_value_t val;

    val.angle = (rand() % 90) * (M_PI / 180);
    val.vel = (rand() % 20) + 10;
    val.scale = fill_vector_2f(0.8, 1);
    val.pos = fill_vector_2f(rand() % WIDTH, 0);
    val.value = 0;
    val.effect = SNOW;
    return (val);
}

particle_value_t init_fire_value(float x, float y)
{
    particle_value_t val;

    val.angle = -((rand() % 90) + 45) * (M_PI / 180);
    val.vel = 3;
    val.scale = fill_vector_2f(0.5, 1);
    val.pos = fill_vector_2f(x, y);
    val.value = 0;
    val.effect = FIRE;
    return (val);
}

particle_value_t init_cursor_value(float x, float y)
{
    particle_value_t val;

    val.angle = (rand() % 360) * (M_PI / 180);
    val.vel = (rand() % 2) + 1;
    val.scale = fill_vector_2f(0.5, 0.5);
    val.pos = fill_vector_2f(x, y);
    val.value = 255;
    val.effect = CURSOR;
    return (val);
}

particle_value_t init_heal_value(float x, float y)
{
    particle_value_t val;
    float pos_x = (rand() % 100) - 50 + x;

    val.angle = 90 * (M_PI / 180);
    val.vel = 1;
    val.scale = fill_vector_2f(0.1, 0.3);
    val.pos = fill_vector_2f(pos_x, y);
    val.value = 255;
    val.effect = HEAL_PAR;
    return (val);
}