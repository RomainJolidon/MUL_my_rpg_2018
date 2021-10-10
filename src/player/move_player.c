/*
** EPITECH PROJECT, 2019
** move_player.c
** File description:
** move plyer in map
*/

#include "rpg.h"

bool collide_decor(game_t *game, sfVector2f dest)
{
    for (int i = 0; game->decor[i] != NULL; i++) {
        if (sfIntRect_contains(&game->decor[i]->rect, \
            dest.x, dest.y) == sfTrue)
            return (true);
    }
    for (int i = 0; game->villagers[i] != NULL; i++) {
        if (sfIntRect_contains(&game->villagers[i]->info->rect, \
            dest.x, dest.y) == sfTrue)
            return (true);
    }
    return (false);
}

int find_cell(cell_t **line, sfVector2f dest)
{
    sfVector2f pos;

    for (int x = 0; line[x] != NULL; x++) {
        pos = sfSprite_getPosition(line[x]->sprite);
        if (dest.x == pos.x && dest.y == pos.y)
            return (x);
    }
    return (-1);
}

int collision(game_t *game, int value)
{
    int y = 0;
    int x = -1;

    while (game->map[y] != NULL) {
        x = find_cell(game->map[y], game->player->dest);
        if (x > -1)
            break;
        y++;
    }
    if (x == -1 || game->map[y] == NULL)
        return (value);
    if (game->map[y][x]->type != '0' && \
    collide_decor(game, game->player->dest) == false) {
        start_battle(game);
        return (0);
    } else
        return (value);
}

void move_player(game_t *game)
{
    int size[2] = {-32, 32};

    for (int i = sfKeyUp; i <= sfKeyDown; i++) {
        if (sfKeyboard_isKeyPressed(i)) {
            game->player->dest.y += size[i - sfKeyUp];
            game->player->dest.y += collision(game, \
            (size[i - sfKeyUp] * -1));
            set_character_dir(&game->player->dir, size[i - sfKeyUp], 'y');
            return;
        }
    }
    for (int i = sfKeyLeft; i <= sfKeyRight; i++) {
        if (sfKeyboard_isKeyPressed(i)) {
            game->player->dest.x += size[i - sfKeyLeft];
            game->player->dest.x += collision(game, \
            (size[i - sfKeyLeft] * -1));
            set_character_dir(&game->player->dir, size[i - sfKeyLeft], 'x');
            return;
        }
    }
}