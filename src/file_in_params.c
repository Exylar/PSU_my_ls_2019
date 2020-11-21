/*
** EPITECH PROJECT, 2019
** file_to_params
** File description:
** file_to_params
*/

#include "../include/my.h"
#include "../include/my_ls.h"

void display_file(char *name_file, struct s_my_option *option)
{
    if (option->list == 0) {
        my_putstr(name_file);
        my_putstr("\n");
    }
    else if (option->list == 1) {
        diplay_type_file(name_file);
        display_permission(name_file);
        display_user_groupe_size(name_file, 0);
        my_putstr(" ");
        display_time(name_file);
        my_putstr(name_file);
        display_symlink(name_file);
        my_putstr("\n");
    }
}