/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "player.h"

character_t *init_bird(character_t *enemy, int x, int y)
{
    sfVector2f scale = {2.5, 2.5};
    int stats[9] = {100, 10, 15, 10, 15, 10, 20, 25, 0};
    enemy = malloc(sizeof(*enemy));
    enemy->stats = malloc(sizeof(*enemy->stats));
    enemy->name = my_strdup("Bird");
    fill_character_stats(enemy, stats);
    enemy->e = sprite_creator("assets/sprites/Bird.png", x, y);
    enemy->enemy = true;
    sfSprite_scale(enemy->e->s, scale);
    return (enemy);
}

character_t *init_slug(character_t *enemy, int x, int y)
{
    sfVector2f scale = {2, 2};
    int stats[9] = {50, 10, 15, 10, 15, 10, 20, 10, 0};
    enemy = malloc(sizeof(*enemy));
    enemy->stats = malloc(sizeof(*enemy->stats));
    enemy->name = my_strdup("Slug");
    enemy->enemy = true;
    fill_character_stats(enemy, stats);
    enemy->e = sprite_creator("assets/sprites/Slug.png", x, y);
    sfSprite_scale(enemy->e->s, scale);
    return (enemy);
}

character_t *init_reptile(character_t *enemy, int x, int y)
{
    sfVector2f scale = {2.5, 2.5};
    int stats[9] = {50, 10, 15, 10, 15, 10, 20, 1, 0};
    enemy = malloc(sizeof(*enemy));
    enemy->stats = malloc(sizeof(*enemy->stats));
    enemy->name = my_strdup("Reptile");
    enemy->enemy = true;
    fill_character_stats(enemy, stats);
    enemy->e = sprite_creator("assets/sprites/Reptile.png", x, y);
    sfSprite_scale(enemy->e->s, scale);
    return (enemy);
}

character_t **init_enemies_tab(void)
{
    character_t **enemies = malloc(sizeof(character_t *) * 4);
    sfVector2i pos[3] = {{150, 150}, {300, 275}, {150, 375}};
    if (enemies == NULL)
        return (NULL);
    for (int i = 0; i < 3; i++)
        load_random_enemy(&enemies[i], pos[i]);
    enemies[3] = NULL;
    return (enemies);
}