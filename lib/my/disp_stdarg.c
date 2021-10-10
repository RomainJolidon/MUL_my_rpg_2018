/*
** EPITECH PROJECT, 2018
** bootstrap my_printf
** File description:
** bootstrap my_printf
*/
#include <stdarg.h>

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);

int disp_stdarg(char *s, ...)
{
    va_list ap;

    va_start(ap, s);
    while (*s) {
        if (*s == 'c')
            my_putchar(va_arg(ap, int));
        if (*s == 's')
            my_putstr(va_arg(ap, char *));
        if (*s == 'i')
            my_put_nbr(va_arg(ap, int));
        my_putchar('\n');
        s++;
    }
    return (0);
}
