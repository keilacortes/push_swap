// header

#include "push_swap.h"

int is_valid_number(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int has_duplicate(char **args)
{
    int i;
    int j;
    int num_i;
    int num_j;

    i = 0;
    while (args[i])
    {
        num_i = ft_atoi(args[i]);
        j = i + 1;
        while (args[j])
        {
            num_j = ft_atoi(args[j]);
            if (num_i == num_j)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int validate_args(char **args)
{
    int     i;

    i = 0;
    while (args[i])
    {
        if(!is_valid_number(args[i]))
            return (0);
        i++;
    }
    if (has_duplicate(args))
        return (0);
    return (1);
}
