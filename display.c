#include <stdio.h>
#include <SFML/Graphics.h>
#include <time.h>
#include "hunt.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int absolute_value(int nb)
{
    if (nb < 0)
        nb = nb * -1;
    return (nb);
}

char *my_nbr_array(int nb, char *buffer)
{
    if (nb < 0) {
        *buffer = '-';
        buffer++;
        nb = nb * -1;
    }
    if (nb > 9) {
        buffer = my_nbr_array(nb / 10, buffer);
    }
    nb = nb % 10;
    *buffer = nb + 48;
    buffer++;
    *buffer = 0;
    return (buffer);
}

char *my_itoa(int value)
{
    char *buffer;

    buffer = malloc(sizeof(char) * 11);
    my_nbr_array(value, buffer);
    return (buffer);
}

sfText *create_timer(void)
{
    sfFont *font = sfFont_createFromFile("Minecraft.ttf");
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, (sfVector2f){1000, 20});
    return text;
}

void print_clock(parameters_t *parameters, assets_t *assets, positions_t *pos)
{
    sfText_setString(assets->kills, my_itoa(pos->kills));
    sfText_setColor(assets->kills, (sfColor){30, 10, 80, 255});
    sfRenderWindow_drawText(parameters->w, assets->kills, NULL);
}