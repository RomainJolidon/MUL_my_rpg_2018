/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** pause
*/

#include "rpg.h"

void display_pause(game_t *game)
{
    display_parallax(game->window, game->menu->parallax);
    for (int i = 0; i != 3; i++)
        draw_button_menu(game, game->pse->button[i]);
    cursor_effect(game);
}

void resume_game(game_t *game)
{
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    game->state = GAME;
}

pause_t *init_pause(void)
{
    pause_t *pse = malloc(sizeof(*pse));

    if (!pse)
        return (NULL);
    if ((pse->button = malloc(sizeof(*pse->button) * 4)) == NULL)
        return (NULL);
    pse->button[0] = create_button(PATH_RESUME_B, resume_game, RESUME);
    pse->button[1] = create_button(PATH_SAVE_B, write_save, SAVE);
    pse->button[2] = create_button(PATH_RETURN_MENU_B, return_menu, CROSS);
    pse->button[3] = NULL;
    for (int i = 0; i != 3; i++) {
        if (!pse->button[i])
            return (NULL);
    }
    set_button_attribute(pse->button[0], POS_RESUME_B, SIZE_RESUME_B);
    set_button_attribute(pse->button[1], POS_SAVE_B, SIZE_SAVE_B);
    set_button_attribute(pse->button[2], POS_RETURN_MENU_B, SIZE_RETURN_MENU_B);
    return (pse);
}