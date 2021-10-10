/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_putstr
*/
#include <unistd.h>

int my_putstr(char const *str)
{
    int len = 0;
    int i = 0;

    while (str[i] != '\0') {
        len++;
        i++;
    }
    write(1, str, len);
    return (0);
}
