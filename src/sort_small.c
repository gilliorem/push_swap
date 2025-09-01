#include "push_swap.h"

void sort_three(t_node **a)
{
    int f = (*a)->value;
    int s = (*a)->next->value;
    int t = (*a)->next->next->value;

    if (f > s && s < t && f < t)
        sa(a);
    else if (f > s && s > t)
    {
        sa(a);
        rra(a);
    }
    else if (f > s && s < t && f > t)
        ra(a);
    else if (f < s && s > t && f < t)
    {
        sa(a);
        ra(a);
    }
    else if (f < s && s > t && f > t)
        rra(a);
}

static void move_min_to_b(t_node **a, t_node **b)
{
    int pos;
    int size;

    size = stack_size(*a);
    pos = find_min_position(*a);
    if (pos <= size / 2)
        while (pos-- > 0)
            ra(a);
    else
        while (pos++ < size)
            rra(a);
    pb(a, b);
}

void sort_four(t_node **a, t_node **b)
{
    move_min_to_b(a, b);
    sort_three(a);
    pa(a, b);
}

void sort_five(t_node **a, t_node **b)
{
    move_min_to_b(a, b);
    move_min_to_b(a, b);
    sort_three(a);
    pa(a, b);
    pa(a, b);
}
