/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:03:09 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/16 20:01:48 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (1 == argc || (2 == argc) || !argv[1][0])
		return (1);
	if(!stack_init(&a, &argv[1]))
		return (1);
	if(!stack_sorted(&a))
		printf("not sorted or empty\n");
	else 
		printf("sorted\n");

	print_both(&a, &b);

	free_stack(&a);
	return (0);
}
