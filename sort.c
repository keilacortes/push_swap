// header

#include "push_swap.h"

int min_value(t_stack *stack)
{
    t_node  *current;
    int     min;

    current = stack->top;
    min = current->value;
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return (min);
}

int min_position(t_stack *stack)
{
    t_node  *current;
    int     min;
    int     pos;
    int     min_pos;

    current = stack->top;
    min = current->value;
    pos = 0;
    min_pos = 0;
    while (current)
    {
        if (current->value < min)
        {
            min = current->value;
            min_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return (min_pos);
}

void    sort_two(t_stack *a)
{
    if (a->top->value > a->top->next->value)
        sa(a);
}

void    sort_three(t_stack *a)
{
    int first;
    int second;
    int third;

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

void    sort_four(t_stack *a, t_stack *b)
{
    int pos;

    pos = min_position(a);
    if (pos <= 2)
    {
        while (pos > 0)
        {
            ra(a);
            pos--;
        }
    }
    else
    {
        while (pos < 4)
        {
            rra(a);
            pos++;
        }
    }
    pb(a, b);
    sort_three(a);
    pa(a, b);
}

void    sort_five(t_stack *a, t_stack *b)
{
    int pos;

    pos = min_position(a);
    if (pos <= 2)
    {
        while (pos > 0)
        {
            ra(a);
            pos--;
        }
    }
    else
    {
        while (pos < 5)
        {
            rra(a);
            pos++;
        }
    }
    pb(a, b);
    sort_four(a, b);
    pa(a, b);
}

void    sort_stack(t_stack *a, t_stack *b)
{
    int size;

    size = a->size;
    if (size == 2)
        sort_two(a);
    else if (size == 3)
        sort_three(a);
    else if (size == 4)
        sort_four(a, b);
    else if (size == 5)
        sort_five(a, b);
    else
        radix_sort(a, b);
}
