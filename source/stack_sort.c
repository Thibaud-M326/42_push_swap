/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-30 10:26:50 by thmaitre          #+#    #+#             */
/*   Updated: 2025-04-30 10:26:50 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack_node **a)
{
	t_stack_node	*node;
	t_stack_node	*node_next;

	if (!a || !*a || !(*a)->next)
		return (0);
	node = *a;
	node_next = node->next;
	while (node->next)
	{
		if (node_next->value < node->value)
			return (0);
		node = node->next;
		node_next = node_next->next;
	}
	return (1);
}

void	stack_sort_three(t_stack_node **a)
{
	t_stack_node	*i;
	t_stack_node	*j;
	t_stack_node	*k;

	i = *a;
	j = i->next;
	k = j->next;
	if (i->value > j->value && j->value > k->value)
	{
		swap_a(&i);
		reverse_rotate_a(&i);
	}
	while (i->value > j->value || i->value > k->value)
		rotate_a(&i);
	j = i->next;
	k = j->next;
	if (j->value > k->value)
	{
		swap_a(&i);
		rotate_a(&i);
	}
	*a = i;
}

int	find_smallest_top(t_stack_node **a)
{
	t_stack_node	*node;
	int				smallest;
	int				smallest_pos;
	int				i;

	node = *a;
	smallest = (*a)->value;
	smallest_pos = 0;
	i = 0;
	while (node)
	{
		if (node->value < smallest)
		{
			smallest = node->value;
			smallest_pos = i;
		}
		i++;
		node = node->next;
	}
	return (smallest_pos);
}

void	stack_sort_four(t_stack_node **a, t_stack_node **b)
{
	int	smallest_pos;
	int	len;

	smallest_pos = find_smallest_top(a);
	len = get_stack_len(a);
	if (smallest_pos < len / 2)
		while (smallest_pos--)
			rotate_a(a);
	else
		while (smallest_pos++ < len)
			reverse_rotate_a(a);
	push_b(a, b);
	stack_sort_three(a);
	push_a(a, b);
}

void	stack_sort_five(t_stack_node **a, t_stack_node **b)
{
	int	smallest_pos;
	int	len;

	smallest_pos = find_smallest_top(a);
	len = get_stack_len(a);
	if (smallest_pos < len / 2)
		while (smallest_pos--)
			rotate_a(a);
	else
		while (smallest_pos++ < len)
			reverse_rotate_a(a);
	push_b(a, b);
	stack_sort_four(a, b);
	push_a(a, b);
}
