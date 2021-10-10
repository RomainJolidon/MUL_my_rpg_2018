/*
** EPITECH PROJECT, 2019
** sort_words.c
** File description:
** display names in order
*/

#include "rpg.h"

int my_strcmp(char const *str1, char const *str2)
{
    for (int i = 0; str1[i] && str2[i]; i++) {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
    }
    return (0);
}

void sort_two_strings(sfTexture **stock, int *names, int n, int j)
{
    sfTexture *temp = NULL;
    int name_temp = 0;

    for (int i = j + 1; i < n; i++) {
        if (names[j] >= names[i]) {
            temp = stock[j];
            name_temp = names[j];
            stock[j] = stock[i];
            names[j] = names[i];
            stock[i] = temp;
            names[i] = name_temp;
        }
    }
}

void sort_texture(sfTexture **stock, int *texture_name, int n)
{
    for (int j = 0; j < n - 1; j++)
        sort_two_strings(stock, texture_name, n, j);
}

void sorter(sfTexture **stock, int *texture_name, int nb)
{
    sort_texture(stock, texture_name, nb);
    free(texture_name);
}