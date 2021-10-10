/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "fight.h"

void *get_ally_function(int i)
{
    switch (i) {
    case 0:
        return (choose_ally_one);
    case 1:
        return (choose_ally_two);
    case 2:
        return (choose_ally_three);
    default:
        return (choose_ally_four);
    }
}

void load_heal_text(action_t *action, game_t *game)
{
    sfVector2f pos_attack = {POS_ATTACK_B.x + 130, POS_ATTACK_B.y + 30};
    sfVector2f pos_defend = {POS_DEFEND_B.x + 130, POS_DEFEND_B.y + 30};
    sfVector2f pos_object = {POS_OBJECT_B.x + 130, POS_OBJECT_B.y + 30};
    sfVector2f pos_flee = {POS_FLEE_B.x + 130, POS_FLEE_B.y + 30};
    action->button_text[0] = load_text(game->characters[0]->name, \
game, pos_attack);
    action->button_text[1] = load_text(game->characters[1]->name, \
game, pos_defend);
    action->button_text[2] = load_text(game->characters[2]->name, \
game, pos_flee);
    action->button_text[3] = load_text(game->characters[3]->name, \
game, pos_object);
}

void load_heal_button(game_t *game)
{
    int count = 0;

    for (count = 0; game->characters[count] != NULL; count++) {
        game->scene->action[7]->button[count] = \
        create_button(PATH_DEFEND_B, get_ally_function(count), HEAL);
        set_button_attribute(game->scene->action[7]->button[count], \
        get_pos_button(count), SIZE_S_ATTACK_B);
    }
}