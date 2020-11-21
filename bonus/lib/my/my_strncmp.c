/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    return s1[n - 1] != s2[n - 1] ? s1[n - 1] - s2[n - 1] : 0;
}