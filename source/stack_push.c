/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-30 10:26:08 by thmaitre          #+#    #+#             */
/*   Updated: 2025-04-30 10:26:08 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;

	if (b == NULL || a == NULL || *b == NULL)
		return ;
	temp = (*b)->next;
	if (*a == NULL)
		(*b)->next = NULL;
	else
		(*b)->next = *a;
	*a = *b;
	*b = temp;
	write(1, "pa\n", 3);
}

void	push_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;

	if (a == NULL || b == NULL || *a == NULL)
		return ;
	temp = (*a)->next;
	if (*b == NULL)
		(*a)->next = NULL;
	else
		(*a)->next = *b;
	*b = *a;
	*a = temp;
	write(1, "pb\n", 3);
}
