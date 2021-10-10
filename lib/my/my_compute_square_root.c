/*
** EPITECH PROJECT, 2018
** my_compute_square_root
** File description:
** my_compute_square_root
*/

void my_putchar(char c);

int my_compute_square_root(int nb)
{
    int i = 0;

    while (i <= 46340) {
        if ((i * i) == nb)
            return (i);
        i++;
    }
    return (0);
}
