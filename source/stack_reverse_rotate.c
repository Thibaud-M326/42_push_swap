/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:05:19 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/20 14:05:04 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack_node **a)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!a || !*a || !(*a)->next)
		return ;
	last = get_last_node(a);
	second_last = get_second_last_node(a);
	second_last->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack_node **b)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!b || !*b || !(*b)->next)
		return ;
	last = get_last_node(b);
	second_last = get_second_last_node(b);
	second_last->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_rotate(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
	write(1, "rrr\n", 4);
}
