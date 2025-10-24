/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:50:44 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/10/15 16:03:30 by kqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

static t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

static void free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

static char	**split_one_arg(char *arg)
{
	char	**numbers;

	numbers = ft_split(arg, ' ');
	return (numbers);
}

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

//remover
void print_stack(t_stack *stack, char name)
{
    t_node *current;

    if (!stack || !stack->top)
    {
        ft_printf("Stack %c: (empty)\n", name);
        return;
    }
    ft_printf("Stack %c: ", name);
    current = stack->top;
    while (current)
    {
        ft_printf("%d ", current->value);
        current = current->next;
    }
    ft_printf("(size: %d)\n", stack->size);
}

static char	**prepare_args(int argc, char **argv, int *need_free)
{
	char	**args;

	*need_free = 0;
	if (argc == 2)
	{
		args = split_one_arg(argv[1]);
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

int	main(int argc, char **argv)
{
	int		need_free;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	if (argc < 2)
		return (0);
	args = prepare_args(argc, argv, &need_free);
	if (!validate_and_check(args, need_free))
		return (1);
	stack_a = init_stack();
	stack_b = init_stack();
	stack_a_args(args, stack_a);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	free_stack(stack_a);
	free_stack(stack_b);
	if (need_free)
		free_split(args);
	return (0);
}

//mover funções
//header no validate e atol