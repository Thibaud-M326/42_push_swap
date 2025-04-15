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
    t_stack_node   *temp;
    t_stack_node   *last;
    if (!a || !*a || !(*a)->next)
        return ;
    last = get_last_node(a);
    temp = (*a)->next;
    (*a)->next = NULL;
    last->next = *a;
    *a = temp;
    write(1, "ra\n", 3);
}

void    rotate_b(t_stack_node **b)
{
    t_stack_node   *temp;
    t_stack_node   *last;
    if (!b || !*b || !(*b)->next)
        return ;
    last = get_last_node(b);
    
    temp = (*b)->next;
    (*b)->next = NULL;
    last->next = *b;
    *b = temp;
    write(1, "rb\n", 3);
}

void    rotate_rotate(t_stack_node **a, t_stack_node **b)
{
    rotate_a(a);    
    rotate_b(b);
    write(1, "rr\n", 3);
}