/*
** EPITECH PROJECT, 2019
** load_save.c
** File description:
** load save for game
*/

#include "rpg.h"

bool check_line_read(FILE *fd, char *model)
{
    char *buffer = malloc(sizeof(char) * my_strlen(model) + 1);

    buffer = memset(buffer, 0, my_strlen(model));
    fread(buffer, sizeof(char), my_strlen(model), fd);
    if (my_strcmp(buffer, model) != 0) {
        my_putstr("Error: wrong line\n");
        fclose(fd);
        return (false);
    }
    return (true);
}

void load_story(FILE *fd, int *status)
{
    int save = 0;
    int end = 1;

    if (check_line_read(fd, "STORY:") != true)
        return;
    while (end > 0 && save != '\n') {
        end = fread(&save, sizeof(int), 1, fd);
        *status = save;
        end = fread(&save, sizeof(char), 1, fd);
    }
}

void load_player_pos(FILE *fd, player_t *player)
{
    int save = 0;
    int end = 1;
    int coord = 0;

    if (check_line_read(fd, "POS:") != true)
        return;
    while (end > 0 && save != '\n') {
        end = fread(&save, sizeof(int), 1, fd);
        if (coord == 0) {
            player->player->pos.x = save;
            player->dest.x = save;
        } else if (coord == 1){
            player->player->pos.y = save;
            player->dest.y = save;
        }
        end = fread(&save, sizeof(char), 1, fd);
        coord++;
    }
    sfSprite_setPosition(player->player->s, player->player->pos);
}

void load_hp(FILE *fd, character_t **characters)
{
    int save = 0;
    int end = 1;

    if (check_line_read(fd, "HP:") != true)
        return;
    for (int i = 0; characters[i] != NULL && end > 0 && save != '\n'; i++) {
        end = fread(&save, sizeof(int), 1, fd);
        characters[i]->stats->hp = save;
        end = fread(&save, sizeof(char), 1, fd);
    }
}

void load_save(game_t *game)
{
    FILE *fd = fopen("save/save.sav", "rb");
    int story = 0;

    if (!fd)
        return;
    load_hp(fd, game->characters);
    load_player_pos(fd, game->player);
    load_story(fd, &story);
    fclose(fd);
    begin_game(game);
}