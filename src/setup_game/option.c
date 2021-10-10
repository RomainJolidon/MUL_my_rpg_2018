/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** option
*/

#include "rpg.h"

void display_option(game_t *game)
{
    display_parallax(game->window, game->menu->parallax);
    for (int i = 0; i != 3; i++)
        draw_button_menu(game, game->opt->button[i]);
    cursor_effect(game);
}

void return_menu(game_t *game)
{
    game->state = MENU;
}

option_t *init_option(void)
{
    option_t *opt = malloc(sizeof(*opt));

    if (!opt)
        return (NULL);
    if ((opt->button = malloc(sizeof(*opt->button) * 4)) == NULL)
        return (NULL);
    opt->button[0] = create_volume_button(PATH_DOWN_B, \
    change_current_music_volume, VOLUME_DOWN);
    opt->button[1] = create_volume_button(PATH_UP_B, \
    change_current_music_volume, VOLUME_UP);
    opt->button[2] = create_button(PATH_RETURN_MENU_B, return_menu, RETURN);
    opt->button[3] = NULL;
    for (int i = 0; i != 3; i++) {
        if (!opt->button[i])
            return (NULL);
    }
    set_button_attribute(opt->button[0], POS_DOWN_B, SIZE_DOWN_B);
    set_button_attribute(opt->button[1], POS_UP_B, SIZE_UP_B);
    set_button_attribute(opt->button[2], POS_RETURN_MENU_B, \
    SIZE_RETURN_MENU_B);
    return (opt);
}