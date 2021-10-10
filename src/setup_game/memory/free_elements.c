/*
** EPITECH PROJECT, 2019
** free_elements.c
** File description:
** free elements
*/

#include "memory.h"

void free_font_tab(sfFont **font)
{
    if (font == NULL)
        return;
    for (int i = 0; font[i] != NULL; i++)
        sfFont_destroy(font[i]);
    free(font);
}

void free_watch(watch_t *watch)
{
    if (watch == NULL)
        return;
    sfClock_destroy(watch->clock);
    free(watch);
}

void free_parallax(parallax_t **parallax)
{
    if (parallax == NULL)
        return;
    for (int i = 0; parallax[i] != NULL; i++) {
        sfTexture_destroy(parallax[i]->texture);
        sfSprite_destroy(parallax[i]->sprite_1);
        free(parallax[i]);
    }
    free(parallax);
}