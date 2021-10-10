/*
** EPITECH PROJECT, 2019
** create_parallax->c
** File description:
** create parallax
*/

#include "rpg.h"

void display_parallax(sfRenderWindow *window, parallax_t **para)
{
    float decal = 0.5;

    for (int i = 0; para[i] != NULL; i++) {
        para[i]->pos_1.x -= decal;
        if (para[i]->pos_1.x <= -WIDTH)
            para[i]->pos_1.x += 2 * WIDTH - decal;
        sfSprite_setPosition(para[i]->sprite_1, para[i]->pos_1);
        para[i]->pos_2.x -= decal;
        if (para[i]->pos_2.x <= -WIDTH)
            para[i]->pos_2.x += 2 * WIDTH - decal;
        decal += 0.5;
    }
    for (int i = 0; para[i] != NULL; i++) {
        sfRenderWindow_drawSprite(window, para[i]->sprite_1, NULL);
        sfSprite_setPosition(para[i]->sprite_1, para[i]->pos_2);
        sfRenderWindow_drawSprite(window, para[i]->sprite_1, NULL);
    }
}

parallax_t *add_parallax(char *str)
{
    parallax_t *para = malloc(sizeof(parallax_t));

    if (!para)
        return (NULL);
    para->texture = sfTexture_createFromFile(str, NULL);
    para->sprite_1 = sfSprite_create();
    sfSprite_setTexture(para->sprite_1, para->texture, sfTrue);
    para->pos_1.x = 0;
    para->pos_1.y = 0;
    para->pos_2.x = WIDTH;
    para->pos_2.y = 0;
    sfSprite_setPosition(para->sprite_1, para->pos_1);
    sfSprite_scale(para->sprite_1, fill_vector_2f(2.5, 3.7));
    return (para);
}

parallax_t **create_parallax(void)
{
    parallax_t **parallax = malloc(sizeof(*parallax) * 9);

    parallax[0] = add_parallax("assets/parallax/sky.png");
    parallax[1] = add_parallax("assets/parallax/far_mountains_fc.png");
    parallax[2] = add_parallax("assets/parallax/grassy_mountains_fc.png");
    parallax[3] = add_parallax("assets/parallax/clouds_mid_fc.png");
    parallax[4] = add_parallax("assets/parallax/clouds_mid_t_fc.png");
    parallax[5] = add_parallax("assets/parallax/hill.png");
    parallax[6] = add_parallax("assets/parallax/clouds_front_fc.png");
    parallax[7] = add_parallax("assets/parallax/clouds_front_t_fc.png");
    parallax[8] = NULL;
    return (parallax);
}