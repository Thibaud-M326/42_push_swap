/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:35:12 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/19 16:41:03 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
				DEBUG_PRINT(("duplicate"));
				printf("Error\n");
				return (1);
			}
			j = j->next;
		}
		if (i->value == j->value)
		{
			DEBUG_PRINT(("duplicate"));
			printf("Error\n");
			return (1);
		}
		i = i->next;
	}
	return (0);
}

int stack_init(t_stack_node **a, char **argv)
{
	t_atoi_check	check;
    int				i;
	char			**splited_argv;
    int				j;

		(void)a;

    i = 0;
	check.error = 0;
	DEBUG_PRINT(("DEBUG : stack_init\n"));
    while (argv[i] && check.error == 0)
    {
			j = 0;
			splited_argv = ft_split(argv[i]);
			while (splited_argv[j])
			{
				printf("argv[%d] splited_argv[%d] : %s\n", i, j, splited_argv[j]);
				j++;
			}



		// DEBUG_PRINT(("DEBUG : %s\n", splited_argv[0]));
		// while (splited_argv[j_split])
		// {
			// check = atol_overflow(splited_argv[j_split]);
			// check = atol_overflow(argv[i]);
			// if (check.error == 0)
			// 	check.error = push_back_stack(a, check.nb);
			// if (check.error == 0)
			// 	check.error = is_duplicate_num_in_stack(a);
			// if (check.error == 1)
			// {
			// 	free_stack(a);
			// 	return (0);
			// }
    	// 	j_split++;
		// }
        i++;
    }
    return (1);
}