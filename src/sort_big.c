#include "push_swap.h"

static int get_max_bits(int size)
{
    int max_bits;

    max_bits = 0;
    while ((size - 1) >> max_bits)
        max_bits++;
    return max_bits;
}

static void process_bit(t_node **a, t_node **b, int size, int i)
{
    int j;

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
}

void radix_sort(t_node **a, t_node **b)
{
    int size;
    int max_bits;
    int i;

    size = stack_size(*a);
    max_bits = get_max_bits(size);
    i = 0;
    while (i < max_bits)
    {
        process_bit(a, b, size, i);
        i++;
    }
}

