/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** particle
*/

#include "rpg.h"
#include "define.h"

void set_particle_attribute(particle_t *par, particle_value_t val)
{
    sfSprite_setOrigin(par->sprite, \
fill_vector_2f(MIDDLE_PARTICLE, MIDDLE_PARTICLE));
    sfSprite_setTexture(par->sprite, par->texture, sfFalse);
    sfSprite_setTextureRect(par->sprite, SIZE_PARTICLE);
    sfSprite_setPosition(par->sprite, val.pos);
    sfSprite_setScale(par->sprite, val.scale);
}

particle_t *create_particle(particle_value_t val)
{
    particle_t *par = malloc(sizeof(*par));

    if (!par)
        return (NULL);
    par->texture = sfTexture_createFromFile(PATH_PARTICLE, NULL);
    par->sprite = sfSprite_create();
    par->clock = sfClock_create();
    par->end = 0;
    par->next = NULL;
    par->base_y = val.pos.y;
    par->base_x = val.pos.x;
    par->x = -val.vel * cosf(val.angle);
    par->y = val.vel * sinf(val.angle);
    par->value = val.value;
    par->effect = val.effect;
    set_particle_attribute(par, val);
    return (par);
}

particle_f *init_particle(void)
{
    particle_f *ret = malloc(sizeof(*ret));

    if (!ret)
        return (NULL);
    ret->first = NULL;
    return (ret);
}

void particle(game_t *game, particle_t *particle)
{
    particle_t *browse = malloc(sizeof(*browse));

    if (!particle || !browse)
        return;
    if (!game->p->first) {
        game->p->first = particle;
    } else {
        browse = game->p->first;
        while (browse->next) {
            browse = browse->next;
        }
        browse->next = particle;
    }
}

void free_particle(game_t *game)
{
    particle_t *browse;
    particle_t *tmp;

    browse = game->p->first;
    while (browse) {
        tmp = browse;
        browse = browse->next;
        sfClock_destroy(tmp->clock);
        sfSprite_destroy(tmp->sprite);
        sfTexture_destroy(tmp->texture);
        free(tmp);
    }
    game->p->first = NULL;
}