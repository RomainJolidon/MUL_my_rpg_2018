/*
** EPITECH PROJECT, 2019
** setup_text.c
** File description:
** set up sfText to for info display on the screen
*/

#include "rpg.h"

sfText *text_setting(sfFont *font, char *str, sfVector2i pos, int size)
{
    sfVector2f text_pos = {pos.x, pos.y};
    sfText *text = sfText_create();

    sfText_setPosition(text, text_pos);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, size);
    return (text);
}

text_t *text_creator(char *str, char *path, sfVector2i pos, int size)
{
    text_t *text = malloc(sizeof(text_t));

    if (text == NULL)
        return (NULL);
    text->font = sfFont_createFromFile(path);
    text->str = text_setting(text->font, str, pos, size);
    return (text);
}