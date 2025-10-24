/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:13:06 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/10/15 15:13:07 by kqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack *a)
{
    t_node  *first;
    t_node  *second;

    if (!a->top || !a->top->next)
        return ;
    first = a->top;
    second = a->top->next;
    first->next = second->next;
    second->next = first;
    a->top = second;
    ft_printf("sa\n");
}

void    sb(t_stack *b)
{
    t_node  *first;
    t_node  *second;

    if (!b->top || !b->top->next)
        return ;
    first = b->top;
    second = b->top->next;
    first->next = second->next;
    second->next = first;
    b->top = second;
    ft_printf("sb\n");
}

void    ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
    ft_printf("ss\n");
}
