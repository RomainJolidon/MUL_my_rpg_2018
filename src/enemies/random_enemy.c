/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "fight.h"

attack_t **init_enemy_power(void)
{
    attack_t **to_return = load_attack();
    if (!to_return)
        return (NULL);
    to_return[0]->name = my_strdup("Hit");
    to_return[0]->type = MELEE;
    to_return[0]->button_funct = button_hit;
    to_return[1]->name = my_strdup("Hit");
    to_return[1]->type = MELEE;
    to_return[1]->button_funct = button_hit;
    to_return[2]->name = my_strdup("Hit");
    to_return[2]->type = MELEE;
    to_return[2]->button_funct = button_hit;
    return (to_return);
}

void load_random_enemy(character_t **enemy, sfVector2i pos)
{
    int random;
    character_t *(*enemy_load[3])(character_t *, int, int) = {
        init_bird,
        init_slug,
        init_reptile
    };
    random = rand() % 3;
    enemy[0] = enemy_load[random](enemy[0], pos.x, pos.y);
    enemy[0]->played = 0;
    enemy[0]->attack = init_enemy_power();
}