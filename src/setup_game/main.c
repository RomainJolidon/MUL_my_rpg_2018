/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for my_rpg project
*/

#include "fight.h"
#include "player.h"
#include "memory.h"

int main(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return (ERROR);
    if (prepare_assets(game) != true)
        return (ERROR);
    window_creator(game);
    gaming(game);
    destroy_fight(game->scene);
    free_game(game);
    return (0);
}
