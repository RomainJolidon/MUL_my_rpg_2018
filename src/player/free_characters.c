/*
** EPITECH PROJECT, 2019
** free_characters.c
** File description:
** free characters
*/

#include "rpg.h"

void free_attack(attack_t **attack)
{
    if (!attack)
        return;
    for (int i = 0; attack[i] != NULL; i++) {
        free(attack[i]->name);
        free(attack[i]);
    }
    free(attack);
}

void free_character_tab(character_t **character)
{
    if (!character)
        return;
    for (int i = 0; character[i] != NULL; i++) {
        sfSprite_destroy(character[i]->e->s);
        sfTexture_destroy(character[i]->e->t);
        free(character[i]->e);
        free(character[i]->name);
        free(character[i]->stats);
        free_attack(character[i]->attack);
        character[i]->played = 0;
        free(character[i]);
    }
    free(character);
}