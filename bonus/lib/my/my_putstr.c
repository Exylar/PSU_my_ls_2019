/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_putstr
*/

#include <unistd.h>
int my_strlen(char const *str);

int my_putstr(char const *str)
{
    int size = my_strlen(str);

    write(1, str, size);
    return 0;
}