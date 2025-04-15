/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:41:46 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/15 17:18:39 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_a(t_stack_node **a)
{
    t_stack_node    *temp;
    t_stack_node    *b;
    if (!a || !*a || !(*a)->prev)
        return ;
    b = (*a)->prev;
    temp = b->prev;
    b->prev = *a;
    (*a)->prev = temp;
    *a = b;
    write(1, "sa\n", 3);
}

void    swap_b(t_stack_node **b)
{
    t_stack_node    *temp;
    t_stack_node    *a;
    if (!b || !*b || !(*b)->prev)
        return ;
    a = (*b)->prev;
    temp = a->prev;
    a->prev = *b;
    (*b)->prev = temp;
    *b = a;
    write(1, "sb\n", 3);
}

void    swap_swap(t_stack_node **a, t_stack_node **b)
{
    swap_a(a);
    swap_b(b);
    write(1, "ss\n", 3);
}
