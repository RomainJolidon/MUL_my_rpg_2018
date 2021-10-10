/*
** EPITECH PROJECT, 2018
** display_window.c
** File description:
** display window of the gamee
*/

#include "rpg.h"

sfText *load_text(const char *buffer, game_t *game, sfVector2f to_set)
{
    sfFloatRect size;
    sfVector2f pos;
    sfText *to_return = sfText_create();
    sfText_setString(to_return, buffer);
    sfText_setFillColor(to_return, sfWhite);
    sfText_setFont(to_return, game->font[0]);
    size = sfText_getGlobalBounds(to_return);
    pos = sfText_getPosition(to_return);
    size.width /= 2;
    size.height /= 2;
    sfVector2f origin = {pos.x + size.width, pos.y + size.height};
    sfText_setOrigin(to_return, origin);
    sfText_setPosition(to_return, to_set);
    return (to_return);
}

void load_action_text(action_t *action, game_t *game)
{
    sfVector2f pos_attack = {POS_ATTACK_B.x + 130, POS_ATTACK_B.y + 30};
    sfVector2f pos_defend = {POS_DEFEND_B.x + 130, POS_DEFEND_B.y + 30};
    sfVector2f pos_object = {POS_OBJECT_B.x + 130, POS_OBJECT_B.y + 30};
    sfVector2f pos_flee = {POS_FLEE_B.x + 130, POS_FLEE_B.y + 30};
    action->button_text[0] = load_text("Attack", game, pos_attack);
    action->button_text[1] = load_text("Defend", game, pos_defend);
    action->button_text[2] = load_text("Objects", game, pos_object);
    action->button_text[3] = load_text("Flee", game, pos_flee);
}

sfVector2f get_pos_text(int i)
{
    switch (i) {
    case 0:
        return (POS_ATTACK_B);
    case 1:
        return (POS_DEFEND_B);
    default:
        return (POS_FLEE_B);
    }
}

void load_attack_text(game_t *game)
{
    sfVector2f pos;
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            pos = get_pos_text(j);
            pos.x += 130;
            pos.y += 30;
            game->scene->action[i]->button_text[j] = \
            load_text(game->characters[i - 1]->attack[j]->name, game, pos);
        }
        pos = POS_OBJECT_B;
        pos.x += 130;
        pos.y += 30;
        game->scene->action[i]->button_text[3] = load_text("Back", game, pos);
    }
}