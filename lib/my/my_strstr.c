/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strstr
*/

#include <stddef.h>

char *search_my_strstr(char *str, char const *to_find, char const *cpy_to_find)
{
    if (*to_find == '\0')
        return str;
    if (*str != '\0') {
        if (*str == *to_find)
            return search_my_strstr(str + 1, to_find + 1, cpy_to_find);
        return search_my_strstr(str + 1, cpy_to_find, cpy_to_find);
    }
    return NULL;
}

char *my_strstr(char *str, char const *to_find)
{
    return search_my_strstr(str, to_find, to_find) != NULL ? str : NULL;
}