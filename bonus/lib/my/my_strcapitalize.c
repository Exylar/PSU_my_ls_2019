/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strcapitalize
*/

char *my_strlowcase(char *str);

int is_alpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? 1 : 0;
}

int is_alphanum(char c)
{
    return is_alpha(c) || (c >= '0' && c <= '9') ? 1 : 0;
}

char *my_strcapitalize(char *str)
{
    str = my_strlowcase(str);
    for (int i = 0; str[i]; i++) {
        if (is_alpha(str[i]) && !is_alphanum(str[i - 1]))
            str[i] = str[i] - 32;
    }
    return str;
}