/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:03:09 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/20 16:48:11 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				stack_len;

	a = NULL;
	b = NULL;
	if (1 == argc || 2 == argc)
		return (1);
	if (!stack_init(&a, &argv[1]))
		return (1);
	stack_len = get_stack_len(&a);
	print_both(&a, &b);
	if (!stack_sorted(&a))
	{
		if (stack_len == 2)
			rotate_a(&a);
		if (stack_len == 3)
			stack_sort_three(&a);
		if (stack_len > 3)
			push_swap(&a, &b);
	}
	print_both(&a, &b);
	if (a)
		free_stack(&a);
	return (0);
}
