/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:04:15 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/15 17:18:14 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_a(t_stack_node **a)
{
    t_stack_node    *b;
    t_stack_node    *second_last_node;
    if (!a || !*a || !(*a)->prev)
        return ;
    b = get_last_node(a);
    second_last_node = get_second_last_node(a);
    b->prev = *a;
    second_last_node->prev = NULL;
    *a = b;
    write(1, "ra\n", 3);
}

void    rotate_b(t_stack_node **b)
{
    t_stack_node    *a;
    t_stack_node    *second_last_node;
    if (!b || !*b || !(*b)->prev)
        return ;
    a = get_last_node(b);
    second_last_node = get_second_last_node(b);
    a->prev = *b;
    second_last_node->prev = NULL;
    *b = a;
    write(1, "rb\n", 3);
}

void    rotate_rotate(t_stack_node **a, t_stack_node **b)
{
    rotate_a(a);    
    rotate_b(b);
    write(1, "rr\n", 3);
}