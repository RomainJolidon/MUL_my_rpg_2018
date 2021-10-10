/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018d
** File description:
** inventory
*/

#include "rpg.h"

int info(inventory_t *inv, game_t *game, int x, int y)
{
    sfRenderWindow_drawText(game->window, inv->obj[y][x].name, NULL);
    sfRenderWindow_drawText(game->window, inv->obj[y][x].detail, NULL);
    return (0);
}

int use(inventory_t *inv, game_t *game, int x, int y)
{
    if (my_strcmp(sfText_getString(inv->obj[y][x].name), \
    "Health potion") == 0) {
        for (int i = 0; game->characters[i] != NULL; i++)
            game->characters[i]->stats->hp += 30;
    }
    for (int i = 0; game->characters[i] != NULL; i++) {
        if (game->characters[i]->stats->hp > \
            game->characters[i]->stats->hp_max)
            game->characters[i]->stats->hp = \
            game->characters[i]->stats->hp_max;
    }
    check_life(game);
    inv->obj[y][x].obj = NULL;
    inv->obj[y][x].name = NULL;
    inv->obj[y][x].detail = NULL;
    return (-1);
}

int move(inventory_t *inv, game_t *game, int x, int y)
{
    if (inv->state == STOP) {
        inv->state = NONE;
        return (-1);
    }
    inv->state = MOVE;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfIntRect rect = sfSprite_getTextureRect(inv->obj[y][x].obj->s);
    sfSprite_setPosition(inv->obj[y][x].obj->s, \
fill_vector_2f(mouse.x - rect.width / 2 , mouse.y - rect.height / 2));
    sfRenderWindow_drawSprite(game->window, inv->obj[y][x].obj->s, NULL);
    return (2);
}

int check_infobox_button(inventory_t *inv, sfVector2i mouse, int i)
{
    int select = -1;
    sfVector2f pos = sfSprite_getPosition(inv->info->infobox->s);
    sfIntRect *rect[3] = {INFO_RECT(pos.x, pos.y), \
        USE_RECT(pos.x, pos.y), \
        MOVE_RECT(pos.x, pos.y)};

    if (sfIntRect_contains(rect[i], mouse.x, mouse.y) == sfTrue) {
        sfSprite_setPosition(inv->info->layer->s, \
fill_vector_2f(rect[i]->left, rect[i]->top));
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            select = i;
            inv->info->visible = false;
            while (sfMouse_isButtonPressed(sfMouseLeft));
            return (select);
        }
    }
    return (-1);
}

int browse_infobox(inventory_t *inv, sfVector2i mouse)
{
    int select;

    for (int i = 0; i != 3; i++) {
        select = check_infobox_button(inv, mouse, i);
        if (select != -1)
            return (select);
    }
    return (-1);
}