/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-30 10:26:00 by thmaitre          #+#    #+#             */
/*   Updated: 2025-04-30 10:26:00 by thmaitre         ###   ########.fr       */
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
