/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for my_rpg project
*/

#include "rpg.h"

void healthbar_and_icon_creator(character_t *perso, int type)
{
    if (type == 0) {
        perso->healthbar = init_rectangleshape(1, 650, 590);
        perso->healthbackground = init_rectangleshape(0, 650, 590);
        perso->icon = sprite_creator("assets/fight/Mimosa.png", 860, 580);
    }
    if (type == 1) {
        perso->healthbar = init_rectangleshape(1, 650, 635);
        perso->healthbackground = init_rectangleshape(0, 650, 635);
        perso->icon = sprite_creator("assets/fight/Egoline.png", 860, 625);
    }
    if (type == 2) {
        perso->healthbar = init_rectangleshape(1, 650, 685);
        perso->healthbackground = init_rectangleshape(0, 650, 685);
        perso->icon = sprite_creator("assets/fight/Romani.png", 860, 675);
    }
    if (type == 3) {
        perso->healthbar = init_rectangleshape(1, 650, 730);
        perso->healthbackground = init_rectangleshape(0, 650, 730);
        perso->icon = sprite_creator("assets/fight/Watashi.png", 860, 725);
    }
}

sfRectangleShape *init_rectangleshape(int type, int posx, int posy)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfVector2f position;

    position.x = posx;
    position.y = posy;
    sfRectangleShape_setPosition(shape, position);
    if (type == 0) {
        position.x = 200;
        position.y = 20;
        sfRectangleShape_setSize(shape, position);
        sfRectangleShape_setOutlineThickness(shape, 5);
        sfRectangleShape_setFillColor(shape, sfRed);
        sfRectangleShape_setOutlineColor(shape, sfBlack);
    }
    else if (type == 1) {
        position.x = 200;
        position.y = 20;
        sfRectangleShape_setSize(shape, position);
        sfRectangleShape_setFillColor(shape, sfColor_fromRGB(97, 226, 119));
    }
    return (shape);
}