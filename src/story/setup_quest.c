/*
** EPITECH PROJECT, 2019
** setup_quest.c
** File description:
** setup quest
*/

#include "rpg.h"

story_t **next_quest(story_t **story)
{
    int i = 0;

    for (int j = 0; story[0]->infos[j] != NULL; j++)
        free(story[0]->infos[j]);
    free(story[0]->infos);
    free(story[0]);
    for (i = 0; story[i + 1] != NULL; i++)
        story[i] = story[i + 1];
    story[i] = NULL;
    return (story);
}

story_t *setup_quest_get(char *name, char *desc, \
obj_value_t object, int nb_item)
{
    story_t *quest = malloc(sizeof(story_t));

    if (!quest)
        return (NULL);
    quest->infos = malloc(sizeof(text_t *) * 5);
    if (!quest->infos)
        return (NULL);
    quest->count_id = nb_item;
    quest->goal = GET;
    quest->infos[0] = text_creator(name, "assets/font/pixel.ttf", \
    fill_vector_2i(5, 10), 25);
    quest->infos[1] = text_creator(desc, "assets/font/pixel.ttf", \
    fill_vector_2i(5, 40), 25);
    quest->infos[2] = text_creator(int_to_str(nb_item), \
    "assets/font/pixel.ttf", fill_vector_2i(5, 70), 20);
    quest->infos[3] = text_creator("rewards to get", \
    "assets/font/pixel.ttf", fill_vector_2i(30, 70), 20);
    quest->infos[4] = NULL;
    quest->object = object;
    return (quest);
}

story_t *setup_quest_fight(char *name, char *desc, int nb_enemies)
{
    story_t *quest = malloc(sizeof(story_t));

    if (!quest)
        return (NULL);
    quest->infos = malloc(sizeof(text_t *) * 5);
    if (!quest->infos)
        return (NULL);
    quest->count_id = nb_enemies;
    quest->goal = BATTLE;
    quest->infos[0] = text_creator(name, "assets/font/pixel.ttf", \
    fill_vector_2i(5, 10), 25);
    quest->infos[1] = text_creator(desc, "assets/font/pixel.ttf", \
    fill_vector_2i(5, 40), 25);
    quest->infos[2] = text_creator(int_to_str(nb_enemies), \
    "assets/font/pixel.ttf", fill_vector_2i(5, 70), 20);
    quest->infos[3] = text_creator("enemies remenaning", \
    "assets/font/pixel.ttf", fill_vector_2i(30, 70), 20);
    quest->infos[4] = NULL;
    return (quest);
}

story_t *setup_quest_talk(char *name, char *desc, int id_villager)
{
    story_t *quest = malloc(sizeof(story_t));

    if (!quest)
        return (NULL);
    quest->infos = malloc(sizeof(text_t *) * 3);
    if (!quest->infos)
        return (NULL);
    quest->count_id = id_villager;
    quest->goal = TALK;
    quest->infos[0] = text_creator(name, "assets/font/pixel.ttf", \
    fill_vector_2i(5, 10), 25);
    quest->infos[1] = text_creator(desc, "assets/font/pixel.ttf", \
    fill_vector_2i(5, 40), 25);
    quest->infos[2] = NULL;
    return (quest);
}