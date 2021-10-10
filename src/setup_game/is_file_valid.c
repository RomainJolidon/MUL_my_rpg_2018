/*
** EPITECH PROJECT, 2019
** is_file_valid.c
** File description:
** chekc if vile contain valid chracters
*/

#include <stdio.h>
#include <stdbool.h>

int count_letter(char *line, char letter)
{
    int count = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == letter)
            count++;
    }
    return (count);
}

bool is_letter_valid(char letter, char *valid_letters)
{
    for (int i = 0; valid_letters[i] != '\0'; i++) {
        if (letter == valid_letters[i])
            return (true);
    }
    return (false);
}

bool check_in_line(char *buffer, char *valid_char)
{
    static int count = 0;

    count++;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (is_letter_valid(buffer[i], valid_char) != true) {
            return (false);
        }
    }
    return (true);
}

bool is_file_valid(char *filepath, char *valid_char, int nb_separation)
{
    FILE *fd = fopen(filepath, "r");
    char *buffer = NULL;
    size_t size = 0;
    int end = 0;

    if (fd == NULL)
        return (false);
    while ((end = getline(&buffer, &size, fd)) > 0) {
        buffer[end - 1] = '\0';
        if (check_in_line(buffer, valid_char) != true || \
        count_letter(buffer, ':') != nb_separation) {
            fclose(fd);
            return (false);
        }
    }
    fclose(fd);
    return (true);
}