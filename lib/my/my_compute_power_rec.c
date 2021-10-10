/*
** EPITECH PROJECT, 2018
** my_compute_power_rec
** File description:
** my_compute_power_rec
*/

void my_putchar(char c);

int my_compute_power_rec(int nb, int p)
{
    int result = nb;
    int i = 0;

    if (p == 0)
        return (1);
    else if (p < 0)
        return (0);
    if (i != p) {
        result = my_compute_power_rec(nb, p - 1) * nb;
        i++;
    }
    return (result);
}
