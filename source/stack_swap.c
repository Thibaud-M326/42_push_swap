/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-30 10:27:15 by thmaitre          #+#    #+#             */
/*   Updated: 2025-04-30 10:27:15 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack_node **a, int print)
{
	t_stack_node	*temp;
	t_stack_node	*b;

	if (!a || !*a || !(*a)->next)
		return ;
	b = (*a)->next;
	temp = b->next;
	b->next = *a;
	(*a)->next = temp;
	*a = b;
	if (print)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack_node **b, int print)
{
	t_stack_node	*temp;
	t_stack_node	*a;

	if (!b || !*b || !(*b)->next)
		return ;
	a = (*b)->next;
	temp = a->next;
	a->next = *b;
	(*b)->next = temp;
	*b = a;
	if (print)
		write(1, "sb\n", 3);
}

void	swap_swap(t_stack_node **a, t_stack_node **b)
{
	swap_a(a, 0);
	swap_b(b, 0);
	write(1, "ss\n", 3);
}
