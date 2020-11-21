/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_atoi
*/

#include "my.h"

int my_atoi(char *str)
{
    int pow = 1;
    int is_neg = 0;
    long cal = 0;

    str = my_revstr(str);
    if (str[my_strlen(str) - 1] == '-') {
        is_neg = 1;
        str[my_strlen(str) - 1] = '\0';
    }
    for (int i = 0; i < my_strlen(str); i++) {
        if (((str[i] - '0') * pow) < 2147483647) {
            cal += (str[i] - '0') * pow;
            pow *= 10;
        }
    }
    if (is_neg == 1)
        cal *= (-1);
    return cal;
}
