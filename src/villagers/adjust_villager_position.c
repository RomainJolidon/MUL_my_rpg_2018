/*
** EPITECH PROJECT, 2019
** adjust_villager_position.c
** File description:
** adjust villager position
*/

#include "rpg.h"

void adjust_villager_position_y(pnj_t *villager)
{
    if (villager->info->pos.y != villager->dest.y) {
        change_sprite_horizontale(&villager->pos_s, 32, 32 * 3);
        villager->is_moving = true;
        if (villager->dest.y - villager->info->pos.y < 0) {
            villager->info->pos.y -= 4;
            set_sprite_vertical(&villager->pos_s, 96);
            sfSprite_setPosition(villager->info->sprite, villager->info->pos);
        } else {
            villager->info->pos.y += 4;
            set_sprite_vertical(&villager->pos_s, 0);
            sfSprite_setPosition(villager->info->sprite, villager->info->pos);
        }
        sfSprite_setTextureRect(villager->info->sprite, villager->pos_s);
        return;
    }
    villager->is_moving = false;
}

void adjust_villager_position_x(pnj_t *villager)
{
    set_character_position(villager->info->sprite, \
&villager->pos_s, villager->dir);
    if (villager->info->pos.x != villager->dest.x) {
        change_sprite_horizontale(&villager->pos_s, 32, 32 * 3);
        villager->is_moving = true;
        if (villager->dest.x - villager->info->pos.x < 0) {
            villager->info->pos.x -= 4;
            set_sprite_vertical(&villager->pos_s, 32);
            sfSprite_setPosition(villager->info->sprite, villager->info->pos);
        } else {
            villager->info->pos.x += 4;
            set_sprite_vertical(&villager->pos_s, 64);
            sfSprite_setPosition(villager->info->sprite, villager->info->pos);
        }
        sfSprite_setTextureRect(villager->info->sprite, villager->pos_s);
        return;
    }
    adjust_villager_position_y(villager);
}