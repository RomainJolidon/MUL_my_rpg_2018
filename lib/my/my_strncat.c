/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** my_strncat
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = my_strlen(dest);
    int i = 0;

    dest[len] = src[i];
    while (i < nb && (src[i] != '\0')) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}
