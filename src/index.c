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

static int *fill_array(t_node *a, int size)
{
    int *arr;
    int i;

    arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        return NULL;
    i = 0;
    while (a)
    {
        arr[i++] = a->value;
        a = a->next;
    }
    return arr;
}

static void assign_indices(t_node *a, int *arr, int size)
{
    int i;
    t_node *tmp;

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
}

void index_stack(t_node *a)
{
    int size;
    int *arr;

    size = stack_size(a);
    arr = fill_array(a, size);
    if (!arr)
        return ;
    sort_array(arr, size);
    assign_indices(a, arr, size);
    free(arr);
}

