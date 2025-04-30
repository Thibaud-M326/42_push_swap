/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-30 10:26:37 by thmaitre          #+#    #+#             */
/*   Updated: 2025-04-30 10:26:37 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack_node **a, int print)
{
	t_stack_node	*temp;
	t_stack_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	last = get_last_node(a);
	temp = (*a)->next;
	(*a)->next = NULL;
	last->next = *a;
	*a = temp;
	if (print)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack_node **b, int print)
{
	t_stack_node	*temp;
	t_stack_node	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	last = get_last_node(b);
	temp = (*b)->next;
	(*b)->next = NULL;
	last->next = *b;
	*b = temp;
	if (print)
		write(1, "rb\n", 3);
}

void	rotate_rotate(t_stack_node **a, t_stack_node **b)
{
	rotate_a(a, 0);
	rotate_b(b, 0);
	write(1, "rr\n", 3);
}
