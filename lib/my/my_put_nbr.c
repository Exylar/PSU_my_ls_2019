/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_put_nbr
*/

char my_putchar(char c);

int my_put_nbr(int nb)
{
    int digit = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 0) {
        if (nb >= 10) {
            digit = nb % 10;
            nb = (nb - digit) / 10;
            my_put_nbr(nb);
            my_putchar(48 + digit);
        }
        else
            my_putchar(48 + nb);
    }
    return 0;
}