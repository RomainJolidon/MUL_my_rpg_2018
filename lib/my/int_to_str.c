/*
** EPITECH PROJECT, 2018
** int_to_str.c
** File description:
** get a int to a str
*/

#include <stdlib.h>
#include "my.h"

int intlen(int nb)
{
    int size = 0;

    for (int i = 0; nb > 0; i++) {
        nb /= 10;
        size++;
    }
    return (size);
}

char *int_to_str_neg(int nb)
{
    char *str = NULL;
    int size = 0;

    nb = -nb;
    size = intlen(nb);
    str = malloc(sizeof(char) * size + 2);
    if (str == NULL)
        return ("0");
    str[size + 1] = '\0';
    str[size] = '-';
    for (int i = 0; size > 0; i++) {
        str[i] = (nb % 10) + '0';
        nb /= 10;
        size--;
    }
    return (str);
}

char *int_to_str(int nb)
{
    int size = intlen(nb);
    char *str = NULL;

    if (nb < 0)
        str = int_to_str_neg(nb);
    else {
        str = malloc(sizeof(char) * size + 1);
        if (str == NULL || nb == 0)
            return ("0");
        str[size] = '\0';
        for (int i = 0; size > 0; i++) {
            str[i] = (nb % 10) + '0';
            nb /= 10;
            size--;
        }
    }
    str = my_revstr(str);
    return (str);
}