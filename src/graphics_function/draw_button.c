/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "rpg.h"

void draw_button_game(game_t *game, button_t *but)
{
    sfVector2i pos_mouse;

    pos_mouse = sfMouse_getPositionRenderWindow(game->window);
    if (pos_mouse.y >= but->surf.top &&\
    pos_mouse.y <= (but->surf.top + but->surf.height)\
    && pos_mouse.x >= but->surf.left &&\
    pos_mouse.x <= (but->surf.left + but->surf.width)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            but->e->pos_s.top = (but->e->pos_s.height * 2) + 5;
        } else if (but->e->pos_s.top == (but->e->pos_s.height * 2) + 5) {
            sfMusic_play(game->music[4]);
            but->action_b(game);
            but->e->pos_s.top = but->e->pos_s.height + 5;
        } else
            but->e->pos_s.top = but->e->pos_s.height + 5;
    } else
        but->e->pos_s.top = 5;
    if (but->state == B_TOGGLE)
        but->action_b(game);
    sfSprite_setTextureRect(but->e->s, but->e->pos_s);
    sfRenderWindow_drawSprite(game->window, but->e->s, NULL);
}

void select_action(game_t *game, button_t *but)
{
    if (but->type != VOLUME_DOWN && but->type != VOLUME_UP)
        but->action_b(game);
    if (but->type == VOLUME_DOWN)
        but->action_volume(game, false);
    if (but->type == VOLUME_UP)
        but->action_volume(game, true);
}

void draw_button_menu(game_t *game, button_t *but)
{
    sfVector2i pos_mouse;

    pos_mouse = sfMouse_getPositionRenderWindow(game->window);
    if (pos_mouse.y >= but->surf.top &&\
    pos_mouse.y <= (but->surf.top + but->surf.height)\
    && pos_mouse.x >= but->surf.left &&\
    pos_mouse.x <= (but->surf.left + but->surf.width)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            but->e->pos_s.top = but->e->pos_s.height * 2 + 25;
        } else if (but->e->pos_s.top == but->e->pos_s.height * 2 + 25) {
            sfMusic_play(game->music[4]);
            select_action(game, but);
            but->e->pos_s.top = but->e->pos_s.height + 15;
        } else
            but->e->pos_s.top = but->e->pos_s.height + 15;
    } else
        but->e->pos_s.top = 5;
    if (but->state == B_TOGGLE)
        but->action_b(game);
    sfSprite_setTextureRect(but->e->s, but->e->pos_s);
    sfRenderWindow_drawSprite(game->window, but->e->s, NULL);
}