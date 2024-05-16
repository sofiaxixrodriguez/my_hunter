/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** lib
*/

#include <unistd.h>
#include "hunt.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;
    int a;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    a = my_strlen(str);
    return (a);
}

int my_strlen(char const *str)
{
    int i = 0 ;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_put_nbr(int nb)
{
    int a;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    a = my_numlen(nb);
    return (a);
}

int my_numlen(int a)
{
    int i = 0;

    while (a != 0) {
        a = a / 10;
        i++;
    }
    return (i);
}
