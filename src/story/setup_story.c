/*
** EPITECH PROJECT, 2019
** setup_story.c
** File description:
** setup quest for story
*/

#include "rpg.h"

void setup_story_next(story_t **story)
{
    story[4] = setup_quest_talk("The bad guy", \
    "Talk the village girl on the central square", 1);
    story[5] = setup_quest_talk("Find the villain", \
    "Find the one-eyed villain hidden in the village", 2);
    story[6] = setup_quest_fight("Stop the bad guy", \
    "stop the villain's actions by fighting him", 1);
    story[7] = setup_quest_talk("Gift from the ancient", \
    "Talk to the ancient near the forest", 3);
    story[8] = setup_quest_get("The gift", "Get the gift from the ancient", \
    GIFT, 1);
}

story_t **setup_story(void)
{
    story_t **story = malloc(sizeof(story_t *) * 10);

    if (!story)
        return (NULL);
    story[0] = setup_quest_talk("The mysterious story", \
    "Talk to the the chief of the village in the central square", 0);
    story[1] = setup_quest_fight("Protect the village", \
    "Protect the village from the monsters hidden in the forest", 5);
    story[2] = setup_quest_talk("Golden fish !", \
    "Talk to the guardian of the lake", 5);
    story[3] = setup_quest_fight("Fight the fish eaters", \
    "Help the guardian of the lac by killing the fish eaters", 1);
    setup_story_next(story);
    story[9] = NULL;
    return (story);
}