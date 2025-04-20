/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:51:19 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/20 15:09:46 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_last_node(t_stack_node **a)
{
	t_stack_node	*current;

	current = *a;
	if (*a == NULL || (*a)->next == NULL)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

t_stack_node	*get_second_last_node(t_stack_node **a)
{
	t_stack_node	*current;

	if (*a == NULL || (*a)->next == NULL)
		return (NULL);
	current = *a;
	while (current->next && current->next->next)
		current = current->next;
	return (current);
}

int	get_stack_len(t_stack_node **a)
{
	t_stack_node	*current;
	int				stack_len;

	if (!a || !*a)
		return (0);
	current = *a;
	stack_len = 1;
	while (current->next)
	{
		current = current->next;
		stack_len++;
	}
	return (stack_len);
}

int	is_stack_empty(t_stack_node **b)
{
	if (!*b)
		return (1);
	return (0);
}

int	get_stack_top_value(t_stack_node **a)
{
	int	num;

	num = (*a)->value;
	return (num);
}
