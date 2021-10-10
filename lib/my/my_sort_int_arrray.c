/*
** EPITECH PROJECT, 2018
** my_sort_int_array
** File description:
** my_sort_int_array
*/

int swap_if_needed(int *nb1, int *nb2);
void my_swap(int *a, int *b);

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int j = 0;

    while (i < size) {
        while (j < size - 1 - i) {
            swap_if_needed(&array[j], &array[j + 1]);
            j++;
        }
        i++;
    }
}

int swap_if_needed(int *nb1, int *nb2)
{
    if (*nb1 > *nb2) {
        my_swap(nb1, nb2);
        return (1);
    }
    return (0);
}
