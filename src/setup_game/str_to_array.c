/*
** EPITECH PROJECT, 2019
** str_to_array.c
** File description:
** str to array
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "my.h"

int count_arg(char *str, int nb, char c)
{
    int nb_arg = 0;

    while (str[nb] != '\0') {
        if (str[nb] == c)
            nb_arg++;
        nb++;
    }
    return (nb_arg);
}

char *string_tab(char *str, int *nb, char c)
{
    char *result = NULL;

    if (str == NULL)
        return (NULL);
    result = malloc(sizeof(char) * my_strlen(str) + 1);
    if (result == NULL)
        return (NULL);
    result = memset(result, '\0', my_strlen(str));
    for (int i = 0; str[*nb] != c && str[*nb] != '\0'; i++) {
        result[i + 1] = '\0';
        result[i] = str[*nb];
        (*nb)++;
    }
    return (result);
}

char **str_to_array(char *str, char c)
{
    char **tab = NULL;
    int count = 0;
    int nb_args = 0;

    if (str == NULL)
        return (NULL);
    nb_args = count_arg(str, 0, c);
    tab = malloc(sizeof(char *) * (nb_args + 3));
    if (tab == NULL)
        return (NULL);
    for (int i = 0; count < my_strlen(str); i++) {
        tab[i] = string_tab(str, &count, c);
        while (count < my_strlen(str) && str[count] == c)
            count++;
        tab[i + 1] = NULL;
    }
    return (tab);
}
