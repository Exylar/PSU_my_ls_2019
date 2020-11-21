/*
** EPITECH PROJECT, 2019
** my_ls_l
** File description:
** my_ls_l
*/

#include <stdlib.h>
#include <sys/stat.h>
#include "../include/my_ls.h"
#include "../include/my.h"
#include <time.h>
#include <pwd.h>
#include <grp.h>

void display_permission(char *name_file)
{
    struct stat file;

    lstat(name_file, &file);
    file.st_mode & (S_IRUSR) ? my_putstr("r") : my_putstr("-");
    file.st_mode & (S_IWUSR) ? my_putstr("w") : my_putstr("-");
    if ((file.st_mode & S_ISUID) && !(file.st_mode & S_IXUSR))
        my_putstr("S");
    else if ((file.st_mode & S_ISUID) && (file.st_mode & S_IXUSR))
        my_putstr("s");
    else
        file.st_mode & (S_IXUSR) ? my_putstr("x") : my_putstr("-");
    file.st_mode & (S_IRGRP) ? my_putstr("r") : my_putstr("-");
    file.st_mode & (S_IWGRP) ? my_putstr("w") : my_putstr("-");
    display_last_perm(name_file);

}

void display_user_groupe_size(char *name_file, int max_size)
{
    struct passwd *pwd;
    struct group *grp;
    struct stat file;

    lstat(name_file, &file);
    my_putstr(" ");
    my_put_nbr(file.st_nlink);
    my_putstr(" ");
    pwd = getpwuid(file.st_uid);
    my_putstr(pwd->pw_name);
    my_putstr(" ");
    grp = getgrgid(file.st_gid);
    my_putstr(grp->gr_name);
    my_putstr(" ");
    display_minor_major(name_file, max_size);
}

void display_time(char *name_file)
{
    char *time;
    char **wtime;
    struct stat file;

    lstat(name_file, &file);
    time = ctime(&file.st_mtime);
    wtime = my_str_to_word_array(time);
    my_putstr(wtime[1]);
    my_strlen(wtime[2]) == 1 ? my_putstr("  ") : my_putstr(" ");
    my_putstr(wtime[2]);
    my_putstr(" ");
    my_putstr(wtime[3]);
    my_putstr(":");
    my_putstr(wtime[4]);
    my_putstr(" ");
    for (int i = 0; wtime[i] != 0; i++)
        free(wtime[i]);
    free(wtime);
}

void diplay_type_file(char *name_file)
{
    struct stat file;

    lstat(name_file, &file);
    switch (file.st_mode & S_IFMT) {
        case S_IFCHR:
            my_putstr("c");
            break;
        case S_IFDIR:
            my_putstr("d");
            break;
        case S_IFLNK:
            my_putstr("l");
            break;
        case S_IFREG:
            my_putstr("-");
            break;
        default:
            my_putstr("-");
            break;
    }
}

void ls_l(char **name_files, int i, char *pathname)
{
    struct stat file_stat;
    char **new_path = get_files_with_path(name_files, pathname, i);
    int total_size = 0;
    int max_size = 0;

    get_files_infos(new_path, i, &max_size, &total_size);
    for (int j = 0; j < i; j++) {
        if (lstat(new_path[j], &file_stat) != -1) {
            diplay_type_file(new_path[j]);
            display_permission(new_path[j]);
            display_user_groupe_size(new_path[j], max_size);
            my_putstr(" ");
            display_time(new_path[j]);
            display_file_style(name_files[j], new_path[j]);
            display_symlink(new_path[j]);
        }
        my_putchar('\n');
    }
    for (int k = 0; k < i; k++)
        free(new_path[k]);
    free(new_path);
}