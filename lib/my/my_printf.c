/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/
#include <stdarg.h>

void my_putchar(char c);
int my_putstr(char const *str);
int check_flag(char flag, va_list ap);
int my_put_unbr(unsigned int nb);
int my_put_nbr(int nb);
void my_print_printable(char *str);
int my_put_nbr_base(int nb, char *base);
int my_put_unbr_base(int nb, char *base);
int check_flag_2(char flag, va_list ap);

int my_printf(char *str, ...)
{
    va_list ap;
    int i = 0;

    va_start(ap, str);
    while (str[i] != '\0') {
        if (str[i] == '%' && ((str[i + 1] > 'a' && str[i + 1])
        || (str[i + 1] > 'A' && str[i + 1] < 'Z')
        || str[i + 1] == '%')) {
            check_flag(str[i + 1], ap);
            i += 2;
        }
        if (str[i] != '%' && str[i] != '\0') {
            my_putchar(str[i]);
            i++;
        }
    }
    va_end(ap);
    return (0);
}

int check_flag(char flag, va_list ap)
{
    if (flag == 'c')
        my_putchar(va_arg(ap, int));
    if (flag == 's')
        my_putstr(va_arg(ap, char *));
    if (flag == 'd' || flag == 'i')
        my_put_nbr(va_arg(ap, int));
    if (flag == 'u')
        my_put_unbr(va_arg(ap, unsigned int));
    if (flag == 'S')
        my_print_printable(va_arg(ap, char *));
    if (flag == 'x')
        my_put_unbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
    if (flag == 'X')
        my_put_unbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
    if (flag == 'o')
        my_put_unbr_base(va_arg(ap, unsigned int), "01234567");
    check_flag_2(flag, ap);
    return (0);
}

int check_flag_2(char flag, va_list ap)
{
    if (flag == 'b')
        my_put_unbr_base(va_arg(ap, unsigned int), "01");
    if (flag == 'p')
        my_put_nbr_base(va_arg(ap, int), "0123456789ABCDEF");
    if (flag == '%')
        my_putchar('%');
    return (0);
}
