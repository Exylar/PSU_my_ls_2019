/*
** EPITECH PROJECT, 2019
** file
** File description:
** file
*/

#include <stdlib.h>
#include "../include/my_ls.h"
#include "../include/my.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

void get_size(char *file_name, int *max_size, int *total_size)
{
    struct stat file_stat;
    char *len;

    if (lstat(file_name, &file_stat) != -1) {
        len = my_nbr_to_str(file_stat.st_size);
        *total_size = *total_size + (file_stat.st_blocks / 2);
        if (my_strlen(len) > *max_size)
            *max_size = my_strlen(len);
    }
    free(len);
}

void get_files_infos(char **list_file_path, int size, int *m_size, int *t_size)
{
    for (int i = 0; i < size; i++) {
        get_size(list_file_path[i], m_size, t_size);
    }
    my_putstr("total ");
    my_put_nbr(*t_size);
    my_putstr("\n");
}

char **get_files_with_path(char **name_files, char *pathname, int size)
{
    char **path_files = malloc(sizeof(char *) * (size + 1));
    int i = 0;

    for (i = 0; i < size; i++) {
        path_files[i] = my_strdup(pathname);
        if (my_strcmp(pathname, "./") != 0) {
            path_files[i] = my_realloc(path_files[i], sizeof(char) *
            (my_strlen(path_files[i]) + 1), sizeof(char) *
            (my_strlen(path_files[i]) + 2));
            my_strcat(path_files[i], "/");
        }
        path_files[i] = my_realloc(path_files[i], sizeof(char) *
        (my_strlen(path_files[i]) + 1), sizeof(char) *
        (my_strlen(path_files[i]) + 2));
        my_strcat(path_files[i], name_files[i]);
    }
    path_files[i] = 0;
    return path_files;
}

char **remove_path_file(char **path_files, char *pathname, int size)
{
    char **files = malloc(sizeof(char *) * (size + 1));
    int i = 0;
    char *memory;

    for (i = 0; i < size; i++) {
        memory = my_strdup(path_files[i]);
        my_revstr(memory);
        if (my_strcmp(pathname, "./") == 0)
            memory[my_strlen(memory) - my_strlen(pathname)] = '\0';
        else
            memory[my_strlen(memory) - my_strlen(pathname) - 1] = '\0';
        my_revstr(memory);
        files[i] = my_strdup(memory);
        free(memory);
    }
    files[i] = 0;
    for (int j = 0; j < i; j++)
        free(path_files[j]);
    free(path_files);
    return files;
}

char **get_files(int *i, struct s_my_option *op, char *pathname)
{
    DIR *dir = opendir(pathname);
    struct dirent *dent;
    char **name_files = malloc(sizeof(char *));
    struct stat file;

    while (((dent = readdir(dir)) != NULL)) {
        if ((dent->d_name[0] != '.' && op->dir == 0) ||
        (dent->d_name[0] == '.' && dent->d_name[1] == '\0' &&
        op->dir == 1 || op->hide == 1)) {
            name_files = my_realloc(name_files, sizeof(char *) * (*i + 1),
            sizeof(char *) * (*i + 2));
            name_files[*i] = my_strdup(dent->d_name);
            *i = *i + 1;
        }
    }
    name_files[*i] = 0;
    closedir(dir);
    return name_files;
}