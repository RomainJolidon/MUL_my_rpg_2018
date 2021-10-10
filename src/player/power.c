/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for my_rpg project
*/

#include "fight.h"

attack_t **load_attack(void)
{
    attack_t **to_return = malloc(sizeof(*to_return) * 4);
    if (!to_return)
        return (NULL);
    to_return[3] = NULL;
    for (int i = 0; i < 3; i++)
        to_return[i] = malloc(sizeof(**to_return));
    return (to_return);
}

attack_t **init_hero_power(void)
{
    attack_t **to_return = load_attack();
    if (!to_return)
        return (NULL);
    to_return[0]->name = my_strdup("Hit");
    to_return[0]->type = MELEE;
    to_return[0]->button_funct = button_hit;
    to_return[1]->name = my_strdup("Fire");
    to_return[1]->type = SPELL;
    to_return[1]->button_funct = button_fire;
    to_return[2]->name = my_strdup("Heal");
    to_return[2]->type = HEAL;
    to_return[2]->button_funct = button_heal;
    return (to_return);
}

attack_t **init_egoline_power(void)
{
    attack_t **to_return = load_attack();
    if (!to_return)
        return (NULL);
    to_return[0]->name = my_strdup("Hit");
    to_return[0]->type = MELEE;
    to_return[0]->button_funct = button_hit;
    to_return[1]->name = my_strdup("Fire");
    to_return[1]->type = SPELL;
    to_return[1]->button_funct = button_fire;
    to_return[2]->name = my_strdup("Blizzard");
    to_return[2]->type = SPELL;
    to_return[2]->button_funct = button_blizzard;
    return (to_return);
}