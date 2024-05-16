/*
** EPITECH PROJECT, 2023
** my hunter
** File description:
** my hunter
*/
#include <stdio.h>
#include <SFML/Graphics.h>
#include <time.h>
#include "hunt.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void events(parameters_t *param, assets_t *assets,
    positions_t *pos, sfIntRect m_rect)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(param->w, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(param->w);
        if (event.type == sfEvtMouseMoved) {
            assets->mir_position.x = event.mouseMove.x;
            assets->mir_position.y = event.mouseMove.y;
            sfSprite_setPosition(assets->sprite_mir, assets->mir_position);
            sfSprite_setTextureRect(assets->sprite_mir, m_rect);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            pos->mouse_x = event.mouseButton.x;
            pos->mouse_y = event.mouseButton.y;
            pos->check_x = pos->mouse_x - assets->bird_position.x;
            pos->check_y = pos->mouse_y - assets->bird_position.y;
        }
    }
}

void destroy(parameters_t *param, assets_t *assets)
{
    sfSprite_destroy(assets->sprite_bg);
    sfTexture_destroy(assets->text_bg);
    sfSprite_destroy(assets->sprite_bird);
    sfTexture_destroy(assets->text_bird);
    sfRenderWindow_destroy(param->w);
}

void draw(parameters_t *param, assets_t *assets, positions_t *pos)
{
    sfRenderWindow_clear(param->w, sfBlack);
    sfRenderWindow_drawSprite(param->w, assets->sprite_bg, NULL);
    sfRenderWindow_drawSprite(param->w, assets->sprite_bird, NULL);
    sfRenderWindow_drawSprite(param->w, assets->sprite_mir, NULL);
    print_clock(param, assets, pos);
    sfRenderWindow_display(param->w);
}

sfIntRect kills(parameters_t *param, assets_t *assets,
    positions_t *pos, sfIntRect rect)
{
    pos->check_x = param->mode.width;
    pos->check_y = param->mode.height;
    assets->bird_position.x += assets->speed;
    if (assets->bird_position.x > param->mode.width) {
        assets->bird_position.x = 0;
        assets->bird_position.y = (rand() % 495 + 1);
    }
    sfSprite_setPosition(assets->sprite_bird, assets->bird_position);
    if (sfTime_asSeconds(sfClock_getElapsedTime(param->clock)) > 0.1f) {
        rect.left += 175;
        if (rect.left >= 700)
            rect.left = 0;
        sfSprite_setTextureRect(assets->sprite_bird, rect);
        sfClock_restart(param->clock);
    }
    return (rect);
}

void game_loop(parameters_t *param, assets_t *assets, positions_t *pos)
{
    sfIntRect rect = {0, 0, 175, 160};
    sfIntRect m_rect = {0, 0, 80, 80};

    sfRenderWindow_setMouseCursorVisible(param->w, sfFalse);
    srand(time(NULL));
    sfSprite_setTextureRect(assets->sprite_bird, rect);
    sfSprite_setTextureRect(assets->sprite_mir, m_rect);
    while (sfRenderWindow_isOpen(param->w)) {
        events(param, assets, pos, m_rect);
        if ((pos->check_x >= 0 && pos->check_x <= 175) &&
            (pos->check_y >= 0 && pos->check_y <= 160)) {
            assets->speed += 0.05f;
            assets->bird_position.x = 0;
            assets->bird_position.y = (rand() % 495 + 1);
            pos->kills = pos->kills + 1;
            my_put_nbr(pos->kills);
            my_putstr(" BIRDS KILLED\n");
        }
        rect = kills(param, assets, pos, rect);
        draw(param, assets, pos);
    }
    destroy(param, assets);
}
