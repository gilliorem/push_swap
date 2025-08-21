#include "push_swap.h"

static int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

static int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v');
}

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
    if (!ft_isdigit(s[*i]))
    {
        *error = 1;
        return 0;
    }
    while (ft_isdigit(s[*i]))
    {
        res = res * 10 + (s[*i] - '0');
        if (res * sign > INT_MAX || res * sign < INT_MIN)
            *error = 1;
        (*i)++;
    }
    return res * sign;
}

int parse_args(int ac, char **av, t_node **a)
{
    int arg = 1;
    while (arg < ac)
    {
        int i = 0;
        while (av[arg][i])
        {
            while (is_space(av[arg][i]))
                i++;
            if (av[arg][i] == '\0')
                break;
            int error = 0;
            long num = get_number(av[arg], &i, &error);
            if (error)
                return 0;
            if (!is_space(av[arg][i]) && av[arg][i] != '\0')
                return 0;
            if (stack_has_value(*a, (int)num))
                return 0;
            t_node *node = new_node((int)num);
            if (!node)
                return 0;
            add_back(a, node);
        }
        arg++;
    }
    return 1;
}
