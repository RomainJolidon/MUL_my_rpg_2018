/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** my_revstr
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    char c;
    int len = my_strlen(str);
    int i = 0;

    if (len > 0) {
        while (i < len / 2) {
            c = str[i];
            str[i] = str[len - 1 - i];
            str[len - i - 1] = c;
            i++;
        }
    }
    return (str);
}
