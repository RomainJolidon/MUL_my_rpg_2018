/*
** EPITECH PROJECT, 2019
** save_game.c
** File description:
** savd and load data
*/

#include "rpg.h"

void save_story(FILE *fd, int status)
{
    fwrite("STORY", sizeof(char), 5, fd);
    fwrite(":", sizeof(char), 1, fd);
    fwrite(&status, sizeof(int), 1, fd);
}

void save_player_pos(FILE *fd, player_t *player)
{
    sfVector2i pos;

    pos.x = (int) player->player->pos.x;
    pos.y = (int) player->player->pos.y;
    fwrite("POS", sizeof(char), 3, fd);
    fwrite(":", sizeof(char), 1, fd);
    fwrite(&pos.x, sizeof(int), 1, fd);
    fwrite(":", sizeof(char), 1, fd);
    fwrite(&pos.y, sizeof(int), 1, fd);
}

void save_hp(FILE *fd, character_t **characters)
{
    fwrite("HP", sizeof(char), 2, fd);
    for (int i = 0; characters[i] != NULL; i++) {
        fwrite(":", sizeof(char), 1, fd);
        fwrite(&characters[i]->stats->hp, sizeof(int), 1, fd);
    }
}

void write_save(game_t *game)
{
    FILE *fd = fopen("save/save.sav", "wb");

    if (fd == NULL)
        return;
    save_hp(fd, game->characters);
    fwrite("\n", sizeof(char), 1, fd);
    save_player_pos(fd, game->player);
    fwrite("\n", sizeof(char), 1, fd);
    save_story(fd, 0);
    fclose(fd);
}