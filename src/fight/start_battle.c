/*
** EPITECH PROJECT, 2019
** start_battle.c
** File description:
** check when start a battle
*/

#include "fight.h"

void start_battle(game_t *game)
{
    sfView const *view = sfRenderWindow_getDefaultView(game->window);
    sfVector2f pos = sfSprite_getPosition(game->player->player->s);
    sfIntRect safe_zone = {288, 96, 1312, 896};
    static int luck = 5;

    srand(time(NULL));
    if (sfIntRect_contains(&safe_zone, pos.x, pos.y) == sfTrue)
        return;
    if (rand() % 100 < luck) {
        sfRenderWindow_setView(game->window, view);
        if (prepare_fight(game) == ERROR)
            return;
        game->transition = create_transition(game->transition);
        game->state = FIGHT;
        luck = -5;
    } else
        luck += 5;
}