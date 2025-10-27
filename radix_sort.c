//header

#include "push_swap.h"

void    bubble_sort(int *arr, int size)
{
    int i;
    int j;
    int temp;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

int *sorted_array(t_stack *a)
{
    int     *arr;
    t_node  *current;
    int     i;

    arr = malloc(sizeof(int) * a->size);
    if (!arr)
        return (NULL);
    current = a->top;
    i = 0;
    while (current)
    {
        arr[i] = current->value;
        current = current->next;
        i++;
    }
    bubble_sort(arr, a->size);
    return (arr);
}

void    assign_index(t_stack *a)
{
    int     *arr;
    t_node  *current;
    int     i;

    arr = sorted_array(a);
    if (!arr)
        return ;
    current = a->top;
    while (current)
    {
        i = 0;
        while (i < a->size)
        {
            if (current->value == arr[i])
            {
                current->index = i;
                break ;
            }
            i++;
        }
        current = current->next;
    }
    free(arr);
}

int get_max_bit(int stack_size)
{
    int max_bit;
    int max_num;

    max_bit = 0;
    max_num = stack_size - 1;
    while ((max_num >> max_bit) != 0)
        max_bit++;
    return (max_bit);
}

void radix_sort(t_stack *a, t_stack *b)
{
    int max_bit;
    int i;
    int j;
    int count;

    assign_index(a);
    max_bit = get_max_bit(a->size);
    i = 0;
    while (i < max_bit)
    {
        j = 0;
        count = a->size;
        while (j < count)
        {
            if (((a->top->index >> i) & 1) == 1)
                ra(a);
            else
                pb(a, b);
            j++;
        }
        while (b->top)
            pa(a, b);
        i++;
    }
}
