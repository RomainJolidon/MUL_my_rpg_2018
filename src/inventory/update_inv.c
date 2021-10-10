/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018d
** File description:
** update_inv
*/

#include "rpg.h"
#include "define.h"

void check_menu_inv(inventory_t *inv, game_t *game, int x, int y)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    int (*ptr[3])(inventory_t *, game_t *, int, int) = {info, use, move};
    static int select = -1;

    if (select != -1)
        select = (*ptr[select])(inv, game, x, y);
    if (inv->info->visible == true) {
        if ((select = browse_infobox(inv, mouse)) != -1) {
            return;
        }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && \
sfIntRect_contains(&inv->hud->pos_s, mouse.x, mouse.y) == sfFalse)
        inv->info->visible = false;
}

void drop_object(inventory_t *inv, pos_t pos, pos_t static_pos)
{
    sfSprite_setPosition(inv->obj[static_pos.y][static_pos.x].obj->s, \
fill_vector_2f(inv->obj[pos.y][pos.x].hitbox.left, \
inv->obj[pos.y][pos.x].hitbox.top));
    inv->obj[pos.y][pos.x].obj = inv->obj[static_pos.y][static_pos.x].obj;
    inv->obj[pos.y][pos.x].obj->pos.x = inv->obj[pos.y][pos.x].hitbox.left;
    inv->obj[pos.y][pos.x].obj->pos.y = inv->obj[pos.y][pos.x].hitbox.top;
    inv->obj[static_pos.y][static_pos.x].obj = NULL;
    inv->obj[pos.y][pos.x].name = inv->obj[static_pos.y][static_pos.x].name;
    inv->obj[pos.y][pos.x].detail = inv->obj[static_pos.y][static_pos.x].detail;
    inv->obj[static_pos.y][static_pos.x].name = NULL;
    inv->obj[static_pos.y][static_pos.x].detail = NULL;
    inv->state = STOP;
}

pos_t move_layer(inventory_t *inv, game_t *game, pos_t p, pos_t s_p)
{
    inv->info->visible = true;
    s_p.x = p.x;
    s_p.y = p.y;
    sfSprite_setPosition(inv->info->layer->s, \
fill_vector_2f(inv->obj[p.y][p.x].obj->pos.x + \
inv->obj[p.y][p.x].obj->pos_s.width / 2 + 5, \
inv->obj[p.y][p.x].obj->pos.y + inv->obj[p.y][p.x].obj->pos_s.height / 2 + 5));
    sfSprite_setPosition(inv->info->infobox->s, \
fill_vector_2f(inv->obj[p.y][p.x].obj->pos.x + \
inv->obj[p.y][p.x].obj->pos_s.width / 2, \
inv->obj[p.y][p.x].obj->pos.y + inv->obj[p.y][p.x].obj->pos_s.height / 2));
    sfRenderWindow_drawSprite(game->window, inv->info->infobox->s, NULL);
    return (s_p);
}

pos_t browse_in_object(inventory_t *inv, game_t *game, pos_t p, pos_t s_p)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    if (sfIntRect_contains(&inv->obj[p.y][p.x].hitbox, mouse.x, mouse.y) \
== sfTrue) {
        sfSprite_setPosition(inv->pointer->s, \
fill_vector_2f(inv->obj[p.y][p.x].hitbox.left, inv->obj[p.y][p.x].hitbox.top));
        sfRenderWindow_drawSprite(game->window, inv->pointer->s, NULL);
        if (inv->state == MOVE && \
sfMouse_isButtonPressed(sfMouseLeft) && inv->obj[p.y][p.x].obj == NULL)
            drop_object(inv, p, s_p);
        else if (inv->state == NONE && \
sfMouse_isButtonPressed(sfMouseRight) && inv->obj[p.y][p.x].obj != NULL)
            s_p = move_layer(inv, game, p, s_p);
    }
    if (inv->obj[p.y][p.x].obj != NULL)
        sfRenderWindow_drawSprite(game->window, \
inv->obj[p.y][p.x].obj->s, NULL);
    return (s_p);
}

void check_inv(inventory_t *inv, game_t *game)
{
    static pos_t static_pos = {0, 0};
    pos_t pos = {0, 0};

    for (int y = 0; y != 4; y++) {
        for (int x = 0; x != 8; x++) {
            pos.x = x;
            pos.y = y;
            static_pos = browse_in_object(inv, game, pos, static_pos);
        }
    }
    check_menu_inv(inv, game, static_pos.x, static_pos.y);
    if (inv->info->visible == true) {
        sfRenderWindow_drawSprite(game->window, inv->info->infobox->s, NULL);
        sfRenderWindow_drawSprite(game->window, inv->info->layer->s, NULL);
    }
}