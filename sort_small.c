/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:30:35 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/11/04 15:32:01 by kqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && first > third)
	{
		ra(a);
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	else if (second > first && second > third)
	{
		rra(a);
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	else if (first > second)
		sa(a);
}
