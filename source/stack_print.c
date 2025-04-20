/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:34:10 by vscode            #+#    #+#             */
/*   Updated: 2025/04/20 14:40:50 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	print_stack(t_stack_node **a)
{
	t_stack_node	*current;

	current = *a;
	while (current != NULL)
	{
		ft_printf("a->value = %d\n", current->value);
		current = current->next;
	}
	if (current == NULL)
		ft_printf("a->value = : NULL\n");
}

void	print_both(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*current_a;
	t_stack_node	*current_b;

	current_a = *a;
	current_b = *b;
	while (current_a != NULL)
	{
		ft_printf("a->value %d\n", current_a->value);
		current_a = current_a->next;
	}
	if (current_a == NULL)
		ft_printf("a->value NULL\n\n");
	while (current_b != NULL)
	{
		ft_printf("b->value %d\n", current_b->value);
		current_b = current_b->next;
	}
	if (current_b == NULL)
		ft_printf("b->value NULL\n");
	ft_printf("-------------\n");
}
