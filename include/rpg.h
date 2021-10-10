/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** RPG
*/

/*
** START
*/

#ifndef RPG_H
#define RPG_H

/*
** INCLUDE
*/

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Graphics/ConvexShape.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Config.h>
#include <SFML/Audio/Music.h>
#include <SFML/Graphics/VertexArray.h>
#include <SFML/Graphics/View.h>
#include <stdio.h>
#include <math.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include "define.h"
#include "texture.h"

/*
** STRUCT
*/

struct game;
typedef struct character character_t;
typedef struct fight_t fight_t;

typedef enum \
{MENU, INVENTORY, GAME, OPTIONS, PAUSE, FIGHT, DIALOG, HOW_TO_PLAY} state_t;
typedef enum {UP, DOWN, RIGHT, LEFT} dir_t;
typedef enum {POTION_TYPE, SWORD_TYPE} obj_t;
typedef enum {NONE, STOP, INFO, MOVE} inv_state_t;
typedef enum {MELEE, SPELL, HEAL} type_e;
typedef enum {TALK, BATTLE, GET} quest_t;

typedef struct stats {
    int hp_max;
    int hp;
    int mp_max;
    int mp;
    int atk;
    int def;
    int atk_mag;
    int def_mag;
    int crit;
    int speed;
    int exp;
    int level;
} stats_t;

typedef struct button {
    type_t type;
    entity_t *e;
    sfIntRect surf;
    int state;
    void (*action_b)(struct game *);
    void (*action_volume)(struct game *, bool);
} button_t;

typedef struct element {
    entity_t *e;
    button_t *button;
    struct element *next;
} element_t;

typedef struct list {
    struct element *first;
} list_t;

typedef struct menu {
    button_t **main;
    button_t **save;
    parallax_t **parallax;
    bool selection;
} menu_t;

typedef struct pause {
    button_t **button;
} pause_t;

typedef struct attack_t {
    char *name;
    void (*button_funct)(struct game *);
    type_e type;
} attack_t;

typedef struct character {
    entity_t *e;
    entity_t *icon;
    char *name;
    bool enemy;
    stats_t *stats;
    sfRectangleShape *healthbar;
    sfRectangleShape *healthbackground;
    attack_t **attack;
    int played;
} character_t;

typedef struct action_t {
    button_t **button;
    sfText **button_text;
} action_t;

typedef struct fight_t {
    character_t *to_play;
    void (*animation)(struct game *);
    void (*to_do)(struct game *);
    void (*anim)(struct game *, int *);
    character_t *target;
    sfText *damage;
    sfText *wrong_target;
    entity_t *arrow;
    watch_t *clock;
} fight_t;

typedef struct option {
    button_t **button;
} option_t;

typedef struct scene {
    entity_t *bckgrnd;
    entity_t *front;
    entity_t **characters;
    text_t **dialogues;
    button_t **choices;
    action_t **action;
    fight_t *info_fight;
    int state;
} scene_t;

typedef struct player {
    entity_t *player;
    sfVector2f dest;
    bool is_moving;
    dir_t dir;
} player_t;

typedef struct dialog {
    entity_t *text_bar;
    button_t *next;
    int status_read;
} dialog_t;

typedef struct transition {
    sfRectangleShape *fading;
    watch_t *clock;
    bool end;
} transition_t;

typedef struct infobox {
    entity_t *infobox;
    entity_t *layer;
    bool visible;
} infobox_t;

typedef struct object {
    entity_t *obj;
    obj_t type;
    sfText *name;
    sfText *detail;
    sfIntRect hitbox;
} object_t;

typedef struct obj_value {
    char *name;
    char *detail;
    sfIntRect rect;
} obj_value_t;

typedef struct inventory {
    entity_t *hud;
    object_t obj[4][8];
    entity_t *pointer;
    infobox_t *info;
    inv_state_t state;
    text_t **stats_xp;
} inventory_t;

typedef struct control {
    entity_t *e;
    text_t *text;
} control_t;

typedef struct pnj {
    cell_t *info;
    sfIntRect pos_s;
    sfVector2f dest;
    bool is_moving;
    text_t **text;
    bool display;
    dir_t dir;
    void (*goal)(struct game *, obj_value_t object);
    obj_value_t object;
} pnj_t;

typedef struct ctrl_value {
    sfVector2f pos;
    sfVector2i t_pos;
    sfIntRect rect;
    char *text;
} ctrl_value_t;

typedef struct story {
    text_t **infos;
    quest_t goal;
    int count_id;
    obj_value_t object;
} story_t;

typedef struct game {
    cell_t ***map;
    cell_t **decor;
    pnj_t **villagers;
    story_t **story;
    sfView *view;
    player_t *player;
    dialog_t *dialog;
    inventory_t *inv;
    menu_t *menu;
    state_t state;
    bool win_fight;
    sfFont **font;
    transition_t *transition;
    sfRenderWindow *window;
    sfVideoMode video_mode;
    scene_t *scene;
    character_t **characters;
    character_t **enemies;
    sfMusic **music;
    cursor_f *c;
    particle_f *p;
    option_t *opt;
    pause_t *pse;
    control_t **ctrl;
} game_t;

/*
** PROTOTYPE
*/

int gaming(game_t *game);
void window_creator(game_t *game);
sfMusic *music_creator(char *str, int vol, sfBool stat);
watch_t *time_creator(void);
cell_t ***get_map(char *filepath);
int click_events(game_t *game);
void zoom_screen(game_t *game, sfEvent event);
int click_button(sfVector2i mouse, game_t *game);
sfView *view_creator(float left, float top, float width, float heigh);
void target_player(game_t *game);
void move_player(game_t *game);
void adjust_player_position_x(player_t *player);
void adjust_villager_position_x(pnj_t *villager);
void start_battle(game_t *game);
cell_t *create_ground_cell(sfTexture *texture, int x, int y, char type);
cell_t **get_decor(char *filepath);
entity_t *sprite_creator(char *str, int x, int y);
player_t *create_main_player(void);
void change_sprite_horizontale(sfIntRect *rect, int offset, int max_value);
void set_sprite_vertical(sfIntRect *rect, int value);
void connect_texture(cell_t ***map);
void get_connection_oppos(cell_t ***map, int x, int y, sfTexture *texture[5]);
int get_nb_line(char *filepath);
char **str_to_array(char *str, char c);
button_t *create_button(char *path, void(*action_b), type_t type);
void draw_button_game(game_t *game, button_t *but);
void draw_button_menu(game_t *game, button_t *but);
entity_t *sprite_creator(char *str, int x, int y);
void set_button_attribute(button_t *b, sfVector2f pos, sfIntRect size_s);
menu_t *create_menu(void);
void destroy_menu(menu_t *menu);
cursor_f *init_cursor(void);
sfTexture **get_texture_list(char *filepath);
cell_t *get_texture_decor(char *buffer, cell_t *cell, \
sfTexture **texture, char type);
pnj_t **get_villagers(char *filepath);
bool collide_decor(game_t *game, sfVector2f dest);
void move_villagers(game_t *game, pnj_t *villager);
int find_cell(cell_t **line, sfVector2f dest);
text_t *text_creator(char *str, char *path, sfVector2i pos, int size);
void setup_quest(pnj_t *pnj, int nb_dialog);
void create_quest(pnj_t *pnj, char *message);
bool talk_to_pnj(state_t *state, pnj_t **pnj, \
sfVector2f player_pos, dir_t player_dir);
void sorter(sfTexture **stock, int *texture_name, int nb);
void anime_world(game_t *game, watch_t *clock, watch_t *clock_player);
int count_textures(char *filepath);
char *complete_file(char *filepath, char *name);
void display_villagers(game_t *game, int status);
void display_menu(game_t *game);
entity_t *sprite_creator(char *str, int x, int y);
entity_t *sprite_creator(char *str, int x, int y);
char *fill_name(char *str);
void load_action_button(game_t *game);
void display_hud(action_t *action, game_t *game);
sfRectangleShape *init_rectangleshape(int type, int posx, int posy);
void manage_fight(game_t *game);
void my_memeset(button_t **button, sfText **text, int size);
sfText *load_text(const char *buffer, game_t *game, sfVector2f to_set);
void display_inventory(game_t *game, inventory_t *inv);
sfVector2f get_pos_text(int i);
void cursor(game_t *game, int x, int y, int choice);
void display_cursor(game_t *game);
particle_f *init_particle(void);
void particle(game_t *game, particle_t *particle);
void display_particle(game_t *game);
particle_t *create_fire_particle(particle_value_t val);
void fire_particle(particle_t *par);
void snow_particle(particle_t *par);
particle_value_t init_fire_value(float x, float y);
particle_value_t init_snow_value(void);
int fire_effect(game_t *game, float x, float y);
int snow_effect(game_t *game);
int cursor_effect(game_t *game);
void cursor_particle(particle_t *par);
particle_value_t init_cursor_value(float x, float y);
particle_t *create_particle(particle_value_t val);
char *int_to_str(int nb);
void destroy_player(game_t *game);
void destroy_fight(scene_t *scene);
void load_attack_button(game_t *game);
void load_action_text(action_t *action, game_t *game);
void load_target_button(game_t *game);
void load_attack_text(game_t *game);
void music_manager(game_t *game);
void create_music_tab(game_t *game);
void destroy_music_tab(game_t *game);
void display_dynamic(game_t *game);
void set_character_dir(dir_t *dir, int value, char type);
void set_character_position(sfSprite *sprite, sfIntRect *rect, dir_t dir);
dialog_t *create_dialog(void);
void load_heal_button(game_t *game);
transition_t *create_transition(transition_t *transition);
void display_transition(sfRenderWindow *window, transition_t *transition);
inventory_t *create_inv(void);
void check_inv(inventory_t *inv, game_t *game);
void destroy_inv(inventory_t *inv);
void add_new_object(obj_value_t type, sfVector2i place, inventory_t *inv);
obj_value_t init_obj_value(char *name, char *detail, sfIntRect rect);
int info(inventory_t *inv, game_t *game, int x, int y);
int use(inventory_t *inv, game_t *game, int x, int y);
int move(inventory_t *inv, game_t *game, int x, int y);
int browse_infobox(inventory_t *inv, sfVector2i mouse);
entity_t *create_entity(char *path, sfVector2f pos, sfIntRect rect);
bool is_file_valid(char *filepath, char *valid_char, int nb_separation);
int my_strcmp(char const *str1, char const *str2);
void load_save(game_t *game);
void write_save(game_t *game);
void begin_game(game_t *game);
void generate_dialog(game_t *game);
void setup_inventory(inventory_t *inv);
sfVector2i find_place_in_inv(inventory_t *inv);
void attribute_goal_give(game_t *game, obj_value_t object);
bool is_all_heroes_dead(game_t *game);
void game_over(game_t *game);
parallax_t **create_parallax(void);
void display_parallax(sfRenderWindow *window, parallax_t **para);
void end_combat(game_t *game);
void close_game(game_t *game);
pause_t *init_pause(void);
void display_pause(game_t *game);
story_t **setup_story(void);
void display_story(game_t *game);
story_t **next_quest(story_t **story);
void update_quest(game_t *game);
void display_volume_menu(game_t *game);
void change_current_music_volume(game_t *game, bool volume);
button_t *create_volume_button(char *path, void(*action_volume), type_t type);
option_t *init_option(void);
void display_option(game_t *game);
void return_menu(game_t *game);
void set_status_xp(inventory_t *inv, character_t **characters);
particle_value_t init_heal_value(float x, float y);
int heal_effect(game_t *game, float x, float y);
void heal_particle(particle_t *par);
void display_ctrl(game_t *game);
control_t **init_control(void);
void game_state(game_t *game);
void game_fight(game_t *game);
void game_dialog(game_t *game);
void key_events(game_t *game);
void game_preparation(game_t *game);
bool prepare_assets(game_t *game);
void start_selection(game_t *game);
void start_options(game_t *game);
int load_fight_element(game_t *game);
int count_item_in_inv(inventory_t *inv, obj_value_t object);
void add_goal(pnj_t *pnj, obj_value_t object, char type);
story_t *setup_quest_talk(char *name, char *desc, int id_villager);
story_t *setup_quest_fight(char *name, char *desc, int nb_enemies);
story_t *setup_quest_get(char *name, char *desc, \
obj_value_t object, int nb_item);
void check_life(game_t *game);
void deal_heal(game_t *game);

#endif

/*
** END
*/