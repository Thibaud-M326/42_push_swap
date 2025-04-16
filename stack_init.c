/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:35:12 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/15 18:20:12 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_back_stack(t_stack_node **a, int value)
{
    t_stack_node    *new_node;
    t_stack_node    *current;

    if (!a)
        return (1);
    new_node = malloc(sizeof(t_stack_node));
    if(!new_node)
        return (1);
    new_node->value = value;
    new_node->next = NULL;
    if (!*a)
    {
        *a = new_node;
        return (0);
    }
    current = *a;
    while (current->next != NULL)
        current = current->next;
    current->next = new_node;
    return (0);
}

int	is_duplicate_num_in_stack(t_stack_node **a)
{
	t_stack_node *i;	
	t_stack_node *j;	

	if(!a || !*a)
		return (1);
	i = *a;
	while (i->next)
	{
		j = i->next;
		while (j->next)
		{
			if (i->value == j->value)
			{
				printf("duplicate\n");
				return (1);
			}
			j = j->next;
		}
		if (i->value == j->value)
		{
			printf("duplicate\n");
			return (1);
		}
		i = i->next;
	}
	return (0);
}

int stack_init(t_stack_node **a, char **argv)
{
    int i;
	t_atoi_check	check;

    i = 0;
	check.error = 0;
    while (argv[i] && check.error == 0)
    {
		check = atol_overflow(argv[i]);
		if (check.error == 0)
        	check.error = push_back_stack(a, check.nb);
		if (check.error == 0)
			check.error = is_duplicate_num_in_stack(a);
        if (check.error == 1)
        {
            free_stack(a);
            return (0);
        }
        i++;
    }
	// print_stack(a);
	// check.error = is_duplicate_num_in_stack(a);
    return (1);
}