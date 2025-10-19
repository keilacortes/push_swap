/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:13:20 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/10/15 15:13:21 by kqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(t_stack *a, t_stack *b)
{
    t_node  *tmp;
    if (!b->top)
        return ;
    tmp = b-> top;
    b->top = b->top->next;
    tmp->next = a->top;
    a->top = tmp;
    a->size++;
}

void    pb(t_stack *a, t_stack *b)
{
    t_node  *tmp;
    if (!a->top)
        return ;
    tmp = a-> top;
    a->top = a->top->next;
    tmp->next = b->top;
    b->top = tmp;
    b->size++;
}
