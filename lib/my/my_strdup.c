/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** my_strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    char *str = NULL;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != '\0') {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
