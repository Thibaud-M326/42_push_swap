/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:41:46 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/21 00:07:55 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack_node **a)
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
	write(1, "sa\n", 3);
}

void	swap_b(t_stack_node **b)
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
	write(1, "sb\n", 3);
}

void	swap_swap(t_stack_node **a, t_stack_node **b)
{
	swap_a(a);
	swap_b(b);
	write(1, "ss\n", 3);
}
