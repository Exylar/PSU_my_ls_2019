/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_isneg
*/

char my_putchar(char c);

int my_isneg(int nb)
{
    if (nb < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return 0;
}