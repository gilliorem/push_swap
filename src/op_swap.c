#include "push_swap.h"
#include "ft_printf.h"

static int swap(t_node **stack)
{
    t_node *first;
    t_node *second;

    if (!*stack || !(*stack)->next)
        return 0;
    first = *stack;
    second = (*stack)->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
    return 1;
}

void sa(t_node **a)
{
    if (swap(a))
        ft_printf("sa\n");
}

void sb(t_node **b)
{
    if (swap(b))
        ft_printf("sb\n");
}

void ss(t_node **a, t_node **b)
{
    int moved;

    moved = swap(a);
    moved += swap(b);
    if (moved)
        ft_printf("ss\n");
}

