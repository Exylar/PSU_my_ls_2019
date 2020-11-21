/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls
*/

#define SUCESS 0
#define ERROR 84

#ifndef MY_LS_H
#define MY_LS_H

struct s_my_option
{
    int hide;
    int list;
    int rev;
    int dir;
    int rec;
    int time;
};

void display_invalid_option(void);
void display_help(void);
void simple_ls(struct s_my_option *option, char *pathname);
void get_my_option(struct s_my_option *option, char *arg);
void read_my_option(int argc, char **argv, struct s_my_option *option);
char **get_files(int *i, struct s_my_option *op, char * pathname);
void ls_l(char **name_files, int i, char *pathname);
void sort_alphabetically(char **array, int size, struct s_my_option *option);
void sort_time(char **array, int size);
char **get_folder(int *i, struct s_my_option *op, char *pathname);
void rec_ls(struct s_my_option *option, char *pathname);
void get_files_infos(char **list_file_path, int size, int *m_size, int *t_size);
char **get_files_with_path(char **name_files, char *pathname, int size);
void display_symlink(char *name_file);
void diplay_type_file(char *name_file);
void display_time(char *name_file);
void display_user_groupe_size(char *name_file, int max_size);
void display_permission(char *name_file);
void display_file(char *name_file, struct s_my_option *option);
char **remove_path_file(char **path_files, char *pathname, int size);
void display_minor_major(char *name_file, int max_size);
void display_error(char *argv, int n_error);
void display_last_perm(char *name_file);
void check_dir(char **list, int *v, char *argv, struct s_my_option *option);
void rec_call(struct s_my_option *option, char *folder);
void display_files(char **name_files, char **path_files, int size, int a);
void display_file_style(char *name, char *path_file);

#endif //MY_LS_H
