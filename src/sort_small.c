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

void sort_four(t_node **a, t_node **b)
{
    int pos = find_min_position(*a);

    if (pos == 1)
        ra(a);
    else if (pos == 2)
    {
        ra(a);
        ra(a);
    }
    else if (pos == 3)
        rra(a);
    pb(a, b);
    sort_three(a);
    pa(a, b);
}

void sort_five(t_node **a, t_node **b)
{
    int pos = find_min_position(*a);

    if (pos == 1)
        ra(a);
    else if (pos == 2)
    {
        ra(a);
        ra(a);
    }
    else if (pos == 3)
    {
        rra(a);
        rra(a);
    }
    else if (pos == 4)
        rra(a);
    pb(a, b);
    pos = find_min_position(*a);
    if (pos == 1)
        ra(a);
    else if (pos == 2)
    {
        ra(a);
        ra(a);
    }
    else if (pos == 3)
        rra(a);
    pb(a, b);
    sort_three(a);
    pa(a, b);
    pa(a, b);
}
