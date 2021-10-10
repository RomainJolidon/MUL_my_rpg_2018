/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "fight.h"

void *get_target_function(int i)
{
    switch (i) {
    case 0:
        return (choose_target_one);
    case 1:
        return (choose_target_two);
    default:
        return (choose_target_three);
    }
}

void load_text_target(game_t *game)
{
    sfVector2f pos;
    int count = 0;
    for (; game->enemies[count] != NULL; count++) {
        pos = get_pos_text(count);
        pos.x += 130;
        pos.y += 30;
        game->scene->action[5]->button_text[count] = \
        load_text(game->enemies[count]->name, game, pos);
    }
    pos = POS_OBJECT_B;
    pos.x += 130;
    pos.y += 30;
    game->scene->action[5]->button_text[count] = load_text("Back", game, pos);
}

void load_target_button(game_t *game)
{
    int count = 0;

    for (count = 0; game->enemies[count] != NULL; count++) {
        game->scene->action[5]->button[count] = \
        create_button(PATH_ATTACK_B, get_target_function(count), FIGHT);
        set_button_attribute(game->scene->action[5]->button[count], \
        get_pos_button(count), SIZE_S_ATTACK_B);
    }
    game->scene->action[5]->button[count] = \
    create_button(PATH_RETURN_B, return_action, FIGHT);
    set_button_attribute(game->scene->action[5]->button[count], \
    POS_RETURN_B, SIZE_S_RETURN_B);
    load_text_target(game);
}