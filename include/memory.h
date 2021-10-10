/*
** EPITECH PROJECT, 2019
** memory.h
** File description:
** functions related to memory
*/

#ifndef MEMORY_H_
#define MEMORY_H_

#include "rpg.h"

void free_player(player_t *player);
void free_dialog_struct(dialog_t *dialog);
void free_button(button_t *button);
void free_buttons(button_t **buttons);
void free_text(text_t *text);
void free_dialogues(text_t **dialogues);
void free_entity(entity_t *entity);
void free_character_tab(character_t **character);
void free_font_tab(sfFont **font);
void free_watch(watch_t *watch);
void free_parallax(parallax_t **parallax);
void free_map(cell_t ***map);
void free_decor(cell_t **decor);
void free_villagers(pnj_t **villagers);
void free_story(story_t **story);
void free_cell(cell_t *cell);
void free_dialog_struct(dialog_t *dialog);
void free_options(option_t *options);
void free_pause(pause_t *pause);
void free_controls(control_t **controls);
void free_transition(transition_t *transition);
void free_game(game_t *game);

#endif /* !memory */
