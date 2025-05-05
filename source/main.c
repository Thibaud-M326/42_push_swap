/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:25:14 by thmaitre          #+#    #+#             */
/*   Updated: 2025/05/01 21:04:01 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_by_stack_size(t_stack_node **a, t_stack_node **b)
{
	int				stack_len;

	stack_len = get_stack_len(a);
	if (stack_len == 2)
		rotate_a(a, 1);
	if (stack_len == 3)
		stack_sort_three(a);
	if (stack_len == 4)
		stack_sort_four(a, b);
	if (stack_len == 5)
		stack_sort_five(a, b);
	if (stack_len > 5)
		if (!push_swap(a, b))
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (1 == argc)
		return (0);
	if (!stack_init(&a, &argv[1]))
		return (1);
	if (!stack_sorted(&a))
	{
		if (!sort_by_stack_size(&a, &b))
		{
			if (a)
				free_stack(&a);
			return (1);
		}
	}
	if (a)
		free_stack(&a);
	return (0);
}
