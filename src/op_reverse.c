#include "push_swap.h"
#include "ft_printf.h"

static int reverse_rotate(t_node **stack)
{
    t_node *prev;
    t_node *last;

    if (!*stack || !(*stack)->next)
        return 0;
    prev = NULL;
    last = *stack;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
    return 1;
}

void rra(t_node **a)
{
    if (reverse_rotate(a))
        ft_printf("rra\n");
}

void rrb(t_node **b)
{
    if (reverse_rotate(b))
        ft_printf("rrb\n");
}

void rrr(t_node **a, t_node **b)
{
    int moved;

    moved = reverse_rotate(a);
    moved += reverse_rotate(b);
    if (moved)
        ft_printf("rrr\n");
}

