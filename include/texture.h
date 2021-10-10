/*
** EPITECH PROJECT, 2019
** texture.h
** File description:
** include texture
*/

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Texture.h>

typedef enum {FIRE, SNOW, CURSOR, HEAL_PAR} effect_t;
typedef enum \
{PLAY, OPTION, CROSS, RESUME, SAVE, VOLUME_DOWN, VOLUME_UP, RETURN, HOW} type_t;

typedef struct pos {
    int x;
    int y;
} pos_t;

typedef struct particle {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    int end;
    sfClock *clock;
    float base_y;
    float base_x;
    float y;
    float x;
    double angle;
    struct particle *next;
    int value;
    effect_t effect;
} particle_t;

typedef struct particle_value {
    sfVector2f pos;
    sfVector2f scale;
    float vel;
    float angle;
    int value;
    effect_t effect;
} particle_value_t;

typedef struct particle_f {
    struct particle *first;
} particle_f;

typedef struct cursor {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    int end;
    sfClock *clock;
    struct cursor *next;
} cursor_t;

typedef struct cursor_f {
    struct cursor *first;
} cursor_f;

typedef struct entity {
    sfSprite *s;
    sfTexture *t;
    sfVector2f pos;
    sfIntRect pos_s;
} entity_t;

typedef struct cell {
    char type;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} cell_t;

typedef struct parallax{
    sfTexture *texture;
    sfSprite *sprite_1;
    sfVector2f pos_1;
    sfVector2f pos_2;
} parallax_t;

typedef struct text {
    sfVector2f pos;
    sfText *str;
    sfFont *font;
} text_t;

typedef struct watch {
    sfClock *clock;
    sfTime time;
    float seconds;
} watch_t;

#endif /* !TEXTURE_H_ */
