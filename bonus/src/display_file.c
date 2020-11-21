/*
** EPITECH PROJECT, 2019
** display_file
** File description:
** display_file
*/

#include <stdlib.h>
#include <sys/stat.h>
#include "../include/my_ls.h"
#include "../include/my.h"

void display_file_style(char *name, char *path_file)
{
    struct stat file_stat;

    if (lstat(path_file, &file_stat) != -1) {
        if (file_stat.st_mode & (S_IXUSR))
            my_putstr("\E[1m\e[32m");
        switch (file_stat.st_mode & S_IFMT) {
            case S_IFDIR:
                my_putstr("\e[1;34m");
                my_putstr(name);
                break;
            case S_IFLNK:
                my_putstr("\e[1;36m");
                my_putstr(name);
                break;
            case S_IFREG:
                my_putstr(name);
                break;
        }
        my_putstr("\e[0m\e[39m");
    }
    my_putstr("  ");
}

void display_files(char **name_files, char **path_files, int size, int a)
{
    struct stat file_stat;

    for (int j = 0; j < size; j++) {
        lstat(path_files[j], &file_stat);
        if (name_files[j][0] != '.' || a == 1)
            display_file_style(name_files[j], path_files[j]);
    }
    my_putstr("\n");
}