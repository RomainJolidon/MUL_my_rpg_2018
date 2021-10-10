/*
** EPITECH PROJECT, 2019
** define.h
** File description:
** all definer for my_world project
*/

#ifndef FIGHT_H_
#define FIGHT_H_

#include "rpg.h"

void display_fight(game_t *game);
void display_entity(entity_t *entity, game_t *game);
int prepare_fight(game_t *game);
void fight(game_t *game);
void object(game_t *game);
void defend(game_t *game);
void flee(game_t *game);
void destroy_fight(scene_t *scene);
attack_t **load_attack(void);
void load_attack_button(game_t *game);
void destroy_player(game_t *game);
void find_next_player(game_t *game);
void return_action(game_t *game);
void load_action_text(action_t *action, game_t *game);
void choose_target_one(game_t *game);
void choose_target_two(game_t *game);
void choose_target_three(game_t *game);
void load_attack_text(game_t *game);
sfVector2f get_pos_button(int number);
void load_target_button(game_t *game);
void button_hit(game_t *game);
void do_hit(game_t *game);
void enemy_attack(game_t *game);
int check_death(game_t *game);
void damage_text(game_t *game, fight_t *info_fight, sfText *damage);
void deal_dommage(game_t *game, int attack);
void end_of_attack(game_t *game);
int prepare_fight(game_t *game);
void display_fight(game_t *game);
void end_combat(game_t *game);
bool is_all_enemies_dead(game_t *game);
void button_heal(game_t *game);
void do_heal(game_t *game);
void event_fight(game_t *game);
void choose_ally_four(game_t *game);
void choose_ally_three(game_t *game);
void choose_ally_two(game_t *game);
void choose_ally_one(game_t *game);
void load_heal_text(action_t *action, game_t *game);
character_t *init_bird(character_t *enemy, int x, int y);
character_t *init_slug(character_t *enemy, int x, int y);
character_t *init_reptile(character_t *enemy, int x, int y);
character_t **init_enemies_tab(void);
attack_t **load_attack(void);
void player_attack(int *state, int *event, game_t *game, int sound);
void enemy_hit(int *state, int *event, game_t *game, int sound);
void button_fire(game_t *game);
void do_fire(game_t *game);
void fire_animation(game_t *game, int *event);
void do_blizzard(game_t *game);
void blizzard_animation(game_t *game, int *event);
void button_blizzard(game_t *game);

#endif