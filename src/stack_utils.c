#include "push_swap.h"

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

int find_min_value(t_node *stack)
{
    int min;

    min = INT_MAX;
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
    int min;
    int pos;
    int i;

    min = INT_MAX;
    pos = 0;
    i = 0;
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

