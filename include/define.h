/*
** EPITECH PROJECT, 2019
** define.h
** File description:
** all definer for my_world project
*/

#ifndef DEFINE_H_
#define DEFINE_H_

#define USAGE "USAGE\n     ./rpg\n\
DESCRIPTION\n     third person RPG.\n"

#define BAD_ARGS "Bad arguments:\
\n     Retry with -h.\n"

#define SUCCESS 0
#define ERROR 84
#define HEIGHT 800
#define WIDTH 960

#define MAX_INT 2147483647
#define MIN_INT -2147483648

#define B_IDLE 0
#define B_OVER 1
#define B_CLICK 2
#define B_TOGGLE 4

#define PATH_NEXT_B "assets/buttons/next.png"
#define POS_NEXT_B fill_vector_2f(850, 750)
#define SIZE_NEXT_B fill_intrect(5, 0, 19, 56)

#define PATH_PLAY_B "assets/buttons/play.png"
#define POS_PLAY_B fill_vector_2f(150, 450)
#define SIZE_PLAY_B fill_intrect(5, 5, 61, 284)

#define PATH_NEW_B "assets/buttons/new.png"
#define POS_NEW_B fill_vector_2f(150, 450)
#define SIZE_NEW_B fill_intrect(5, 5, 61, 284)

#define PATH_LOAD_B "assets/buttons/load.png"
#define POS_LOAD_B fill_vector_2f(450, 450)
#define SIZE_LOAD_B fill_intrect(5, 5, 61, 284)

#define PATH_OPTION_B "assets/buttons/option.png"
#define POS_OPTION_B fill_vector_2f(450, 450)
#define SIZE_OPTION_B fill_intrect(5, 5, 61, 284)

#define PATH_RESUME_B "assets/buttons/resume.png"
#define POS_RESUME_B fill_vector_2f(150, 450)
#define SIZE_RESUME_B fill_intrect(5, 5, 61, 284)

#define PATH_SAVE_B "assets/buttons/save.png"
#define POS_SAVE_B fill_vector_2f(450, 450)
#define SIZE_SAVE_B fill_intrect(5, 5, 61, 284)

#define PATH_CROSS_B "assets/buttons/cross.png"
#define POS_CROSS_B fill_vector_2f(870, 10)
#define SIZE_CROSS_B fill_intrect(5, 5, 61, 75)

#define PATH_UP_B "assets/buttons/up.png"
#define POS_UP_B fill_vector_2f(450, 450)
#define SIZE_UP_B fill_intrect(5, 5, 61, 75)

#define PATH_DOWN_B "assets/buttons/down.png"
#define POS_DOWN_B fill_vector_2f(300, 450)
#define SIZE_DOWN_B fill_intrect(5, 5, 61, 75)

#define PATH_RETURN_MENU_B "assets/buttons/return.png"
#define POS_RETURN_MENU_B fill_vector_2f(10, 10)
#define SIZE_RETURN_MENU_B fill_intrect(5, 5, 61, 75)

#define PATH_HOW_B "assets/buttons/howtoplay.png"
#define POS_HOW_B fill_vector_2f(710, 730)
#define SIZE_HOW_B fill_intrect(5, 5, 29, 210)

#define PATH_CTRL "assets/buttons/control.png"

#define POS_TC_ARROW fill_vector_2i(500, 100)
#define POS_C_ARROW fill_vector_2f(300, 100)
#define SIZE_C_ARROW fill_intrect(0, 0, 38, 158)
#define POS_TC_E fill_vector_2i(500, 200)
#define POS_C_E fill_vector_2f(420, 200)
#define SIZE_C_E fill_intrect(38, 0, 38, 30)
#define POS_TC_I fill_vector_2i(500, 300)
#define POS_C_I fill_vector_2f(420, 300)
#define SIZE_C_I fill_intrect(38, 30, 38, 33)
#define POS_TC_Q fill_vector_2i(500, 400)
#define POS_C_Q fill_vector_2f(420, 400)
#define SIZE_C_Q fill_intrect(38, 62, 38, 37)
#define POS_TC_MOUSE fill_vector_2i(500, 500)
#define POS_C_MOUSE fill_vector_2f(420, 500)
#define SIZE_C_MOUSE fill_intrect(38, 98, 38, 30)

#define PATH_FIRE_C "assets/cursor/fire.png"
#define PATH_WATER_C "assets/cursor/water.png"
#define PATH_ELECTRIC_C "assets/cursor/electric.png"
#define CURSOR_RECT fill_intrect(1, 1, 187, 187)
#define MIDDLE_SPRITE 94

#include <SFML/Graphics/Sprite.h>

#define PATH_ATTACK_B "assets/buttons/button_attack.png"
#define SIZE_S_ATTACK_B fill_intrect(5, 5, 80, 260)
#define POS_ATTACK_B fill_vector_2f(45, 585)

#define PATH_DEFEND_B "assets/buttons/button_defend.png"
#define SIZE_S_DEFEND_B fill_intrect(5, 5, 80, 260)
#define POS_DEFEND_B fill_vector_2f(335, 585)

#define PATH_FLEE_B "assets/buttons/button_flee.png"
#define SIZE_S_FLEE_B fill_intrect(5, 5, 80, 260)
#define POS_FLEE_B fill_vector_2f(45, 675)

#define PATH_OBJECT_B "assets/buttons/button_object.png"
#define SIZE_S_OBJECT_B fill_intrect(5, 5, 80, 260)
#define POS_OBJECT_B fill_vector_2f(335, 675)

#define PATH_RETURN_B "assets/buttons/button_return.png"
#define SIZE_S_RETURN_B fill_intrect(5, 5, 80, 260)
#define POS_RETURN_B fill_vector_2f(335, 675)

#define HUD_FIGHT "assets/hud/hud_fight.png"
#define POS_HUD_FIGHT fill_vector_2f(0, 540);

#define BACK_FIGHT "assets/fight/background.png"
#define POS_BACK fill_vector_2f(0, 0);

#define PATH_PIXEL_F "assets/font/pixel.ttf"

#define PATH_FIRE_C "assets/cursor/fire.png"
#define PATH_WATER_C "assets/cursor/water.png"
#define PATH_ELECTRIC_C "assets/cursor/electric.png"
#define CURSOR_RECT fill_intrect(1, 1, 187, 187)
#define MIDDLE_SPRITE 94

#define PATH_PARTICLE "assets/particles/particles.png"
#define SIZE_PARTICLE fill_intrect(0, 396, 132, 132)
#define MIDDLE_PARTICLE 66

#define MOUSE(window) \
fill_vector_2f(sfMouse_getPositionRenderWindow(window).x, \
sfMouse_getPositionRenderWindow(window).y)

#define FIRE_VALUE(x, y) init_fire_value(x, y)
#define SNOW_VALUE init_snow_value()
#define CURSOR_VALUE(x, y) init_cursor_value(x, y)
#define HEAL_VALUE(x, y) init_heal_value(x, y)

#define PATH_INV "assets/hud/inventory.png"
#define POS_INV fill_vector_2f(WIDTH / 2, (HEIGHT / 2) - 30)
#define SIZE_INV fill_intrect(0, 0, 349, 415)
#define CENTER_INV fill_vector_2f(158, 96)

#define PATH_POINT "assets/hud/pointer.png"
#define POS_POINT fill_vector_2f(200, 300)
#define SIZE_POINT fill_intrect(3, 8, 10, 10)

#define PATH_INFO "assets/hud/infobox.png"
#define POS_INFO fill_vector_2f(0, 0)
#define SIZE_INFO fill_intrect(52, 2, 25, 21)
#define SIZE_LAYER_INFO fill_intrect(53, 25, 7, 19)
#define INFO_RECT(x, y) fill_addr_intrect(y + 5, x + 5, 35, 90)
#define USE_RECT(x, y) fill_addr_intrect(y + 45, x + 5, 35, 90)
#define MOVE_RECT(x, y) fill_addr_intrect(y + 85, x + 5, 35, 90)

#define PATH_ITEM "assets/objects/items.png"

#define NONE_ITEM init_obj_value("None", \
"Not an item", \
fill_intrect(0, 0, 0, 0))
#define HEAL_POTION init_obj_value("Health potion", \
"A small vial of potion of life, giving 20LP", \
fill_intrect(0, 64, 16, 16))
#define MANA_POTION init_obj_value("Mana potion", \
"A small vial of potion of mana, giving 20MP", \
fill_intrect(0, 48, 16, 16))
#define KEY init_obj_value("Gold key", \
"An old and rusty gold key, probably used on a door", \
fill_intrect(16, 64, 16, 16))
#define GOLD init_obj_value("Gold coin", \
"1 gold coin = 100 silver coins", \
fill_intrect(96, 32, 16, 16))
#define SILVER init_obj_value("Silver coin", \
"1 silver coin = 100 copper coins", \
fill_intrect(96, 16, 16, 16))
#define COPPER init_obj_value("Copper coin", \
"One copper coin", \
fill_intrect(80, 48, 16, 16))
#define RING init_obj_value("Silver ring", \
"a great wedding ring", \
fill_intrect(16, 112, 16, 16))
#define BOW init_obj_value("Bow of the ancient", \
"a 100-year-old arc, but robust like steel", \
fill_intrect(48, 64, 16, 16))
#define SWORD init_obj_value("Iron sword", \
"A simple iron sword capable of pruning a lizard", \
fill_intrect(32, 32, 16, 16))
#define SHIELD init_obj_value("Sacred shield", \
"a sacred shield found during the Crusade of Kirvarun", \
fill_intrect(48, 0, 16, 16))
#define STAFF init_obj_value("Magic stick", \
"a stick impregnated with a strange power", \
fill_intrect(32, 48, 16, 16))
#define BAD_BOOK init_obj_value("Grimoire of death", \
"a strange book with a skull engraved on the cover", \
fill_intrect(32, 64, 16, 16))
#define GIFT init_obj_value("Gift", \
"A gift from the village", \
fill_intrect(80, 64, 16, 16))

sfVector2f fill_vector_2f(float x, float y);
sfVector2i fill_vector_2i(int x, int y);
sfIntRect fill_intrect(int top, int left, int height, int width);
sfIntRect *fill_addr_intrect(int top, int left, int height, int width);

#endif /* !DEFINE_H_ */
