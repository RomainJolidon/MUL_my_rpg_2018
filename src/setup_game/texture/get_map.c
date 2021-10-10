/*
** EPITECH PROJECT, 2019
** get_map.c
** File description:
** get sprite map from file
*/

#include "rpg.h"

cell_t *create_ground_cell(sfTexture *texture, int x, int y, char type)
{
    sfIntRect rect = {0, 0, 32, 32};
    sfVector2f origin = {16, 16};
    cell_t *cell = malloc(sizeof(cell_t));

    if (cell == NULL)
        return (NULL);
    cell->sprite = sfSprite_create();
    sfSprite_setTexture(cell->sprite, texture, sfTrue);
    sfSprite_setTextureRect(cell->sprite, rect);
    sfSprite_setOrigin(cell->sprite, origin);
    cell->pos.x = x;
    cell->pos.y = y;
    sfSprite_setPosition(cell->sprite, cell->pos);
    cell->type = type;
    return (cell);
}

int get_nb_line(char *filepath)
{
    FILE *fd = fopen(filepath, "r");
    size_t size = 0;
    int count = 0;
    char *buffer = NULL;

    while (getline(&buffer, &size, fd) > 0) {
        count++;
    }
    fclose(fd);
    return (count);
}

void get_texture(char *line, cell_t **board, sfTexture *texture[2], int size)
{
    static sfVector2i pos = {0, 0};

    for (int i = 0; i < size; i++) {
        if (line[i] != '\n' && line[i] != '\0')
            board[i] = create_ground_cell(texture[line[i] - 48], \
            pos.x, pos.y, line[i]);
        pos.x += 32;
    }
    board[size] = NULL;
    pos.x = 0;
    pos.y += 32;
}

void fill_map(cell_t ***map, FILE *fd, int nb_line)
{
    char *buffer = NULL;
    size_t size = 0;
    sfTexture *texture[3];

    texture[0] = sfTexture_createFromFile("assets/connected_tiles/\
water.png", NULL);
    texture[1] = sfTexture_createFromFile("assets/connected_tiles/\
grass.png", NULL);
    texture[2] = sfTexture_createFromFile("assets/connected_tiles/\
path.png", NULL);

    for (int i = 0; i < nb_line; i++) {
        getline(&buffer, &size, fd);
        map[i] = malloc(sizeof(cell_t *) * (my_strlen(buffer) + 1));
        if (map[i] == NULL)
            return;
        get_texture(buffer, map[i], texture, my_strlen(buffer) - 1);
    }
    if (buffer != NULL)
        free(buffer);
}

cell_t ***get_map(char *filepath)
{
    FILE *fd = fopen(filepath, "r");
    cell_t ***map = NULL;
    int nb_line = 0;

    if (fd == NULL)
        return (NULL);
    nb_line = get_nb_line(filepath);
    map = malloc(sizeof(cell_t **) * (nb_line + 1));
    if (map == NULL)
        return (NULL);
    fill_map(map, fd, nb_line);
    map[nb_line] = NULL;
    connect_texture(map);
    fclose(fd);
    return (map);
}