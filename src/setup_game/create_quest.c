/*
** EPITECH PROJECT, 2019
** create_quest.c
** File description:
** create a quest to a selected villager
*/

#include "rpg.h"

void create_quest(pnj_t *pnj, char *message)
{
    int nb = 0;
    sfFloatRect size;
    sfVector2f pos = {300, 700};

    if (pnj->info->type != '5')
        return;
    while (pnj->text[nb] != NULL)
        nb++;
    pnj->text[nb] = text_creator(message, \
    "assets/font/quest.ttf", fill_vector_2i(770, 1420), 35);
    size = sfText_getGlobalBounds(pnj->text[nb]->str);
    size.width /= 2;
    size.height /= 2;
    sfVector2f origin = {pos.x + size.width, pos.y + size.height};
    sfText_setOrigin(pnj->text[nb]->str, origin);
}

void setup_quest(pnj_t *pnj, int nb_dialog)
{
    pnj->info->type = '5';
    if (pnj->text != NULL){
        for (int i = 0; pnj->text[i] != NULL; i++)
            free(pnj->text[i]);
        free(pnj->text);
    }
    pnj->text = malloc(sizeof(text_t *) * (nb_dialog + 1));
    if (!pnj->text)
        return;
    for (int i = 0; i <= nb_dialog; i++)
        pnj->text[i] = NULL;
    pnj->goal = NULL;
}