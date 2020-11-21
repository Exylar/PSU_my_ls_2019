/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls
*/

#include <stdlib.h>
#include <sys/stat.h>
#include "../include/my_ls.h"
#include "../include/my.h"

void sort_alpha_swap(char **tab, int size, int i, struct s_my_option *option)
{
    char *memory;
    char arrayi[256];
    char arrayj[256];

    my_strcpy(arrayi, tab[i]);
    my_strcpy(arrayi, my_strlowcase(arrayi));
    for (int j = 0; j < size; j++) {
        my_strcpy(arrayj, tab[j]);
        my_strcpy(arrayj, my_strlowcase(arrayj));
        if (option->rev == 0 && my_strcmp_by_char(arrayi, arrayj) <= 0
        || option->rev == 1 && my_strcmp_by_char(arrayi, arrayj) >= 0) {
            memory = my_strdup(tab[i]);
            tab[i] = my_realloc(tab[i], sizeof(char) + 1 *
            my_strlen(tab[i]), sizeof(char) * my_strlen(tab[j]) + 1);
            my_strcpy(tab[i], tab[j]);
            tab[j] = my_realloc(tab[j], sizeof(char) + 1 *
            my_strlen(tab[j]), sizeof(char) * my_strlen(memory) + 1);
            my_strcpy(tab[j], memory);
            free(memory);
        }
    }
}

void sort_alphabetically(char **tab, int size, struct s_my_option *option)
{
    for (int i = 0; i < size; i++)
        sort_alpha_swap(tab, size, i, option);
}

void sort_time_swap(char **tab, int size, int i)
{
    char *memory;
    struct stat file_stat;

    lstat(tab[i], &file_stat);
    time_t t1 = file_stat.st_mtime;
    for (int j = 0; j < size; j++) {
        lstat(tab[j], &file_stat);
        time_t t2 = file_stat.st_mtime;
        if (t1 > t2) {
            memory = my_strdup(tab[i]);
            tab[i] = my_realloc(tab[i], sizeof(char) + 1 *
            my_strlen(tab[i]), sizeof(char) * my_strlen(tab[j]) + 1);
            my_strcpy(tab[i], tab[j]);
            tab[j] = my_realloc(tab[j], sizeof(char) + 1 *
            my_strlen(tab[j]), sizeof(char) * my_strlen(memory) + 1);
            my_strcpy(tab[j], memory);
            free(memory);
        }
    }
}

void sort_time(char **tab, int size)
{
    for (int i = 0; i < size; i++)
        sort_time_swap(tab, size, i);
}

void simple_ls(struct s_my_option *option, char *pathname)
{
    char **list_file;
    int size = 0;

    list_file = get_files(&size, option, pathname);
    list_file = get_files_with_path(list_file, pathname, size);
    sort_alphabetically(list_file, size, option);
    if (option->time == 1) {
        sort_time(list_file, size);
        sort_time(list_file, size);
    }
    list_file = remove_path_file(list_file, pathname, size);
    if (option->list == 1)
        ls_l(list_file, size, pathname);
    else
        my_show_word_array(list_file);
    for (int i = 0; i < size; i++)
        free(list_file[i]);
    free(list_file);
}