/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:50:44 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/11/04 15:35:51 by kqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_a_args(char **args, t_stack *stack_a)
{
	int		i;
	int		count;
	t_node	*new_node;

	count = 0;
	while (args[count])
		count++;
	i = count - 1;
	while (i >= 0)
	{
		new_node = create_node(ft_atoi(args[i]));
		new_node->next = stack_a->top;
		stack_a->top = new_node;
		stack_a->size++;
		i--;
	}
}

static char	**prepare_args(int argc, char **argv, int *need_free)
{
	char	**args;

	*need_free = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*need_free = 1;
	}
	else
		args = &argv[1];
	return (args);
}

static int	validate_and_check(char **args, int need_free)
{
	if (!validate_args(args))
	{
		ft_printf("Error\n");
		if (need_free)
			free_split(args);
		return (0);
	}
	return (1);
}

static int	is_sorted(char **args)
{
	int	i;

	i = 0;
	while (args[i + 1])
	{
		if (ft_atoi(args[i]) > ft_atoi(args[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		need_free;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	argv = prepare_args(argc, argv, &need_free);
	if (is_sorted(argv))
	{
		if (need_free)
			free_split(argv);
		return (0);
	}
	if (!validate_and_check(argv, need_free))
		return (1);
	stack_a = init_stack();
	stack_b = init_stack();
	stack_a_args(argv, stack_a);
	sort_stack(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	if (need_free)
		free_split(argv);
	return (0);
}
