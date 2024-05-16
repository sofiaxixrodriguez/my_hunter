/*
** EPITECH PROJECT, 2023
** display_image.c
** File description:
** displays image
*/
#include <stdio.h>
#include <SFML/Graphics.h>
#include <time.h>
#include "hunt.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int arguments(int ac, char **av)
{
    if (ac > 2 || av[1][0] != '-' || av[1][1] != 'h' || my_strlen(av[1]) > 2) {
        return (84);
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("FOREST HUNT!!\n    Kill as many birds as you can by ");
        my_putstr("clicking on them\n");
        my_putstr("GOOD LUCK!!!\n");
        return (1);
    }
    return (0);
}

void init_parameters(parameters_t *param)
{
    param->clock = sfClock_create();
    param->mode.width = 1080;
    param->mode.height = 655;
    param->mode.bitsPerPixel = 32;
    param->w = sfRenderWindow_create(param->mode, "HUNTER",
                                    sfResize | sfClose, NULL);
}

void init_assets(assets_t *assets)
{
    assets->text_bg = sfTexture_createFromFile("background.jpg", NULL);
    assets->sprite_bg = sfSprite_create();
    assets->text_bird = sfTexture_createFromFile("bird.png", NULL);
    assets->sprite_bird = sfSprite_create();
    assets->bird_position.x = 0;
    assets->bird_position.y = 300;
    assets->speed = 0.1f;
    assets->text_mir = sfTexture_createFromFile("mirilla.png", NULL);
    assets->sprite_mir = sfSprite_create();
    assets->mir_position.x = 0;
    assets->mir_position.y = 0;
    assets->kills = create_timer();
    sfSprite_setTexture(assets->sprite_bg, assets->text_bg, sfTrue);
    sfSprite_setTexture(assets->sprite_bird, assets->text_bird, sfTrue);
    sfSprite_setTexture(assets->sprite_mir, assets->text_mir, sfTrue);
}

void init_positions(positions_t *pos)
{
    pos->check_x = 0;
    pos->check_y = 0;
    pos->kills = -1;
}
