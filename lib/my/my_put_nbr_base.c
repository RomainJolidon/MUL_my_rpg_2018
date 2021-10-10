/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);

int my_put_nbr_base(int nb, char *base)
{
    int result;
    int rest;

    result = nb / my_strlen(base);
    rest = nb % my_strlen(base);
    if (result > 0)
        my_put_nbr_base(result, base);
    my_putchar(base[rest]);
    return (0);
}

int my_put_unbr_base(unsigned int nb, char *base)
{
    unsigned int result;
    unsigned int rest;

    result = nb / my_strlen(base);
    rest = nb % my_strlen(base);
    if (result > 0)
        my_put_nbr_base(result, base);
    my_putchar(base[rest]);
    return (0);
}
