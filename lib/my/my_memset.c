/*
** EPITECH PROJECT, 2019
** my_memset.c
** File description:
** my memset
*/

#include <stdlib.h>

char *my_memset(char *str, int nb)
{
    str = malloc(sizeof(char) * nb + 1);

    if (str == NULL)
        return (NULL);
    for (int i = 0; i < nb; i++)
        str[i] = '\0';
    return (str);
}