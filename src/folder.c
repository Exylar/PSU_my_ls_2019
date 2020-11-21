/*
** EPITECH PROJECT, 2019
** folder
** File description:
** folder
*/

#include <stdlib.h>
#include "../include/my_ls.h"
#include "../include/my.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

char *get_name_with_path(char *pathname, struct dirent *dent)
{
    char *name;

    name = my_strdup(pathname);
    if (my_strcmp(pathname, "./") != 0) {
        name = my_realloc(name, sizeof(char) *
        (my_strlen(name) + 1), sizeof(char) * (my_strlen(name) + 2));
        my_strcat(name, "/");
    }
    name = my_realloc(name, sizeof(char) * my_strlen(name) + 1,
    sizeof(char) * my_strlen(name) + my_strlen(dent->d_name) + 4);
    my_strcat(name, dent->d_name);
    return name;
}

char *set_dir_list(char *pathname, int *i, struct dirent *dent)
{
    char *name_file;

    if (my_strcmp(pathname, "./") != 0)
        name_file = my_strdup(pathname);
    else
        name_file = my_strdup("./");
    if (my_strcmp(pathname, "./") != 0) {
        name_file = my_realloc(name_file, sizeof(char) *
        my_strlen(name_file) + 1, sizeof(char) * my_strlen(name_file) + 3);
        my_strcat(name_file, "/");
    }
    name_file = my_realloc(name_file, sizeof(char) * my_strlen(name_file) + 1,
    sizeof(char) * my_strlen(name_file) + my_strlen(dent->d_name) + 5);
    my_strcat(name_file, dent->d_name);
    *i = *i + 1;
    return name_file;
}

int check_is_dir(char *name)
{
    struct stat file = {0};

    lstat(name, &file);
    switch (file.st_mode & S_IFMT)
        case S_IFDIR: return 1;
    return 0;
}

char **get_folder(int *i, struct s_my_option *op, char *pathname)
{
    DIR *dir = opendir(pathname);
    struct dirent *dent;
    char **name_files = malloc(sizeof(char *) * 2);
    char *name;

    name_files[*i] = my_strdup(pathname);
    *i = *i + 1;
    if (errno == EACCES) {
        display_error(pathname, 1);
        name_files = 0;
    }
    else {
        while ((dent = readdir(dir)) != NULL) {
            name = get_name_with_path(pathname, dent);
            if ((dent->d_name[0] != '.') && (check_is_dir(name) == 1)) {
                name_files = my_realloc(name_files, 8 * (*i + 1), 8 * (*i + 2));
                name_files[*i] = set_dir_list(pathname, i, dent);
            } free(name);
        } name_files[*i] = 0;
    } closedir(dir);
    return name_files;
}