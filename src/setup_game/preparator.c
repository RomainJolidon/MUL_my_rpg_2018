/*
** EPITECH PROJECT, 2018
** preparator.c
** File description:
** preparation for sprites and windows
*/

#include "player.h"

void game_preparation(game_t *game)
{
    game->c = init_cursor();
    game->inv = create_inv();
    game->p = init_particle();
    game->pse = init_pause();
    game->menu = create_menu();
    game->story = setup_story();
    game->opt = init_option();
    game->ctrl = init_control();

    setup_inventory(game->inv);
    set_status_xp(game->inv, game->characters);
    generate_dialog(game);
}

entity_t *sprite_creator(char *str, int x, int y)
{
    sfVector2f pos = {x, y};
    entity_t *elem = malloc(sizeof(entity_t));

    if (!elem)
        return (NULL);
    elem->s = sfSprite_create();
    elem->t = sfTexture_createFromFile(str, NULL);
    elem->pos = pos;
    sfSprite_setTexture(elem->s, elem->t, sfTrue);
    sfSprite_setPosition(elem->s, pos);
    return (elem);
}

void window_creator(game_t *game)
{
    game->video_mode.width = WIDTH;
    game->video_mode.height = HEIGHT;
    game->video_mode.bitsPerPixel = 32;
    game->state = 0;
    game->view = sfView_create();
    game->win_fight = false;
    sfView_zoom(game->view, 0.5);
    game->player = create_main_player();
    game->player->dest.x = 768;
    game->player->dest.y = 512;
    game->player->is_moving = false;
    game->characters = init_character_tab();
    game->transition = NULL;
    game->scene = NULL;
    game->font = NULL;
    game->state = MENU;
    game->window = sfRenderWindow_create(game->video_mode, \
"my_rpg", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);
}

sfMusic *music_creator(char *str, int vol, sfBool stat)
{
    sfMusic *music;

    music = sfMusic_createFromFile(str);
    sfMusic_setVolume(music, vol);
    sfMusic_setLoop(music, stat);
    return (music);
}

watch_t *time_creator(void)
{
    watch_t *clock = malloc(sizeof(watch_t));
    clock->clock = sfClock_create();

    return (clock);
}