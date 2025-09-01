#include "push_swap.h"
#include "ft_printf.h"

static int rotate_stack(t_node **stack)
{
    t_node *first;
    t_node *last;

    if (!*stack || !(*stack)->next)
        return 0;
    first = *stack;
    last = *stack;
    while (last->next)
        last = last->next;
    *stack = first->next;
    first->next = NULL;
    last->next = first;
    return 1;
}

void ra(t_node **a)
{
    if (rotate_stack(a))
        ft_printf("ra\n");
}

void rb(t_node **b)
{
    if (rotate_stack(b))
        ft_printf("rb\n");
}

void rr(t_node **a, t_node **b)
{
    int moved;

    moved = rotate_stack(a);
    moved += rotate_stack(b);
    if (moved)
        ft_printf("rr\n");
}

