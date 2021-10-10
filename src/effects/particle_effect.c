/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fire_particule
*/

#include "rpg.h"
#include "define.h"


int cursor_effect(game_t *game)
{
    float x = sfMouse_getPositionRenderWindow(game->window).x;
    float y = sfMouse_getPositionRenderWindow(game->window).y;
    particle_t *par = create_particle(CURSOR_VALUE(x, y));

    particle(game, par);
    return (0);
}

void cursor_particle(particle_t *par)
{
    sfVector2f pos = sfSprite_getPosition(par->sprite);

    pos.x += par->x;
    pos.y += par->y;
    sfSprite_setPosition(par->sprite, pos);
    sfSprite_setColor(par->sprite, \
sfColor_fromRGBA(100, 50, 255, par->value));
    par->value-=2;
    if (par->value < 0)
        par->end = 1;
}

void fire_particle(particle_t *par)
{
    sfVector2f vec = sfSprite_getPosition(par->sprite);
    float dif;

    vec.x += par->x;
    vec.y += par->y;
    dif = par->base_y - vec.y;
    sfSprite_setPosition(par->sprite, vec);
    if (dif < 100)
        sfSprite_setColor(par->sprite, \
sfColor_fromRGBA(255, 100 - dif, 0, 200 - dif));
    if (dif >= 300 || vec.x > par->base_x + 40 || vec.x < par->base_x - 40)
        par->end = 1;
}

void snow_particle(particle_t *par)
{
    sfVector2f pos = sfSprite_getPosition(par->sprite);

    pos.x += par->x;
    pos.y += par->y;
    sfSprite_setPosition(par->sprite, pos);
    if (pos.y >= HEIGHT) {
        par->end = 1;
        return;
    }
    if (HEIGHT - pos.y < 255)
        sfSprite_setColor(par->sprite, \
sfColor_fromRGBA(255, 255, 255, HEIGHT - pos.y));
}

void heal_particle(particle_t *par)
{
    sfVector2f pos = sfSprite_getPosition(par->sprite);

    pos.x += par->x;
    pos.y += par->y;
    sfSprite_setPosition(par->sprite, pos);
    if (par->value > 2)
        par->value-=2;
    else {
        par->end = 1;
        return;
    }
    sfSprite_setColor(par->sprite, \
sfColor_fromRGBA(0, 255, 0, par->value));
}