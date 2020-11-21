/*
** EPITECH PROJECT, 2019
** symlink
** File description:
** symlink
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../include/my_ls.h"
#include "../include/my.h"
#include <unistd.h>
#include <sys/sysmacros.h>
#include <errno.h>
#include <dirent.h>

void display_symlink(char *name_file)
{
    struct stat file;
    char buf[2048];
    ssize_t len;

    lstat(name_file, &file);
    switch (file.st_mode & S_IFMT) {
        case S_IFLNK:
            len = readlink(name_file, buf, sizeof(buf)-1);
            buf[len] = '\0';
            my_putstr(" -> ");
            my_putstr(buf);
    }
}

void display_minor_major(char *name_file, int max_size)
{
    struct stat file;
    char *len;

    lstat(name_file, &file);
    len = my_nbr_to_str(file.st_size);
    switch (file.st_mode & S_IFMT) {
        case S_IFCHR:
            for (int k = 0; k < (max_size - my_strlen(len)); k++)
                my_putstr(" ");
            my_put_nbr(major(file.st_rdev));
            my_putstr(",");
            for (int k = 0; k < (max_size - my_strlen(len)); k++)
                my_putstr(" ");
            my_put_nbr(minor(file.st_rdev));
        default:
            for (int k = 0; k < (max_size - my_strlen(len)); k++)
                my_putstr(" ");
            my_put_nbr(file.st_size);
            break;
    }
    free(len);
}

void display_last_perm(char *name_file)
{
    struct stat file;

    lstat(name_file, &file);
    if ((file.st_mode & S_ISGID) && !(file.st_mode & S_IXGRP))
        my_putstr("S");
    else if ((file.st_mode & S_ISGID) && (file.st_mode & S_IXGRP))
        my_putstr("s");
    else
        file.st_mode & (S_IXUSR) ? my_putstr("x") : my_putstr("-");
    file.st_mode & (S_IROTH) ? my_putstr("r") : my_putstr("-");
    file.st_mode & (S_IWOTH) ? my_putstr("w") : my_putstr("-");
    if (file.st_mode & (S_ISVTX))
        my_putstr("t");
    else if (file.st_mode & (S_IXOTH))
        my_putstr("x");
    else
        my_putstr("-");
}

void check_dir(char **list, int *v, char *argv, struct s_my_option *option)
{
    struct stat file;

    if (errno == EACCES) {
        display_error(argv, 1);
        v[2] = v[2] - 1;
    }
    else if (lstat(argv, &file) != -1) {
        display_file(argv, option);
        v[2] = v[2] + 1;
        v[3] = 1;
    }
    else {
        display_error(argv, 2);
        v[2] = v[2] - 1;
    }
}
