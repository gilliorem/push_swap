#include "push_swap.h"

// create new node
t_node  *new_node(int value)
{
    t_node  *node;

    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return NULL;
    node->value = value;
    node->index = 0;
    node->next = NULL;
    return node;
}

// add node to end of stack
void    add_back(t_node **stack, t_node *new_node)
{
    t_node  *tmp;

    if (!*stack)
    {
        *stack = new_node;
        return ;
    }
    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_node;
}

int stack_has_value(t_node *stack, int value)
{
    while (stack)
    {
        if (stack->value == value)
            return 1;
        stack = stack->next;
    }
    return 0;
}

int stack_size(t_node *stack)
{
    int count = 0;

    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return count;
}

int is_sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return 0;
        stack = stack->next;
    }
    return 1;
}

void free_stack(t_node **stack)
{
    t_node  *tmp;

    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

int find_min_value(t_node *stack)
{
    int min = INT_MAX;

    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return min;
}

int find_min_position(t_node *stack)
{
    int min = INT_MAX;
    int pos = 0;
    int i = 0;

    while (stack)
    {
        if (stack->value < min)
        {
            min = stack->value;
            pos = i;
        }
        stack = stack->next;
        i++;
    }
    return pos;
}
