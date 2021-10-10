/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018d
** File description:
** add_object
*/

#include "rpg.h"
#include "define.h"

sfText *create_text(char *str, sfVector2f pos)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(PATH_PIXEL_F);

    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    sfText_setString(text, str);
    return (text);
}

void add_new_object(obj_value_t object, sfVector2i place, inventory_t *inv)
{
    sfVector2f pos;

    if (my_strcmp(object.name, "None") == 0)
        return;
    inv->obj[place.y][place.x].name = create_text(object.name, \
    fill_vector_2f(5, 10));
    inv->obj[place.y][place.x].detail = create_text(object.detail, \
    fill_vector_2f(5, 100));
    pos.x = inv->obj[place.y][place.x].hitbox.left;
    pos.y = inv->obj[place.y][place.x].hitbox.top;
    inv->obj[place.y][place.x].obj = create_entity(PATH_ITEM, pos, object.rect);
    sfSprite_setPosition(inv->obj[place.y][place.x].obj->s, pos);
    sfSprite_setScale(inv->obj[place.y][place.x].obj->s, fill_vector_2f(3, 3));
}

obj_value_t init_obj_value(char *name, char *detail, sfIntRect rect)
{
    obj_value_t obj;

    obj.name = name;
    obj.detail = detail;
    obj.rect = rect;
    return (obj);
}