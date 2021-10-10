/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** menu
*/

#include "memory.h"

void create_save_menu(menu_t *menu)
{
    menu->save = malloc(sizeof(*menu->save) * 3);
    if (!menu->save)
        return;
    menu->save[0] = create_button(PATH_NEW_B, begin_game, PLAY);
    menu->save[1] = create_button(PATH_LOAD_B, load_save, OPTION);
    menu->save[2] = create_button(PATH_CROSS_B, close_game, CROSS);
    for (int i = 0; i != 3; i++) {
        if (!menu->save[i])
            return;
    }
    set_button_attribute(menu->save[0], POS_NEW_B, SIZE_NEW_B);
    set_button_attribute(menu->save[1], POS_LOAD_B, SIZE_LOAD_B);
    set_button_attribute(menu->save[2], POS_CROSS_B, SIZE_CROSS_B);
    menu->selection = false;
    menu->parallax = create_parallax();
}

void how_to_play_menu(game_t *game)
{
    game->state = HOW_TO_PLAY;
}

menu_t *create_menu(void)
{
    menu_t *menu = malloc(sizeof(*menu));

    if (!menu)
        return (NULL);
    if (!(menu->main = malloc(sizeof(*menu->main) * 4)))
        return (NULL);
    menu->main[0] = create_button(PATH_PLAY_B, start_selection, PLAY);
    menu->main[1] = create_button(PATH_OPTION_B, start_options, OPTION);
    menu->main[2] = create_button(PATH_CROSS_B, close_game, CROSS);
    menu->main[3] = create_button(PATH_HOW_B, how_to_play_menu, HOW);
    for (int i = 0; i != 3; i++) {
        if (!menu->main[i])
            return (NULL);
    }
    set_button_attribute(menu->main[0], POS_PLAY_B, SIZE_PLAY_B);
    set_button_attribute(menu->main[1], POS_OPTION_B, SIZE_OPTION_B);
    set_button_attribute(menu->main[2], POS_CROSS_B, SIZE_CROSS_B);
    set_button_attribute(menu->main[3], POS_HOW_B, SIZE_HOW_B);
    create_save_menu(menu);
    return (menu);
}

void destroy_menu(menu_t *menu)
{
    for (int i = 0; i != 3; i++) {
        free_entity(menu->main[i]->e);
        free(menu->main[i]);
    }
    free(menu->main);
    free(menu);
}