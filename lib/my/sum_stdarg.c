/*
** EPITECH PROJECT, 2018
** bootstrap my_printf
** File description:
** bootstrap my_printf
*/
#include <stdarg.h>

int my_strlen(char const *str);

int sum_stdarg(int i, int nb, ...)
{
    va_list ap;
    int count = 0;
    int result = 0;

    va_start(ap, nb);
    while (count != nb) {
        if (i == 0)
            result += va_arg(ap, int);
        else if (i == 1)
            result += my_strlen(va_arg(ap, char *));
        else
            return (84);
        count++;
    }
    va_end(ap);
    return (result);
}
