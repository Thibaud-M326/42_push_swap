/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:35:12 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/20 00:15:30 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	free_split(char **split, int k)
{
	while (k >= 0)
	{
		printf("free split[%d]: %s\n", k, split[k]);
		free(split[k]);
		k--;
	}
	free(split);
}

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

void	free_split_all(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		printf("split[%d] is free : %s\n", i, split[i]);
		free(split[i++]);
	}
	free(split);
}

int	stack_init(t_stack_node **a, char **argv)
{
	t_atoi_check	check;
	char			**splited_argv;
	int				i;
	int				j;

	i = 0;
	check.error = 0;
	while (argv[i] && check.error == 0)
	{
		j = 0;
		splited_argv = ft_split(argv[i]);
		while (splited_argv[j])
		{
			printf("splited_argv[%d] : %s\n", j, splited_argv[j]);
			check = atol_overflow(splited_argv[j]);
			if (check.error == 0)
				check.error = push_back_stack(a, check.nb);
			if (check.error == 0)
				check.error = is_duplicate_num_in_stack(a);
			if (check.error == 1)
			{
				free_split_all(splited_argv);
				free_stack(a);
				return (0);
			}
			j++;
		}
		if (splited_argv)
		{
			printf("free_split at j : %d\n", j);
			free_split_all(splited_argv);
		}
		i++;
	}
	return (1);
}
