#include "push_swap.h"
#include "ft_printf.h"

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

void pa(t_node **a, t_node **b)
{
    if (push_stack(b, a))
        ft_printf("pa\n");
}

void pb(t_node **a, t_node **b)
{
    if (push_stack(a, b))
        ft_printf("pb\n");
}

