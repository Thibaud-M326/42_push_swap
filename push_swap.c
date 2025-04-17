/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:20:13 by vscode            #+#    #+#             */
/*   Updated: 2025/04/17 21:31:29 by vscode           ###   ########.fr       */
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
        //mettre mon printf
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

static void symplify_stack_value(t_stack_node **a, int *stack_values)
{
    //create a copy tab of stack values
    int stack_len;

    get_stack_values(a, &stack_values, &stack_len);
    printf("stack_value tab : \n");
    print_tab(stack_values, stack_len);
    //sort stack_values
    sort_int_tab(stack_values, stack_len);
    printf("stack_value tab sorted: \n");
    print_tab(stack_values, stack_len);
    //use sorted_values to simplify stack values
    symplify(a, stack_values, stack_len);
}

static int     get_top(t_stack_node **a)
{
    int num;

    if (!a || !*a)
        return (0);
    num = (*a)->value;

    return (num);
}

//return 1 si stack vide 
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
    int i;


    stack_len = get_stack_len(a);
    max_value = stack_len - 1;
    while ((max_value >> max_bits) != 0)
        max_bits++;
}

void    push_swap(t_stack_node **a, t_stack_node **b)
{
    int *stack_values;

    if(!a || !*a || !b)
        return ;
    stack_values = NULL;
    //first simplify stack value
    symplify_stack_value(a, stack_values);

    //then use it to sort with radix
    // radix(a, b);

    //free stack_value
    if(stack_values)
        free(stack_values);
}