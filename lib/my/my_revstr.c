/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_revstr
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int strlen = my_strlen(str);
    char memory;

    for (int i = 0; i < strlen / 2; i++) {
        memory = *(str + i);
        *(str + i) = *(str + strlen - i - 1);
        *(str + strlen - i - 1) = memory;
    }
    return (str);
}