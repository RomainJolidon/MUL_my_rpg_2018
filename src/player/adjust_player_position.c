/*
** EPITECH PROJECT, 2019
** adjust_player_position.c
** File description:
** adjust playe rposition
*/

#include "rpg.h"

void adjust_player_position_y(player_t *player)
{
    if (player->player->pos.y != player->dest.y) {
        change_sprite_horizontale(&player->player->pos_s, 32, 32 * 3);
        player->is_moving = true;
        if (player->dest.y - player->player->pos.y < 0) {
            player->player->pos.y -= 8;
            sfSprite_setPosition(player->player->s, player->player->pos);
        } else {
            player->player->pos.y += 8;
            sfSprite_setPosition(player->player->s, player->player->pos);
        }
        sfSprite_setTextureRect(player->player->s, player->player->pos_s);
        return;
    }
    player->is_moving = false;
}

void adjust_player_position_x(player_t *player)
{
    set_character_position(player->player->s, \
&player->player->pos_s, player->dir);
    if (player->player->pos.x != player->dest.x) {
        change_sprite_horizontale(&player->player->pos_s, 32, 32 * 3);
        player->is_moving = true;
        if (player->dest.x - player->player->pos.x < 0) {
            player->player->pos.x -= 8;
            sfSprite_setPosition(player->player->s, player->player->pos);
        } else {
            player->player->pos.x += 8;
            sfSprite_setPosition(player->player->s, player->player->pos);
        }
        sfSprite_setTextureRect(player->player->s, player->player->pos_s);
        return;
    }
    adjust_player_position_y(player);
}