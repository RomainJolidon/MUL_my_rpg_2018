/*
** EPITECH PROJECT, 2019
** create_dialog.c
** File description:
** create dialog scene
*/

#include "rpg.h"

void next_dialog(game_t *game)
{
    game->dialog->status_read++;
}

dialog_t *create_dialog(void)
{
    dialog_t *dialog = malloc(sizeof(dialog_t));

    if (!dialog)
        return (NULL);
    dialog->status_read = 0;
    dialog->text_bar = sprite_creator("assets/hud/text_bar.png", 0, 659);
    dialog->next = create_button(PATH_NEXT_B, next_dialog, DIALOG);
    set_button_attribute(dialog->next, POS_NEXT_B, SIZE_NEXT_B);
    return (dialog);
}