#include "push_swap.h"

void radix_sort(t_node **a, t_node **b)
{
    int size;
    int max_bits;
    int i;
    int j;

    size = stack_size(*a);
    max_bits = 0;
    while ((size - 1) >> max_bits)
        max_bits++;
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if (((*a)->index >> i) & 1)
                ra(a);
            else
                pb(a, b);
            j++;
        }
        while (*b)
            pa(a, b);
        i++;
    }
}
