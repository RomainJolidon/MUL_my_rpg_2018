/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "rpg.h"

void set_button_attribute(button_t *b, sfVector2f pos, sfIntRect size_s)
{
    b->e->pos_s = size_s;
    b->e->pos.x = pos.x;
    b->e->pos.y = pos.y;
    b->surf.top = pos.y;
    b->surf.left = pos.x;
    b->surf.height = size_s.height;
    b->surf.width = size_s.width;
    sfSprite_setTextureRect(b->e->s, b->e->pos_s);
    sfSprite_setPosition(b->e->s, b->e->pos);
}

button_t *create_button(char *path, void(*action_b), type_t type)
{
    button_t *b = malloc(sizeof(button_t));

    if (!b)
        return (NULL);
    b->e = malloc(sizeof(entity_t));
    if (!b->e)
        return (NULL);
    b->e = sprite_creator(path, 0, 100);
    b->type = type;
    b->state = B_IDLE;
    b->action_b = action_b;
    return (b);
}

button_t *create_volume_button(char *path, void(*action_volume), type_t type)
{
    button_t *b = malloc(sizeof(button_t));

    if (!b)
        return (NULL);
    b->e = malloc(sizeof(entity_t));
    if (!b->e)
        return (NULL);
    b->e = sprite_creator(path, 0, 100);
    b->type = type;
    b->state = B_IDLE;
    b->action_volume = action_volume;
    return (b);
}