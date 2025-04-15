/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:14:47 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/15 14:58:14 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    test_swaps()
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;

//	test sa

    char *test_tab[] = { "1", "2", "3", "4", "5", NULL};
    stack_init(&a, test_tab);
	print_both(&a, &b);
	swap_a(&a);
	print_both(&a, &b);

	printf("-----test----\n\n");

	t_stack_node	*a_2;

	a_2 = NULL;
    char *test_tab_2[] = { "1", NULL};
    stack_init(&a_2, test_tab_2);
	print_both(&a_2, &b);

	printf("-----test----\n\n");

	t_stack_node	*a_3;

	a_3 = NULL;
    char *test_tab_3[] = { NULL };
    stack_init(&a_3, test_tab_3);
	print_both(&a_3, &b);

//	test sb

	a = NULL;
	b = NULL;

    char *test_tab_4[] = { "1", "2", "3", "4", "5", NULL};
    stack_init(&b, test_tab_4);
	print_both(&a, &b);
	swap_a(&b);
	print_both(&a, &b);

	printf("-----test----\n\n");

	t_stack_node	*b_2;

	b_2 = NULL;
    char *test_tab_5[] = { "1", NULL};
    stack_init(&b_2, test_tab_5);
	print_both(&a, &b_2);

	printf("-----test----\n\n");

	t_stack_node	*b_3;

	b_3 = NULL;
    char *test_tab_6[] = { NULL };
    stack_init(&b_3, test_tab_3);
	print_both(&a, &b_3);
}