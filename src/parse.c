#include "push_swap.h"

#define FT_ISDIGIT(c) ((c) >= '0' && (c) <= '9')
#define IS_SPACE(c) ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r' || (c) == '\f' || (c) == '\v')

static long get_number(const char *s, int *i, int *error)
{
    long sign = 1;
    long res = 0;

    if (s[*i] == '+' || s[*i] == '-')
    {
        if (s[*i] == '-')
            sign = -1;
        (*i)++;
    }
    if (!FT_ISDIGIT(s[*i]))
    {
        *error = 1;
        return 0;
    }
    while (FT_ISDIGIT(s[*i]))
    {
        res = res * 10 + (s[*i] - '0');
        if (res * sign > INT_MAX || res * sign < INT_MIN)
            *error = 1;
        (*i)++;
    }
    return res * sign;
}

static int process_number(t_node **a, const char *arg, int *i)
{
    long    num;
    int     error;
    t_node  *node;

    error = 0;
    num = get_number(arg, i, &error);
    if (error || (!IS_SPACE(arg[*i]) && arg[*i] != '\0') || stack_has_value(*a, (int)num))
        return 0;
    node = new_node((int)num);
    if (!node)
        return 0;
    add_back(a, node);
    return 1;
}

static int process_arg(const char *arg, t_node **a)
{
    int i;

    i = 0;
    while (arg[i])
    {
        while (IS_SPACE(arg[i]))
            i++;
        if (arg[i] == '\0')
            break ;
        if (!process_number(a, arg, &i))
            return 0;
    }
    return 1;
}

int parse_args(int ac, char **av, t_node **a)
{
    int arg;

    arg = 1;
    while (arg < ac)
    {
        if (!process_arg(av[arg], a))
            return 0;
        arg++;
    }
    return 1;
}

