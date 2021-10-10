/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "fight.h"

void load_action_button(game_t *game)
{
    game->scene->action[0]->button[0] = \
create_button(PATH_ATTACK_B, fight, FIGHT);
    set_button_attribute(game->scene->action[0]->button[0], \
    POS_ATTACK_B, SIZE_S_ATTACK_B);
    game->scene->action[0]->button[1] = \
create_button(PATH_DEFEND_B, defend, FIGHT);
    set_button_attribute(game->scene->action[0]->button[1], \
    POS_DEFEND_B, SIZE_S_DEFEND_B);
    game->scene->action[0]->button[2] = \
create_button(PATH_FLEE_B, flee, FIGHT);
    set_button_attribute(game->scene->action[0]->button[2], \
    POS_FLEE_B, SIZE_S_FLEE_B);
    game->scene->action[0]->button[3] = \
create_button(PATH_OBJECT_B, object, FIGHT);
    set_button_attribute(game->scene->action[0]->button[3], \
    POS_OBJECT_B, SIZE_S_OBJECT_B);
}

char *find_type_attack(game_t *game, int chara, int att)
{
    switch (game->characters[chara]->attack[att]->type) {
    case MELEE:
        return (PATH_ATTACK_B);
    case SPELL:
        return (PATH_FLEE_B);
    default:
        return (PATH_DEFEND_B);
    }
}

sfVector2f get_pos_button(int number)
{
    switch (number) {
    case 0:
        return (POS_ATTACK_B);
    case 1:
        return (POS_DEFEND_B);
    case 2:
        return (POS_FLEE_B);
    default:
        return (POS_OBJECT_B);
    }
}

void load_attack_button(game_t *game)
{
    char *path = NULL;
    sfVector2f pos;
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            path = find_type_attack(game, i - 1, j);
            game->scene->action[i]->button[j] = create_button(path, \
            game->characters[i - 1]->attack[j]->button_funct, FIGHT);
            pos = get_pos_button(j);
            set_button_attribute(game->scene->action[i]->button[j], \
            pos, SIZE_S_OBJECT_B);
        }
        game->scene->action[i]->button[3] = \
        create_button(PATH_RETURN_B, return_action, FIGHT);
        set_button_attribute(game->scene->action[i]->button[3], \
        POS_RETURN_B, SIZE_S_RETURN_B);
    }
}