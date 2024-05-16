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

int main(int ac, char **av)
{
    parameters_t *param = malloc(sizeof(parameters_t));
    assets_t *assets = malloc(sizeof(assets_t));
    positions_t *pos = malloc(sizeof(positions_t));

    init_parameters(param);
    init_assets(assets);
    init_positions(pos);
    if (ac != 1) {
        return (arguments(ac, av));
    }
    game_loop(param, assets, pos);
    return (0);
}
