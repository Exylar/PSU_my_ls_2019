/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** my_str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int is_an(char c)
{
    int is_num = 0;
    int is_alpha = 0;

    if (c >= '0' && c <= '9')
        is_num = 1;
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        is_alpha = 1;
    if (is_alpha == 1 || is_num == 1)
        return 1;
    return 0;
}

void alloc_memory_word_array(char const *str, int *count_return)
{
    int is_no_alpha = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_an(str[i]) == 0 && is_no_alpha == 0 && is_an(str[i + 1]) == 1) {
            *count_return = *count_return + 1;
            is_no_alpha = 1;
        }
        else
            is_no_alpha = 0;
    }
    if (is_an(str[0]) == 1 || is_an(str[0]) == 0)
        *count_return = *count_return + 1;
    if (is_an(str[1]) == 0)
        *count_return = *count_return - 1;
}

char **assign_word_array(char const *str, char *str_c, int *v)
{
    char **str_array = malloc(sizeof(char *));
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_an(str[i]) == 1) {
            str_c[v[0]] = str[i];
            v[0]++;
            v[2] = 0;
        }
        if ((v[2] == 0) && (is_an(str[i]) == 0 || str[i + 1] == '\0')) {
            str_c[v[0]] = '\0';
            str_array = my_realloc(str_array, sizeof(char *) *
            v[1], sizeof(char *) * (v[1] + 2));
            str_array[v[1]] = my_strdup(str_c);
            v[1]++;
            v[0] = 0;
            v[2] = 1;
        }
    }
    str_c[v[0]] = '\0';
    str_array[v[1]] = 0;
    return str_array;
}

char **my_str_to_word_array(char const *str)
{
    char **str_array;
    char str_cp[100];
    int count_return = 0;
    int v[4] = {0, 0, 1};

    alloc_memory_word_array(str, &count_return);
    str_array = assign_word_array(str, str_cp, v);
    return str_array;
}