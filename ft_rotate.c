/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:13:44 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/10/15 15:13:45 by kqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_stack *a)
{
    t_node  *first;
    t_node  *last;

    if (!a->top || !a->top->next)
        return ;
    first = a->top;
    a->top = first->next;
    last = a->top;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
}

void    rb(t_stack *b)
{
    t_node  *first;
    t_node  *last;

    if (!b->top || !b->top->next)
        return ;
    first = b->top;
    b->top = first->next;
    last = b->top;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;
}

void    rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
}
