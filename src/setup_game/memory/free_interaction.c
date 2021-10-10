/*
** EPITECH PROJECT, 2019
** free_interaction.c
** File description:
** free player and dialog struct
*/

#include "memory.h"

void free_text(text_t *text)
{
    if (text == NULL)
        return;
    if (text->str != NULL)
        sfText_destroy(text->str);
    if (text->font != NULL)
        sfFont_destroy(text->font);
    free(text);
}

void free_button(button_t *button)
{
    if (button != NULL) {
        free_entity(button->e);
        free(button);
    }
}

void free_player(player_t *player)
{
    if (player == NULL)
        return;
    free_entity(player->player);
    free(player);
}