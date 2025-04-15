/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:05:19 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/15 17:10:10 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate_a(t_stack_node **a)
{
    t_stack_node    *b;
    t_stack_node    *temp;
    if (!a || !*a || !(*a)->next)
        return ;
    b = get_last_node(a);
    temp = (*a)->next;
    b->next = *a;
    (*a)->next = NULL;
    *a = temp;
    write(1, "rra\n", 4);
}

void    reverse_rotate_b(t_stack_node **b)
{
    t_stack_node    *a;
    t_stack_node    *temp;
    if (!b || !*b || !(*b)->next)
        return ;
    a = get_last_node(b);
    temp = (*b)->next;
    a->next = *b;
    (*b)->next = NULL;
    *b = temp;
    write(1, "rrb\n", 4);
}

void    reverse_rotate_rotate(t_stack_node **a, t_stack_node **b)
{
    reverse_rotate_a(a);
    reverse_rotate_b(b);
    write(1, "rrr\n", 4);
}