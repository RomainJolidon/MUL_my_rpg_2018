/*
** EPITECH PROJECT, 2019
** create_players.c
** File description:
** set all differents players in the game
*/

#include "player.h"

char *fill_name(char *str)
{
    int count = 0;
    int size = my_strlen(str);
    char *output = malloc(sizeof(char) * (size + 1));

    for (; count < size; count++)
        output[count] = str[count];
    output[count] = '\0';
    return (output);
}

character_t *init_hero(character_t *perso)
{
    int stats[10] = {100, 10, 15, 10, 15, 10, 20, 10, 0, 1};
    perso = malloc(sizeof(*perso));
    perso->stats = malloc(sizeof(*perso->stats));
    perso->name = fill_name("Mimosa");
    fill_character_stats(perso, stats);
    perso->e = sprite_creator("assets/sprites/Mimosa.png", 750, 225);
    perso->e->pos_s.top = 33;
    perso->e->pos_s.left = 0;
    perso->e->pos_s.width = 32;
    perso->e->pos_s.height = 32;
    perso->enemy = false;
    sfVector2f scale = {2, 2};
    sfSprite_scale(perso->e->s, scale);
    healthbar_and_icon_creator(perso, 0);
    return (perso);
}

character_t *init_ally_one(character_t *perso)
{
    int stats[10] = {50, 30, 5, 10, 30, 25, 20, 5, 0, 1};
    perso = malloc(sizeof(*perso));
    perso->stats = malloc(sizeof(*perso->stats));
    perso->name = fill_name("Egoline");
    fill_character_stats(perso, stats);
    perso->e = sprite_creator("assets/sprites/Egoline.png", 750, 300);
    perso->enemy = false;
    sfVector2f scale = {2, 2};
    sfSprite_scale(perso->e->s, scale);
    healthbar_and_icon_creator(perso, 1);
    return (perso);
}

character_t *init_ally_two(character_t *perso)
{
    int stats[10] = {150, 5, 25, 20, 5, 5, 5, 2, 0, 1};
    perso = malloc(sizeof(*perso));
    perso->stats = malloc(sizeof(*perso->stats));
    perso->name = fill_name("Romani Shell");
    fill_character_stats(perso, stats);
    perso->e = sprite_creator("assets/sprites/Romani_Shell.png", 750, 375);
    perso->enemy = false;
    sfVector2f scale = {2, 2};
    sfSprite_scale(perso->e->s, scale);
    healthbar_and_icon_creator(perso, 2);
    return (perso);
}

character_t *init_ally_three(character_t *perso)
{
    int stats[10] = {100, 15, 20, 0, 120, 0, 35, 25, 0, 1};
    perso = malloc(sizeof(*perso));
    perso->stats = malloc(sizeof(*perso->stats));
    perso->name = fill_name("W. Gomesu");
    fill_character_stats(perso, stats);
    perso->e = sprite_creator("assets/sprites/Watashino_Gomesu.png", 750, 450);
    perso->enemy = false;
    sfVector2f scale = {2, 2};
    sfSprite_scale(perso->e->s, scale);
    healthbar_and_icon_creator(perso, 3);
    return (perso);
}