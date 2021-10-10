/*
** EPITECH PROJECT, 2019
** player.c
** File description:
** all related to players
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include "rpg.h"

character_t *init_ally_three(character_t *perso);
character_t *init_ally_two(character_t *perso);
character_t *init_ally_one(character_t *perso);
character_t *init_hero(character_t *perso);
character_t **init_character_tab(void);
void fill_character_stats(character_t *perso, int *stats);
character_t **init_character_tab(void);
void healthbar_and_icon_creator(character_t *perso, int type);
character_t **init_enemies_tab(void);
attack_t **init_hero_power(void);
void load_heal_text(action_t *action, game_t *game);
void load_random_enemy(character_t **enemy, sfVector2i pos);
attack_t **init_egoline_power(void);

#endif /* !PLAYER_H_ */
