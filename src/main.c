/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** main
*/

#include "../include/my.h"
#include "../include/my_ls.h"
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>


void display_error(char *argv, int n_error)
{
    if (n_error == 1) {
        my_putstr("my_ls: cannot open directory '");
        my_putstr(argv);
        my_putstr("': Permission denied\n");
    }
    else if (n_error == 2) {
        my_putstr("my_ls: cannot access '");
        my_putstr(argv);
        my_putstr("': No such file or directory\n");
    }
}

void set_list(char **list, int *v, char *argv, struct s_my_option *option)
{
    DIR *dir = opendir(argv);

    if (dir == 0) {
        check_dir(list, v, argv, option);
    }
    else {
        list[v[1]] = my_strdup(argv);
        v[1] = v[1] + 1;
        v[2] = v[2] + 1;
    }
    closedir(dir);
}

char **get_directory_option(int *v, char **argv, struct s_my_option *option)
{
    char **list_folder = malloc(sizeof(char *));

    for (int i = 1; i < v[0]; i++) {
        if ((argv[i][0] != '-') || (argv[i][0] == '-' && argv[i][1] == '\0')) {
            list_folder = my_realloc(list_folder, sizeof(char *) *
            v[1], sizeof(char *) * (v[1] + 1));
            set_list(list_folder, v, argv[i], option);
        }
    }
    if (v[1] == 0 && v[2] == 0) {
        list_folder[0] = my_strdup("./");
        v[1] = v[1] + 1;
    }
    if (v[2] < 0)
        exit(ERROR);
    list_folder = my_realloc(list_folder, sizeof(char *) *
    v[1], sizeof(char *) * (v[1] + 2));
    list_folder[v[1]] = 0;
    return list_folder;
}

void cal_ls(int i, int *values, char **list_folder, struct s_my_option *option)
{
    if ((values[1] > 1) || (values[1] == 1 && values[3] == 1)) {
        my_putstr(list_folder[i]);
        my_putstr(":\n");
    }
    simple_ls(option, list_folder[i]);
    if (values[1] > 1 && values[1] - 1 != i)
        my_putstr("\n");
}

void main(int argc, char **argv)
{
    struct s_my_option option;
    char **list_folder;
    int values[4] = {argc, 0, 0, 0};

    read_my_option(argc, argv, &option);
    list_folder = get_directory_option(values, argv, &option);
    for (int i = 0; i < values[1]; i++) {
        if (values[3] == 1)
            my_putstr("\n");
        if (option.rec == 0)
            cal_ls(i, values, list_folder, &option);
        else
            rec_ls(&option, list_folder[i]);
    }
    for (int j = 0; j < values[1]; j++)
        free(list_folder[j]);
    free(list_folder);
    exit(SUCESS);
}