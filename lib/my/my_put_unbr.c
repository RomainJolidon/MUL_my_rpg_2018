/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** my_put_nbr
*/

void my_putchar(char c);
void put_limit_n(void);

int my_put_unbr(unsigned int nb)
{
    if (nb >= 10) {
        my_put_unbr(nb / 10);
        my_putchar((nb % 10) + '0');
    } else {
        my_putchar(nb + '0');
    }
    return (0);
}
