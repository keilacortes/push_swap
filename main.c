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

static void	stack_a_one_arg(char *arg, t_stack *stack_a)
{
	int		count;
	char	**numbers;
	t_node	*new_node;

	numbers = ft_split(arg, ' ');
	count = 0;
	while (numbers[count])
		count++;
	count -= 1;
	while (count >= 0)
	{
		new_node = create_node(ft_atoi(numbers[count]));
		new_node->next = stack_a->top;
		stack_a->top = new_node;
		stack_a->size++;
		count--;
	}
	free_split(numbers);
}

static void	stack_a_mult_args(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	t_node	*new_node;

	i = argc - 1;
	while (i >= 1)
	{
		new_node = create_node(ft_atoi(argv[i]));
		new_node->next = stack_a->top;
		stack_a->top = new_node;
		stack_a->size++;
		i--;
	}
}

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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		return (1);
	if (argc == 2)
		stack_a_one_arg(argv[1], stack_a);
	else if (argc > 2)
		stack_a_mult_args(argc, argv, stack_a);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
