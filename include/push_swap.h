#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
}   t_node;

/* parsing */
int     parse_args(int ac, char **av, t_node **a);

/* stack utils */
t_node  *new_node(int value);
void    add_back(t_node **stack, t_node *new_node);
int     stack_has_value(t_node *stack, int value);
int     stack_size(t_node *stack);
int     is_sorted(t_node *stack);
void    free_stack(t_node **stack);
int     find_min_position(t_node *stack);
int     find_min_value(t_node *stack);

/* operations */
void    sa(t_node **a);
void    sb(t_node **b);
void    ss(t_node **a, t_node **b);
void    pa(t_node **a, t_node **b);
void    pb(t_node **a, t_node **b);
void    ra(t_node **a);
void    rb(t_node **b);
void    rr(t_node **a, t_node **b);
void    rra(t_node **a);
void    rrb(t_node **b);
void    rrr(t_node **a, t_node **b);

/* sorting */
void    sort_three(t_node **a);
void    sort_four(t_node **a, t_node **b);
void    sort_five(t_node **a, t_node **b);
void    radix_sort(t_node **a, t_node **b);
void    index_stack(t_node *a);

/* misc */
void    error_exit(t_node **a, t_node **b);

#endif
