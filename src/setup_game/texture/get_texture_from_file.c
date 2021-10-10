/*
** EPITECH PROJECT, 2019
** get_texture_from_file.c
** File description:
** read a dir and get all textures found
*/

#include "rpg.h"

sfTexture *fill_texture_buffer(char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    return (texture);
}

sfTexture **fill_texture_array(char *filepath, int nb_texture, \
sfTexture **texture, DIR *dir)
{
    int nb = 0;
    struct dirent *result = NULL;
    int *texture_name = malloc(sizeof(int) * (nb_texture + 1));

    if (dir != NULL)
        result = readdir(dir);
    while (result != NULL && nb < nb_texture) {
        if (result->d_name[0] != '.') {
            texture[nb] = fill_texture_buffer(complete_file(filepath, \
            result->d_name));
            texture_name[nb] = my_getnbr(result->d_name);
        }
        if (texture[nb] != NULL)
            nb++;
        result = readdir(dir);
    }
    texture[nb_texture] = NULL;
    sorter(texture, texture_name, nb_texture);
    return (texture);
}

sfTexture **search_in_dir(char *filepath, int nb_texture, sfTexture **texture)
{
    DIR *dir = NULL;

    dir = opendir(filepath);
    fill_texture_array(filepath, nb_texture, texture, dir);
    if (dir != NULL)
        closedir(dir);
    return (texture);
}

sfTexture **get_texture_list(char *filepath)
{
    sfTexture **texture = NULL;
    int nb_texture = count_textures(filepath);

    if (nb_texture == 0)
        return (NULL);
    texture = malloc(sizeof(sfTexture *) * (nb_texture + 1));
    if (texture == NULL)
        return (NULL);
    for (int i = 0; i <= nb_texture; i++)
        texture[i] = NULL;
    return (search_in_dir(filepath, nb_texture, texture));
}