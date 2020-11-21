/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strncat
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int destlen = my_strlen(dest);
    int i = 0;

    for (i = 0; i < nb && src[i] != '\0'; i++)
        dest[destlen + i] = src[i];
    dest[destlen + i] = '\0';
    return dest;
}