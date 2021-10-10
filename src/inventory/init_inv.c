/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018d
** File description:
** init_inv
*/

#include "rpg.h"
#include "define.h"

entity_t *create_entity(char *path, sfVector2f pos, sfIntRect rect)
{
    entity_t *e = malloc(sizeof(*e));

    if (!e)
        return (NULL);
    e->s = sfSprite_create();
    e->t = sfTexture_createFromFile(path, NULL);
    e->pos = pos;
    e->pos_s = rect;
    sfSprite_setTexture(e->s, e->t, sfFalse);
    sfSprite_setPosition(e->s, e->pos);
    sfSprite_setTextureRect(e->s, e->pos_s);
    return (e);
}

void set_variable(inventory_t *inv)
{
    inv->hud = create_entity(PATH_INV, POS_INV, SIZE_INV);
    inv->pointer = create_entity(PATH_POINT, POS_POINT, SIZE_POINT);
    inv->info = malloc(sizeof(*inv->info));
    inv->info->infobox = create_entity(PATH_INFO, POS_INFO, SIZE_INFO);
    inv->info->layer = create_entity(PATH_INFO, POS_INFO, SIZE_LAYER_INFO);
    inv->info->visible = false;
    inv->state = NONE;
    sfSprite_setScale(inv->pointer->s, fill_vector_2f(5, 5));
    sfSprite_setScale(inv->info->infobox->s, fill_vector_2f(5, 5));
    sfSprite_setScale(inv->info->layer->s, fill_vector_2f(5, 5));
    sfSprite_setColor(inv->info->layer->s, \
sfColor_fromRGBA(255, 255, 255, 100));
}

void set_object(inventory_t *inv)
{
    int top = 268;
    int left;

    for (int y = 0; y != 4; y++) {
        left = 201;
        for (int x = 0; x != 8; x++) {
            inv->obj[y][x].hitbox = fill_intrect(top, left, 50, 50);
            inv->obj[y][x].obj = NULL;
            inv->obj[y][x].name = NULL;
            inv->obj[y][x].detail = NULL;
            left+=74;
        }
        top+=74;
    }
}

inventory_t *create_inv(void)
{
    inventory_t *inv = malloc(sizeof(*inv));

    if (!inv)
        return (NULL);
    set_variable(inv);
    if (!inv->hud || !inv->pointer || !inv->info->infobox || !inv->info->layer)
        return (NULL);
    sfSprite_setScale(inv->hud->s, fill_vector_2f(2, 2));
    sfSprite_setOrigin(inv->hud->s, CENTER_INV);
    set_object(inv);
    return (inv);
}