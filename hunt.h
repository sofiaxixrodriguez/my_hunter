/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** header file containing functions exposed in libmy.a
*/

#ifndef MY_HUNT_
    #define MY_HUNT_

    #include <stdio.h>
    #include <SFML/Graphics.h>
    #include <time.h>

typedef struct parameters {
    sfRenderWindow* w;
    sfVideoMode mode;
    sfClock* clock;
} parameters_t;

typedef struct assets {
    sfTexture* text_bg;
    sfSprite* sprite_bg;
    sfTexture* text_bird;
    sfSprite* sprite_bird;
    sfVector2f bird_position;
    float speed;
    sfTexture* text_mir;
    sfSprite* sprite_mir;
    sfVector2f mir_position;
    sfText* kills;

} assets_t;

typedef struct positions {
    int mouse_x;
    int mouse_y;
    int check_x;
    int check_y;
    int kills;

} positions_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_numlen(int a);
int arguments(int ac, char **av);
void init_parameters(parameters_t *param);
void init_assets(assets_t *assets);
void init_positions(positions_t *pos);
void events(parameters_t *param, assets_t *assets,
    positions_t *pos, sfIntRect m_rect);
void destroy(parameters_t *param, assets_t *assets);
void draw(parameters_t *param, assets_t *assets, positions_t *pos);
sfIntRect kills(parameters_t *param, assets_t *assets,
    positions_t *pos, sfIntRect rect);
void game_loop(parameters_t *param, assets_t *assets, positions_t *pos);


#endif
