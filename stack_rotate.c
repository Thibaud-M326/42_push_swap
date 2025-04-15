/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:04:15 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/15 17:09:28 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_a(t_stack_node **a)
{
    t_stack_node    *b;
    t_stack_node    *second_last_node;
    if (!a || !*a || !(*a)->next)
        return ;
    b = get_last_node(a);
    second_last_node = get_second_last_node(a);
    b->next = *a;
    second_last_node->next = NULL;
    *a = b;
    write(1, "ra\n", 3);
}

void    rotate_b(t_stack_node **b)
{
    t_stack_node    *a;
    t_stack_node    *second_last_node;
    if (!b || !*b || !(*b)->next)
        return ;
    a = get_last_node(b);
    second_last_node = get_second_last_node(b);
    a->next = *b;
    second_last_node->next = NULL;
    *b = a;
    write(1, "rb\n", 3);
}

void    rotate_rotate(t_stack_node **a, t_stack_node **b)
{
    rotate_a(a);    
    rotate_b(b);
    write(1, "rr\n", 3);
}