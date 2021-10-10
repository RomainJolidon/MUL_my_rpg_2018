/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "rpg.h"

void my_memeset(button_t **button, sfText **text, int size)
{
    for (int i = 0; i < size; i++) {
        button[i] = NULL;
        text[i] = NULL;
    }
}