/*
** EPITECH PROJECT, 2019
** my_int_to_str
** File description:
** my_int_to_str
*/

#include "stdlib.h"
char *my_revstr(char *str);

char *my_nbr_to_str(int nb)
{
    char *str;
    int i = 0;
    int is_neg = 0;

    str = malloc(sizeof(char) * 12);
    nb < 0 ? is_neg = 1 : 0;
    nb < 0 ? nb = -nb : nb;
    while (nb >= 10) {
        str[i] = '0' + (nb % 10);
        nb = (nb - (nb % 10)) / 10;
        i++;
    }
    str[i] = '0' + (nb % 10);
    if (is_neg == 1) {
        i++;
        str[i] = '-';
    }
    str[i + 1] = '\0';
    return my_revstr(str);
}