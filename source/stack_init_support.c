/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_support.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-05 19:42:45 by thmaitre          #+#    #+#             */
/*   Updated: 2025-05-05 19:42:45 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	push_back_stack(t_stack_node **a, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*current;

	if (!a)
		return (1);
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
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
	t_stack_node	*i;
	t_stack_node	*j;

	if (!a || !*a)
		return (1);
	i = *a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
			{
				ft_putendl_fd("Error", 2);
				return (1);
			}
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	push_split_stack(t_stack_node **a, char **splited_argv)
{
	t_atoi_check	check;
	int				i;

	i = 0;
	check.error = 0;
	while (splited_argv[i])
	{
		check = atol_overflow(splited_argv[i]);
		if (check.error == 0)
			check.error = push_back_stack(a, check.nb);
		if (check.error == 0)
			check.error = is_duplicate_num_in_stack(a);
		if (check.error == 1)
			return (0);
		i++;
	}
	return (1);
}

int	is_empty_argv(char **argv)
{
	int	i;
	int	j;
	int	only_space;

	i = 0;
	while (argv[i])
	{
		j = 0;
		only_space = 1;
		while (argv[i][j])
		{
			if (!ft_is_white_space(argv[i][j]))
			{
				only_space = 0;
				break ;
			}
			j++;
		}
		if (only_space)
			return (1);
		i++;
	}
	return (0);
}
