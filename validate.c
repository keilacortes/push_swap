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

//int has_suplicate(char *str)

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
    return (1);
}