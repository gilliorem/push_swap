#include "push_swap.h"

static void sort_array(int *arr, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] > arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

void index_stack(t_node *a)
{
    int size = stack_size(a);
    int *arr;
    int i;
    t_node *tmp;

    arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        return ;
    tmp = a;
    i = 0;
    while (tmp)
    {
        arr[i++] = tmp->value;
        tmp = tmp->next;
    }
    sort_array(arr, size);
    tmp = a;
    while (tmp)
    {
        i = 0;
        while (i < size)
        {
            if (arr[i] == tmp->value)
            {
                tmp->index = i;
                break ;
            }
            i++;
        }
        tmp = tmp->next;
    }
    free(arr);
}
