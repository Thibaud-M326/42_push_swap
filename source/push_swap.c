/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-30 10:25:23 by thmaitre          #+#    #+#             */
/*   Updated: 2025-04-30 10:25:23 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack_node **a)
{
	int	max_value;
	int	max_bits;

	max_value = get_stack_len(a) - 1;
	max_bits = 0;
	while ((max_value >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix(t_stack_node **a, t_stack_node **b)
{
	int	stack_len;
	int	max_bits;
	int	num;
	int	i;

	i = 0;
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		stack_len = get_stack_len(a);
		while (stack_len--)
		{
			num = get_stack_top_value(a);
			if (((num >> i) & 1) == 1)
				rotate_a(a, 1);
			else
				push_b(a, b);
		}
		while (!is_stack_empty(b))
			push_a(a, b);
		i++;
	}
}

int	push_swap(t_stack_node **a, t_stack_node **b)
{
	int	*int_array;

	if (!a || !*a || !b)
		return (0);
	int_array = NULL;
	if (!symplify_stack(a, &int_array))
		return (0);
	radix(a, b);
	if (int_array)
		free(int_array);
	return (1);
}
