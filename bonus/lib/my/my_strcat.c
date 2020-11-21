/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_strcat
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int destlen = my_strlen(dest);
    int i = 0;

    for (i = 0; src[i]; i++)
        dest[destlen + i] = src[i];
    dest[destlen + i] = '\0';
    return dest;
}