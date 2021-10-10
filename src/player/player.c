/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for my_rpg project
*/

#include "player.h"
#include "fight.h"

void fill_character_stats(character_t *perso, int *stats)
{
    perso->stats->hp_max = stats[0];
    perso->stats->hp = stats[0];
    perso->stats->mp_max = stats[1];
    perso->stats->mp = stats[1];
    perso->stats->atk = stats[2];
    perso->stats->def = stats[3];
    perso->stats->atk_mag = stats[4];
    perso->stats->def_mag = stats[5];
    perso->stats->crit = stats[6];
    perso->stats->speed = stats[7];
    perso->stats->exp = stats[8];
    perso->stats->level = stats[9];
}

player_t *create_main_player(void)
{
    sfVector2f origin = {16, 16};
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return (NULL);
    player->player = sprite_creator("assets/sprites/player.png", 768, 512);
    player->player->pos_s.top = 0;
    player->player->pos_s.left = 0;
    player->player->pos_s.width = 32;
    player->player->pos_s.height = 32;
    sfSprite_setTextureRect(player->player->s, player->player->pos_s);
    sfSprite_setOrigin(player->player->s, origin);
    player->dir = DOWN;
    return (player);
}

character_t **init_character_tab(void)
{
    character_t **characters = malloc(sizeof(character_t *) * 5);

    if (characters == NULL)
        return (NULL);
    characters[0] = init_hero(characters[0]);
    characters[1] = init_ally_one(characters[1]);
    characters[2] = init_ally_two(characters[2]);
    characters[3] = init_ally_three(characters[3]);
    characters[4] = NULL;
    characters[0]->attack = init_hero_power();
    characters[1]->attack = init_egoline_power();
    characters[2]->attack = init_hero_power();
    characters[3]->attack = init_hero_power();
    characters[0]->played = 0;
    characters[1]->played = 0;
    characters[2]->played = 0;
    characters[3]->played = 0;
    return (characters);
}