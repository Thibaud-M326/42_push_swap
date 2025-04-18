/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:20:13 by vscode            #+#    #+#             */
/*   Updated: 2025/04/18 20:45:33 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void get_stack_values(t_stack_node **a, int **stack_values, int *stack_len)
{
    t_stack_node    *node;
    int             i;

    if (!a || !*a || !(*a)->next)
        return ;
    *stack_len = get_stack_len(a);
    *stack_values = malloc(sizeof(int) * (*stack_len));
    if (!*stack_values)
        return ;
    node = *a;
    i = 0;
    while (node)
    {
        (*stack_values)[i] = node->value;
        node = node->next;
        i++;
    }
}

void    print_tab(int *tab, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        printf("tab : %d\n", tab[i]);
        i++;
    }
}

static void sort_int_tab(int *tab, int len)
{
    int i;
    int j;
    int temp;

    if (!tab)
        return ;
    i = 0;
    while (i < len)
    {
        j = i + 1;
        while (j < len)
        {
            if (tab[j] < tab[i])
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
            j++;
        }
        i++;
    }
}

void    symplify(t_stack_node **a, int *stack_values, int stack_len)
{
    t_stack_node    *node;
    int             i;

    node = *a;
    while (node)
    {
        i = 0;
        while (i < stack_len)
        {
            if (node->value == stack_values[i])
                node->value = i;
            i++;
        }
        node = node->next;
    }
}

static void symplify_stack(t_stack_node **a, int **stack_values)
{
    int stack_len;

    get_stack_values(a, stack_values, &stack_len);
    sort_int_tab(*stack_values, stack_len);
    symplify(a, *stack_values, stack_len);
}

static int     get_stack_top_value(t_stack_node **a)
{
    int num;

    num = (*a)->value;
    return (num);
}

int     is_stack_empty(t_stack_node **b)
{
    if (!*b)
        return (1);
    return (0);
}

void    radix(t_stack_node **a, t_stack_node **b)
{
    int stack_len;
    int max_value;
    int max_bits;
    int num;
    int i;

    stack_len = get_stack_len(a);
    max_value = stack_len - 1;
    max_bits = 0;
    while ((max_value >> max_bits) != 0)
        max_bits++;
    i = 0;
    while (i < max_bits)
    {
        stack_len = get_stack_len(a);
        while (stack_len--)
        {
            num = get_stack_top_value(a);
            if (((num >> i) & 1) == 1)
                rotate_a(a);
            else
                push_b(a, b);
        }
        while (!is_stack_empty(b))
            push_a(a, b);
        i++;
    }
}

void    push_swap(t_stack_node **a, t_stack_node **b)
{
    int *stack_values;

    if(!a || !*a || !b)
        return ;
    stack_values = NULL;
    symplify_stack(a, &stack_values);
    radix(a, b);
    if(stack_values)
        free(stack_values);
}