/*
** EPITECH PROJECT, 2019
** get_villagers.c
** File description:
** get villagers
*/

#include "rpg.h"

cell_t *create_villagers(sfTexture *texture, int x, int y, char type)
{
    cell_t *cell = malloc(sizeof(cell_t));

    if (cell == NULL || !texture)
        return (NULL);
    cell->sprite = sfSprite_create();
    sfSprite_setTexture(cell->sprite, texture, sfTrue);
    cell->pos.x = x;
    cell->pos.y = y;
    sfSprite_setPosition(cell->sprite, cell->pos);
    cell->type = type;
    return (cell);
}

void fill_villager_info(pnj_t *cell)
{
    cell->text = NULL;
    cell->dest.x = cell->info->pos.x;
    cell->dest.y = cell->info->pos.y;
    cell->is_moving = false;
    cell->display = false;
    cell->dir = DOWN;
}

pnj_t *get_texture_villager(char *buffer, pnj_t *cell, sfTexture **texture)
{
    int x = 0;
    int y = 0;
    sfVector2f origin = {16, 16};
    cell = malloc(sizeof(pnj_t));
    if (!cell)
        return (NULL);
    cell->info = get_texture_decor(buffer, cell->info, texture, '4');
    x = cell->info->pos.x;
    y = cell->info->pos.y;
    cell->info->pos.x = x - (x % 32);
    cell->info->pos.y = y - (y % 32);
    cell->pos_s.top = 0;
    cell->pos_s.left = 0;
    cell->pos_s.width = 32;
    cell->pos_s.height = 32;
    sfSprite_setTextureRect(cell->info->sprite, cell->pos_s);
    sfSprite_setOrigin(cell->info->sprite, origin);
    fill_villager_info(cell);
    return (cell);
}

void fill_villagers(pnj_t **villagers, FILE *fd, int nb_line)
{
    char *buffer = NULL;
    size_t size = 0;
    int check = 0;
    sfTexture **texture = get_texture_list("assets/villagers");

    for (int i = 0; i < nb_line; i++) {
        check = getline(&buffer, &size, fd);
        if (check > 1)
            villagers[i] = get_texture_villager(buffer, villagers[i], texture);
        else if (check == 1 && buffer[0] == '\n')
            i--;
    }
    if (buffer != NULL)
        free(buffer);
}

pnj_t **get_villagers(char *filepath)
{
    FILE *fd = fopen(filepath, "r");
    pnj_t **villagers = NULL;
    int nb_line = 0;

    if (fd == NULL)
        return (NULL);
    nb_line = get_nb_line(filepath);
    villagers = malloc(sizeof(cell_t *) * (nb_line + 1));
    if (villagers == NULL)
        return (NULL);
    fill_villagers(villagers, fd, nb_line);
    villagers[nb_line] = NULL;
    fclose(fd);
    return (villagers);
}