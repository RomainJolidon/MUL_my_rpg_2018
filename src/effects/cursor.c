/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** cursor
*/

#include "rpg.h"
#include "define.h"

cursor_t *create_cursor(sfVector2f pos, int choice)
{
    cursor_t *cur = malloc(sizeof(*cur) * 2);
    sfVector2f origin = {.x = MIDDLE_SPRITE, .y = MIDDLE_SPRITE};
    char path[3][30] = {PATH_FIRE_C, PATH_ELECTRIC_C, PATH_WATER_C};

    if (!cur)
        return (NULL);
    cur->texture = sfTexture_createFromFile(path[choice], NULL);
    cur->sprite = sfSprite_create();
    cur->clock = sfClock_create();
    cur->end = 0;
    cur->next = NULL;
    sfSprite_setOrigin(cur->sprite, origin);
    sfSprite_setTexture(cur->sprite, cur->texture, sfFalse);
    sfSprite_setTextureRect(cur->sprite, CURSOR_RECT);
    sfSprite_setPosition(cur->sprite, pos);
    sfSprite_setRotation(cur->sprite, rand() % 360);
    return (cur);
}

cursor_f *init_cursor(void)
{
    cursor_f *ret = malloc(sizeof(*ret));

    if (!ret)
        return (NULL);
    ret->first = NULL;
    return (ret);
}

void cursor(game_t *game, int x, int y, int choice)
{
    cursor_t *cursor = create_cursor(fill_vector_2f(x, y), choice);
    cursor_t *browse;

    if (!game->c->first) {
        game->c->first = cursor;
    } else {
        browse = game->c->first;
        while (browse->next) {
            browse = browse->next;
        }
        browse->next = cursor;
    }
}

void free_cursor(game_t *game)
{
    cursor_t *browse;
    cursor_t *tmp;

    browse = game->c->first;
    while (browse) {
        tmp = browse;
        browse = browse->next;
        sfClock_destroy(tmp->clock);
        sfSprite_destroy(tmp->sprite);
        sfTexture_destroy(tmp->texture);
        free(tmp);
    }
    game->c->first = NULL;
}