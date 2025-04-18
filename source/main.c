/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:03:09 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/19 01:38:50 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

int     main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				stack_len;	
	
	a = NULL;
	b = NULL;

	ft_printf("bonjour\n");
	ft_printf("is digit %d\n", ft_isdigit(1));

	if (1 == argc || (2 == argc) || !argv[1][0])
		return (1);
	if(!stack_init(&a, &argv[1]))
		return (1);
	stack_len = get_stack_len(&a);
	if (!stack_sorted(&a))
	{
		if (stack_len == 2)
			rotate_a(&a);	
		if (stack_len == 3)
			stack_sort_three(&a);
		if (stack_len > 3)
			push_swap(&a, &b);
	}
	if (a)
		free_stack(&a);
	return (0);
}
