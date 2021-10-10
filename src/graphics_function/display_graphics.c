/*
** EPITECH PROJECT, 2019
** print_graphics.c
** File description:
** print all related to graphical
*/

#include "rpg.h"

void update_stats_xp(text_t **stats, character_t **characters)
{
    int count = 2;

    for (int i = 0; characters[i] != NULL; i++) {
        sfText_setString(stats[count]->str, \
        int_to_str(characters[i]->stats->exp));
        count++;
        sfText_setString(stats[count]->str, \
        int_to_str(characters[i]->stats->level));
        count += 3;
    }
}

void display_inventory(game_t *game, inventory_t *inv)
{
    sfView const *view = sfRenderWindow_getDefaultView(game->window);

    sfRenderWindow_setView(game->window, view);
    sfRenderWindow_drawSprite(game->window, inv->hud->s, NULL);
    for (int i = 0; game->characters[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(game->window, \
        game->characters[i]->healthbackground, NULL);
        sfRenderWindow_drawRectangleShape(game->window, \
        game->characters[i]->healthbar, NULL);
        sfRenderWindow_drawSprite(game->window, \
        game->characters[i]->icon->s, NULL);
    }
    update_stats_xp(inv->stats_xp, game->characters);
    for (int i = 0; inv->stats_xp[i] != NULL; i++)
        sfRenderWindow_drawText(game->window, inv->stats_xp[i]->str, NULL);
    check_inv(inv, game);
}

void display_menu(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    static int key = 0;

    display_parallax(game->window, game->menu->parallax);
    if (game->menu->selection != true) {
        for (int i = 0; i != 4; i++)
            draw_button_menu(game, game->menu->main[i]);
    } else {
        for (int i = 0; i != 3; i++)
            draw_button_menu(game, game->menu->save[i]);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (key == 0) {
            key = 1;
            cursor(game, mouse_pos.x, mouse_pos.y, 2);
        }
    } else
        key = 0;
    cursor_effect(game);
}

void display_volume_menu(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    static int key = 0;

    display_parallax(game->window, game->menu->parallax);
    if (game->menu->selection != true) {
        for (int i = 0; i != 3; i++)
            draw_button_menu(game, game->menu->main[i]);
    } else {
        for (int i = 0; i != 3; i++)
            draw_button_menu(game, game->menu->save[i]);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (key == 0) {
            key = 1;
            cursor(game, mouse_pos.x, mouse_pos.y, 2);
        }
    } else
        key = 0;
    cursor_effect(game);
}