/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr_base(int nb, char *base);

void my_print_printable(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 32 && str[i] < 127)
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            my_put_nbr_base(str[i], "01234567");
        }
        i++;
    }
    return;
}
