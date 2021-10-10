/*
** EPITECH PROJECT, 2019
** get_file_data.c
** File description:
** get file data
*/

#include "rpg.h"

char *complete_file(char *filepath, char *name)
{
    int count = 0;
    int size_filepath = my_strlen(filepath);
    int size_name = my_strlen(name);
    char *str = NULL;

    str = my_memset(str, size_filepath + size_name + 2);
    if (size_name == 0)
        return (filepath);
    for (int i = 0; i < size_filepath; i++)
        str[i] = filepath[i];
    str[size_filepath] = '/';
    for (int i = size_filepath + 1; i < size_filepath + size_name + 1; i++) {
        str[i] = name[count];
        count++;
    }
    return (str);
}

int count_textures(char *filepath)
{
    int nb_pieces = 0;
    DIR *dir = NULL;
    struct dirent *result = NULL;

    dir = opendir(filepath);
    if (dir != NULL)
        result = readdir(dir);
    while (result != NULL) {
        if (result->d_name[0] != '.')
            nb_pieces++;
        result = readdir(dir);
    }
    if (dir != NULL)
        closedir(dir);
    return (nb_pieces);
}