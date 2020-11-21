/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** my_is_prime
*/

int cal_is_prime(int n, long long nb)
{
    if (nb <= 1)
        return 0;
    if (nb % n == 0)
        return 0;
    if (n < nb - 1)
        return cal_is_prime(n + 1, nb);
    return 1;
}

int my_is_prime(long long nb)
{
    if (nb > 2147483647 || nb < 0)
        return 0;
    return cal_is_prime(2, nb);
}