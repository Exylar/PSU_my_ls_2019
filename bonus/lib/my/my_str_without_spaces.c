/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_2019
** File description:
** my_str_without_spaces
*/

#include <stdlib.h>
int my_strlen(char const *str);

char *my_str_without_spaces(char const *str)
{
    char *new_str;
    int cpt = 0;

    new_str = malloc(sizeof(char) * my_strlen(str) + 1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            new_str[cpt] = str[i];
            cpt++;
        }
    }
    new_str[cpt] = '\0';
    return new_str;
}