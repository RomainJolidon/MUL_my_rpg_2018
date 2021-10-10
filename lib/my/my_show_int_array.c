/*
** EPITECH PROJECT, 2018
** my_show_word_array
** File description:
** my_show_word_array
*/
#include <stddef.h>
#include "my.h"

int my_show_int_array(int *tab, int size)
{
    int i = 0;

    while (i != size) {
        my_put_nbr(tab[i]);
        my_putchar(' ');
        i++;
    }
    return (0);
}
