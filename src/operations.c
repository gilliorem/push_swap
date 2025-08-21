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

void    sa(t_node **a)
{
    if (swap(a))
        ft_printf("sa\n");
}

void    sb(t_node **b)
{
    if (swap(b))
        ft_printf("sb\n");
}

void    ss(t_node **a, t_node **b)
{
    int moved;

    moved = swap(a);
    moved += swap(b);
    if (moved)
        ft_printf("ss\n");
}

static int push_stack(t_node **src, t_node **dst)
{
    t_node *tmp;

    if (!*src)
        return 0;
    tmp = *src;
    *src = (*src)->next;
    tmp->next = *dst;
    *dst = tmp;
    return 1;
}

void    pa(t_node **a, t_node **b)
{
    if (push_stack(b, a))
        ft_printf("pa\n");
}

void    pb(t_node **a, t_node **b)
{
    if (push_stack(a, b))
        ft_printf("pb\n");
}

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

void    ra(t_node **a)
{
    if (rotate_stack(a))
        ft_printf("ra\n");
}

void    rb(t_node **b)
{
    if (rotate_stack(b))
        ft_printf("rb\n");
}

void    rr(t_node **a, t_node **b)
{
    int moved;

    moved = rotate_stack(a);
    moved += rotate_stack(b);
    if (moved)
        ft_printf("rr\n");
}

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

void    rra(t_node **a)
{
    if (reverse_rotate(a))
        ft_printf("rra\n");
}

void    rrb(t_node **b)
{
    if (reverse_rotate(b))
        ft_printf("rrb\n");
}

void    rrr(t_node **a, t_node **b)
{
    int moved;

    moved = reverse_rotate(a);
    moved += reverse_rotate(b);
    if (moved)
        ft_printf("rrr\n");
}
