/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** my_compute_sqare_root
*/

int cal_square(int n, long long nb)
{
    if (n * n == nb)
        return n;
    if (n * n < nb)
        return cal_square(n + 1, nb);
    return 0;
}

int my_compute_square_root(long long nb)
{
    if (nb > 2147483647 || nb < 0)
        return 0;
    return cal_square(0, nb);
}