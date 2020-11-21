/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** libmy
*/

#include <stddef.h>


#ifndef MY_LIB
#define MY_LIB

int my_atoi(char *str);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(long long nb);
int cal_square(int n, long long nb);
int my_find_prime_sup(int nb);
int my_is_prime(long long nb);
int cal_is_prime(int n, long long nb);
int my_isneg(int nb);
char *my_nbr_to_str(int nb);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putnbr_base(int nbr, char const *base);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_show_word_array(char * const *tab);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *array, int size);
int my_str_isalpha(char const *s);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char **my_str_to_word_array(char const *str);
char *my_str_without_spaces(char const *str);
char *my_strcapitalize(char *str);
int is_alphanum(char c);
int is_alpha(char c);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strcmp_by_char(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *search_my_strstr(char *str, char const *to_find, char const *cpy_to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
void *my_realloc(void *str, size_t old_size, size_t new_size);

#endif