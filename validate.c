/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:18:58 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/11/04 15:24:57 by kqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(long num)
{
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	is_valid_number(char *str)
{
	int	i;

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

int	has_duplicate(char **args)
{
	int		i;
	int		j;
	long	num_i;
	long	num_j;

	i = 0;
	while (args[i])
	{
		num_i = ft_atol(args[i]);
		j = i + 1;
		while (args[j])
		{
			num_j = ft_atol(args[j]);
			if (num_i == num_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!is_valid_number(args[i]) || !is_int(ft_atol(args[i])))
			return (0);
		i++;
	}
	if (has_duplicate(args))
		return (0);
	return (1);
}
