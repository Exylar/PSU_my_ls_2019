/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_putnbr_base
*/

char my_putchar(char c);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int p);

int my_putnbr_base(int nbr, char const *base)
{
    int len_base = my_strlen(base);

    if (nbr < 0) {
        my_putchar('-');
        nbr = -nbr;
    }
    if (nbr == 0)
        return 0;
    else
        my_putnbr_base(nbr / len_base, base);
    my_putchar(base[nbr % len_base]);
    return 0;
}