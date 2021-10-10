/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** my_put_nbr
*/

void my_putchar(char c);
void put_limit_n(void);

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        put_limit_n();
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + '0');
    } else {
        my_putchar(nb + '0');
    }
    return (0);
}

void put_limit_n(void)
{
    int i = 0;
    char *number_limit_n = "-2147483648";

    while (number_limit_n[i] != '\0') {
        my_putchar(number_limit_n[i]);
        i++;
    }
}
