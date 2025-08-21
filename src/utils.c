#include "push_swap.h"

void error_exit(t_node **a, t_node **b)
{
    free_stack(a);
    free_stack(b);
    write(2, "Error\n", 6);
    exit(1);
}
