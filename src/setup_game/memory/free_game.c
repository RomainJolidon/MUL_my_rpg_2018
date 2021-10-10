/*
** EPITECH PROJECT, 2019
** free_game.c
** File description:
** free game struct
*/

#include "memory.h"

void free_entity(entity_t *entity)
{
    if (entity != NULL) {
        if (entity->s != NULL)
            sfSprite_destroy(entity->s);
        if (entity->t != NULL)
            sfTexture_destroy(entity->t);
        free(entity);
    }
}

void free_dialogues(text_t **dialogues)
{
    if (dialogues != NULL) {
        for (int i = 0; dialogues[i] != NULL; i++) {
            sfText_destroy(dialogues[i]->str);
            sfFont_destroy(dialogues[i]->font);
            free(dialogues[i]);
        }
        free(dialogues);
    }
}

void free_buttons(button_t **buttons)
{
    if (buttons != NULL) {
        for (int i = 0; buttons[i] != NULL; i++)
            free_button(buttons[i]);
        free(buttons);
    }
}

void free_characters(entity_t **characters)
{
    if (characters != NULL) {
        for (int i = 0; characters[i] != NULL; i++) {
            free_entity(characters[i]);
        }
        free(characters);
    }
}

void free_game(game_t *game)
{
    free_dialog_struct(game->dialog);
    free_map(game->map);
    free_decor(game->decor);
    free_villagers(game->villagers);
    free_options(game->opt);
    free_controls(game->ctrl);
    free_pause(game->pse);
    free_story(game->story);
    free_player(game->player);
    free_font_tab(game->font);
    free_transition(game->transition);
    sfView_destroy(game->view);
    sfRenderWindow_destroy(game->window);
    free(game);
}