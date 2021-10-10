/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** my_swap
*/
void my_putchar(char c);

void my_swap(int *a, int *b)
{
    int buffer_value_a = *a;

    *a = *b;
    *b = buffer_value_a;
}
