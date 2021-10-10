/*
** EPITECH PROJECT, 2019
** load_fight_elements.c
** File description:
** load fight elements
*/

#include "player.h"

void load_info_fight(game_t *game)
{
    game->scene->info_fight = malloc(sizeof(*game->scene->info_fight));
    game->scene->info_fight->to_play = NULL;
    game->scene->info_fight->target = NULL;
    game->scene->info_fight->animation = NULL;
    game->scene->info_fight->to_do = NULL;
    game->scene->info_fight->clock = time_creator();
    game->scene->info_fight->damage = sfText_create();
}

void load_scene(game_t *game)
{
    int size = 8;
    int nb_button = 6;

    game->scene->action = malloc(sizeof(*game->scene->action) * (size + 1));
    game->scene->action[size] = NULL;
    for (int i = 0; i < size; i++) {
        game->scene->action[i] = malloc(sizeof(**game->scene->action));
        game->scene->action[i]->button = \
        malloc(sizeof(*game->scene->action[i]->button) * (nb_button + 1));
        game->scene->action[i]->button[nb_button] = NULL;
        game->scene->action[i]->button_text = \
        malloc(sizeof(*game->scene->action[i]->button_text) * (nb_button + 1));
        game->scene->action[i]->button_text[nb_button] = NULL;
        my_memeset(game->scene->action[i]->button, \
        game->scene->action[i]->button_text, nb_button);
    }
}

void load_action(game_t *game)
{
    load_scene(game);
    load_action_button(game);
    load_attack_button(game);
    load_action_text(game->scene->action[0], game);
    load_attack_text(game);
    load_target_button(game);
    load_info_fight(game);
    load_heal_button(game);
    load_heal_text(game->scene->action[7], game);
}

int load_fight_element(game_t *game)
{
    game->scene = malloc(sizeof(*game->scene));
    if (!game->scene)
        return (ERROR);
    sfVector2f pos_hud = POS_HUD_FIGHT;
    sfVector2f pos_back = POS_BACK;
    game->scene->front = sprite_creator(HUD_FIGHT, pos_hud.x, pos_hud.y);
    if (!game->scene->front)
        return (ERROR);
    game->scene->bckgrnd = sprite_creator(BACK_FIGHT, pos_back.x, pos_back.y);
    if (!game->scene->bckgrnd)
        return (ERROR);
    load_action(game);
    game->scene->state = 0;
    return (SUCCESS);
}