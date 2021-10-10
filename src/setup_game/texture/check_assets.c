/*
** EPITECH PROJECT, 2019
** check_assets.c
** File description:
** check if there is no erros in the asssets
*/

#include "rpg.h"

bool is_map_rectangular(char *filepath)
{
    int len = 0;
    int old_len = 0;
    char *buffer = NULL;
    size_t size = 0;
    FILE *fd = fopen(filepath, "r");

    if (!fd)
        return (false);
    len = getline(&buffer, &size, fd);
    old_len = len;
    while ((len = getline(&buffer, &size, fd)) > 0) {
        if (len != old_len) {
            fclose(fd);
            return (false);
        } else
            old_len = len;
    }
    fclose(fd);
    return (true);
}

bool check_files(void)
{
    if (is_file_valid("maps/map_dry.txt", "012", 0) == false || \
    is_map_rectangular("maps/map_dry.txt") == false) {
        write(2, "Error: Invalid map file\n", 24);
        return (false);
    }
    if (is_file_valid("maps/decor.txt", ":-0123456789", 6) == false) {
        write(2, "Error: Invalid decor file\n", 26);
        return (false);
    }
    if (is_file_valid("maps/villagers.txt", ":-0123456789", 6) == false) {
        write(2, "Error: Invalid villagers file\n", 30);
        return (false);
    }
    return (true);
}

bool prepare_assets(game_t *game)
{
    if (check_files() == false)
        return (false);
    game->map = get_map("maps/map_dry.txt");
    game->decor = get_decor("maps/decor.txt");
    game->villagers = get_villagers("maps/villagers.txt");
    if (!game->map || !game->decor || !game->villagers) {
        write(2, "Error: malloc\n", 14);
        return (false);
    }
    game->dialog = create_dialog();
    create_music_tab(game);
    if (!game->dialog || !game->music) {
        write(2, "Error: malloc\n", 14);
        return (false);
    }
    return (true);
}