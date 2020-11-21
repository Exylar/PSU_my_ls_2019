/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_showmem
*/

int my_putstr(char const *str);
void my_putchar(char c);
int my_putnbr_base(int nbr, char const *base);

void print_space(int i)
{
    if (i % 2 == 1)
        my_putchar(' ');
}

int my_showmem(char const *str, int size)
{
    int k = 0;

    while (k < size) {
        my_putnbr_base(str[k], "0123456789abcdef");
        my_putstr(": ");
        for (int i = 0; i < 16; i++) {
            my_putnbr_base(str[i + k], "0123456789abcdef");
            print_space(i);
        }
        for (int i = 0; i < 16; i++)
            my_putchar(str[i + k]);
        my_putchar('\n');
        k = k + 16;
    }
    return 0;
}