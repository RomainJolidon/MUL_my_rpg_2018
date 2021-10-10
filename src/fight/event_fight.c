/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "fight.h"

void event_fight(game_t *game)
{
    if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue) {
        return_action(game);
    }
}