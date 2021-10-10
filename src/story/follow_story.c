/*
** EPITECH PROJECT, 2019
** follow_story.c
** File description:
** follow actual quest
*/

#include "rpg.h"

void check_get(story_t **story, inventory_t *inv)
{
    int count = count_item_in_inv(inv, story[0]->object);

    if (story[0]->count_id - count >= 0)
        sfText_setString(story[0]->infos[2]->str, \
        int_to_str(story[0]->count_id - count));
    else
        sfText_setString(story[0]->infos[2]->str, "0");
    if (story[0]->count_id - count <= 0)
        story = next_quest(story);
}

void check_battle(story_t **story, state_t state, bool *win_fight)
{
    static state_t old_state = GAME;

    if (*win_fight == true && old_state == GAME) {
        *win_fight = false;
        story[0]->count_id--;
        sfText_setString(story[0]->infos[2]->str, \
        int_to_str(story[0]->count_id));
    }
    if (story[0]->count_id <= 0)
        story = next_quest(story);
    old_state = state;
}

void check_talk(story_t **story, pnj_t **villagers)
{
    if (villagers[story[0]->count_id]->display == true)
        story = next_quest(story);
}

void update_quest(game_t *game)
{
    if (game->story[0] == NULL)
        return;
    if (game->story[0]->goal == TALK)
        check_talk(game->story, game->villagers);
    if (game->story[0]->goal == BATTLE)
        check_battle(game->story, game->state, &game->win_fight);
    if (game->story[0]->goal == GET)
        check_get(game->story, game->inv);
}