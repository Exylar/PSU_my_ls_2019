/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_sort_int_array
*/

void my_swap(int *a, int *b);

void is_sup(int *array, int i, int j)
{
    if (array[i] < array[j])
        my_swap(&array[i], &array[j]);
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            is_sup(array, i, j);
    }
}