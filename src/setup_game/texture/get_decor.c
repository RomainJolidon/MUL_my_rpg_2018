/*
** EPITECH PROJECT, 2019
** get_decor.c
** File description:
** get decor
*/

#include "rpg.h"

cell_t *create_decor(sfTexture *texture, int x, int y, char type)
{
    cell_t *cell = malloc(sizeof(cell_t));

    if (cell == NULL)
        return (NULL);
    cell->sprite = sfSprite_create();
    sfSprite_setTexture(cell->sprite, texture, sfTrue);
    cell->pos.x = x;
    cell->pos.y = y;
    sfSprite_setPosition(cell->sprite, cell->pos);
    cell->type = type;
    return (cell);
}

cell_t *get_texture_decor(char *buffer, cell_t *cell, sfTexture **texture, \
char type)
{
    char **tab = str_to_array(buffer, ':');
    int x = my_getnbr(tab[1]);
    int y = my_getnbr(tab[2]);
    int top = my_getnbr(tab[3]) * 32;
    int left = my_getnbr(tab[4]) * 32;
    int width = my_getnbr(tab[5]) * 32;
    int height = my_getnbr(tab[6]) * 32;

    cell = create_decor(texture[my_getnbr(tab[0])], x, y, type);
    cell->rect.top = top;
    cell->rect.left = left;
    cell->rect.width = width;
    cell->rect.height = height;
    return (cell);
}

void fill_decor(cell_t **decor, FILE *fd, int nb_line)
{
    char *buffer = NULL;
    size_t size = 0;
    int check = 0;
    sfTexture **texture = get_texture_list("assets/decor");

    for (int i = 0; i < nb_line; i++) {
        check = getline(&buffer, &size, fd);
        if (check > 1)
            decor[i] = get_texture_decor(buffer, decor[i], texture, '3');
        else if (check == 1 && buffer[0] == '\n')
            i--;
    }
    if (buffer != NULL)
        free(buffer);
}

cell_t **get_decor(char *filepath)
{
    FILE *fd = fopen(filepath, "r");
    cell_t **decor = NULL;
    int nb_line = 0;

    if (fd == NULL)
        return (NULL);
    nb_line = get_nb_line(filepath);
    decor = malloc(sizeof(cell_t *) * (nb_line + 1));
    if (decor == NULL)
        return (NULL);
    fill_decor(decor, fd, nb_line);
    decor[nb_line] = NULL;
    fclose(fd);
    return (decor);
}