/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** my_find_prime_sup
*/

int my_is_prime(long long nb);

int my_find_prime_sup(int nb)
{
    if (nb < 0 || nb > 2147483646)
        return 0;
    if (my_is_prime(nb) != 1)
        return my_find_prime_sup(nb + 1);
    return nb;
}