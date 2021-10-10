/*
** EPITECH PROJECT, 2019
** camera.c
** File description:
** all related to game view
*/

#include "rpg.h"

int click_button(sfVector2i mouse, game_t *game)
{
    sfVector2i base_pos = sfMouse_getPositionRenderWindow(game->window);
    int x_vector = base_pos.x - mouse.x;
    int y_vector = base_pos.y - mouse.y;
    sfVector2f move = {-x_vector, -y_vector};

    sfView_move(game->view, move);
    return (0);
}

void zoom_screen(game_t *game, sfEvent event)
{
    static float cam = 0.5;
    float zoom = 1 - event.mouseWheelScroll.delta / 30;

    cam -= event.mouseWheelScroll.delta / 50;
    if (cam > 0.5 && cam < 1.5)
        sfView_zoom(game->view, zoom);
    else if (cam > 1.5)
        cam = 1.5;
    if (cam < 0.5)
        cam = 0.5;
}