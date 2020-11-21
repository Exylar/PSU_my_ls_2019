/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_showstr
*/

#include <unistd.h>

void my_putchar(char c);
int my_putnbr_base(int nbr, char const *base);

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= ' ' && str[i] <= '~')
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            str[i] < 16 ? my_putchar('0') : 1;
            my_putnbr_base(str[i], "0123456789abcdef");
        }
    }
    return 0;
}