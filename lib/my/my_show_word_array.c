/*
** EPITECH PROJECT, 2018
** my_show_word_array
** File description:
** my_show_word_array
*/
#include <stddef.h>
#include "my.h"

int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}
