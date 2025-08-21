#include "push_swap.h"

int main(int ac, char **av)
{
    t_node *a = NULL;
    t_node *b = NULL;
    int size;

    if (ac < 2)
        return 0;
    if (!parse_args(ac, av, &a))
        error_exit(&a, &b);
    if (is_sorted(a))
    {
        free_stack(&a);
        return 0;
    }
    size = stack_size(a);
    if (size == 2 && a->value > a->next->value)
        sa(&a);
    else if (size == 3)
        sort_three(&a);
    else if (size == 4)
        sort_four(&a, &b);
    else if (size == 5)
        sort_five(&a, &b);
    else
    {
        index_stack(a);
        radix_sort(&a, &b);
    }
    free_stack(&a);
    free_stack(&b);
    return 0;
}
