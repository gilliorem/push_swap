#include "push_swap.h"

// create new node

t_node *new_node(int value)
{
    t_node *node;

    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return NULL;
    node->value = value;
    node->index = 0;
    node->next = NULL;
    return node;
}

// add node to end of stack
void add_back(t_node **stack, t_node *new)
{
    t_node *tmp;

    if (!*stack)
    {
        *stack = new;
        return;
    }
    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

int stack_size(t_node *stack)
{
    int count;

    count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return count;
}

void free_stack(t_node **stack)
{
    t_node *tmp;

    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

