/*
** EPITECH PROJECT, 2019
** option
** File description:
** option
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/my_ls.h"

void display_invalid_option(void)
{
    my_putstr("my_ls: invalid option\n");
    my_putstr("Try 'my_ls --help' for more informations.\n");
}

void display_help(void)
{
    my_putstr("Usage: my_ls [OPTION]... [FILE]...\n");
    my_putstr("As default : List name of files.\n");
    my_putstr("Option are : \n");
    my_putstr("\tl : Long listing format\n");
    my_putstr("\tr : reverse order while sorting\n");
    my_putstr("\td : list directories themselves, not their contents\n");
    my_putstr("\tR : list subdirectories recursively\n");
    my_putstr("\tt : sort by modification time, newest first\n");
    exit(SUCESS);
}

void init_my_option(struct s_my_option *option)
{
    option->list = 0;
    option->rev = 0;
    option->dir = 0;
    option->rec = 0;
    option->time = 0;
}

void get_my_option(struct s_my_option *option, char *arg)
{
    int i = 0;

    if (arg[i] == '-')
        i++;
    for (i; arg[i]; i++) {
        if (arg[i] != 'l' && arg[i] != 'r' && arg[i] != 'd' && arg[i] != 'R'
        && arg[i] != 't') {
            display_invalid_option();
            exit(ERROR);
        }
        arg[i] == 'l' ? option->list = 1 : 0;
        arg[i] == 'r' ? option->rev = 1 : 0;
        arg[i] == 'd' ? option->dir = 1 : 0;
        arg[i] == 'R' ? option->rec = 1 : 0;
        arg[i] == 't' ? option->time = 1 : 0;
    }
}

void read_my_option(int argc, char **argv, struct s_my_option *option)
{
    init_my_option(option);
    for (int i = 1; i < argc; i++) {
        if (my_strcmp(argv[i], "--help") == 0) {
            display_help();
            exit(SUCESS);
        }
        else if (argv[i][0] == '-' && argv[i][1] != '\0')
            get_my_option(option, argv[i]);
    }
}