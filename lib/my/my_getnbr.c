/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** my_getnbr
*/

void my_putchar(char c);

int invert_sign(int count_n, int result);

int my_getnbr(char const *str)
{
    int result = 0;
    int i = 0;
    int count_n = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            count_n++;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    result = invert_sign(count_n, result);
    return (result);
}

int invert_sign(int count_n, int result)
{
    if ((count_n % 2) == 1) {
        result = result * -1;
    }
    return (result);
}
