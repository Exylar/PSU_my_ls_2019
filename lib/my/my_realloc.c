/*
** EPITECH PROJECT, 2019
** my_realloc
** File description:
** my_realloc
*/

#include <stdlib.h>
#include <stddef.h>


char *my_strcpy(char *dest, char const *src);

void *my_realloc(void *str, size_t old_size, size_t new_size)
{
    int i = 0;
    void *new_str = NULL;

    new_str = malloc(sizeof(void *) * new_size);
    for (int i = 0; i < old_size; i++)
        ((char *)new_str)[i] = ((char *)str)[i];
    free(str);
    return new_str;
}