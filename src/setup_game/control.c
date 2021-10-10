/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** control
*/

#include "rpg.h"
#include "define.h"

void display_ctrl(game_t *game)
{
    display_parallax(game->window, game->menu->parallax);
    for (int i = 0; i != 5; i++) {
        sfRenderWindow_drawSprite(game->window, game->ctrl[i]->e->s, NULL);
        sfRenderWindow_drawText(game->window, game->ctrl[i]->text->str, NULL);
    }
    draw_button_menu(game, game->pse->button[2]);
    cursor_effect(game);
}

control_t **init_control(void)
{
    control_t **obj = malloc(sizeof(*obj) * 6);
    ctrl_value_t v[5] = {
        {POS_C_ARROW, POS_TC_ARROW, SIZE_C_ARROW, "Move player"},
        {POS_C_E, POS_TC_E, SIZE_C_E, "Interact"},
        {POS_C_I, POS_TC_I, SIZE_C_I, "Open inventory"},
        {POS_C_Q, POS_TC_Q, SIZE_C_Q, "Open pause menu"},
        {POS_C_MOUSE, POS_TC_MOUSE, SIZE_C_MOUSE, "In fight, go back"}
    };
    if (!obj)
        return (NULL);
    for (int i = 0; i != 5; i++) {
        obj[i] = malloc(sizeof(*obj[i]));
        obj[i]->e = create_entity(PATH_CTRL, v[i].pos, v[i].rect);
        obj[i]->text = text_creator(v[i].text, PATH_PIXEL_F, v[i].t_pos, 30);
        if (!obj[i]->e)
            return (NULL);
    }
    obj[5] = NULL;
    return (obj);
}