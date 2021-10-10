/*
** EPITECH PROJECT, 2019
** target_player.c
** File description:
** center the camera n the main player
*/

#include "rpg.h"

int get_last_column(cell_t **map)
{
    int count = 0;

    while (map[count] != NULL)
        count++;
    return (count - 1);
}

int get_last_line(cell_t ***map)
{
    int count = 0;

    while (map[count] != NULL)
        count++;
    return (count - 1);
}

bool target_player_y(game_t *game, sfVector2f corner_tl, sfVector2f corner_br)
{
    int last_line = get_last_line(game->map);
    int last_column = get_last_column(game->map[last_line]);

    if (game->map[0][0]->pos.y > corner_tl.y) {
        return (false);
    }
    if (game->map[last_line][last_column]->pos.y < corner_br.y) {
        return (false);
    }
    return (true);
}

bool target_player_x(game_t *game, sfVector2f corner_tl, sfVector2f corner_br)
{
    int last_line = get_last_line(game->map);
    int last_column = get_last_column(game->map[last_line]);

    if (game->map[0][0]->pos.x > corner_tl.x) {
        return (false);
    }
    if (game->map[last_line][last_column]->pos.x < corner_br.x) {
        return (false);
    }
    return (true);
}

void target_player(game_t *game)
{
    sfVector2f view_pos = sfView_getCenter(game->view);
    sfVector2f pos = sfSprite_getPosition(game->player->player->s);
    sfVector2f size = sfView_getSize(game->view);
    sfVector2f corner_tl = {pos.x - (size.x / 2), pos.y - (size.y / 2)};
    sfVector2f corner_br = {pos.x + (size.x / 2), pos.y + (size.y / 2)};

    if (target_player_x(game, corner_tl, corner_br) == true) {
        view_pos.x = pos.x;
        sfView_setCenter(game->view, view_pos);
    }
    if (target_player_y(game, corner_tl, corner_br) == true) {
        view_pos.y = pos.y;
        sfView_setCenter(game->view, view_pos);
    }
}