/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:06:31 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/15 17:19:00 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_a(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *temp;

    if (b == NULL || a == NULL|| *b == NULL)
        return ;
    temp = (*b)->prev;
    if (*a == NULL)
        (*b)->prev = NULL;
    else
        (*b)->prev = *a;
    *a = *b;
    *b = temp;
    write(1, "pb\n", 3);
}

void    push_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *temp;

    if (a == NULL || b == NULL|| *a == NULL)
        return ;
    temp = (*a)->prev;
    if (*b == NULL)
        (*a)->prev = NULL;
    else
        (*a)->prev = *b;
    *b = *a;
    *a = temp;
    write(1, "pb\n", 3);
}