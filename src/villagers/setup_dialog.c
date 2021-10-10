/*
** EPITECH PROJECT, 2019
** setup_story.c
** File description:
** generate dialog for villagers
*/

#include "fight.h"

void attribute_goal_give(game_t *game, obj_value_t object)
{
    sfVector2i pos = find_place_in_inv(game->inv);

    if (pos.y == -1 || pos.x == -1)
        return;
    add_new_object(object, pos, game->inv);
}

void attribute_goal_fight(game_t *game, obj_value_t object)
{
    sfView const *view = sfRenderWindow_getDefaultView(game->window);

    (void) object;
    sfRenderWindow_setView(game->window, view);
    if (prepare_fight(game) == ERROR)
        return;
    game->transition = create_transition(game->transition);
    game->state = FIGHT;
    attribute_goal_give(game, object);
}

void add_goal(pnj_t *pnj, obj_value_t object, char type)
{
    if (type == 'g')
        pnj->goal = attribute_goal_give;
    else if (type == 'f')
        pnj->goal = attribute_goal_fight;
    pnj->object.name = object.name;
    pnj->object.detail = object.detail;
    pnj->object.rect = object.rect;
}