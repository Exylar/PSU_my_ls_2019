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


void rec_ls(struct s_my_option *option, char *pathname)
{
    char **list_folder;
    int size = 0;

    list_folder = get_folder(&size, option, pathname);
    if (list_folder != 0) {
        my_putstr(list_folder[0]);
        sort_alphabetically(list_folder, size, option);
        my_putstr(":\n");
        simple_ls(option, list_folder[0]);
        for (int i = 1; i < size; i++) {
            my_putstr("\n");
            rec_call(option, list_folder[i]);
        }
        for (int k = 0; k < size; k++)
            free(list_folder[k]);
    }
    free(list_folder);
}

void rec_call(struct s_my_option *option, char *folder)
{
    if (folder != 0)
        rec_ls(option, folder);
}