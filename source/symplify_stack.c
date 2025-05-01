/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symplify_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:27:31 by thmaitre          #+#    #+#             */
/*   Updated: 2025/05/01 21:14:07 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_array(t_stack_node **a, int **int_array, int *stack_len)
{
	t_stack_node	*node;
	int				i;

	if (!a || !*a || !(*a)->next)
		return (0);
	*stack_len = get_stack_len(a);
	*int_array = malloc(sizeof(int) * (*stack_len));
	if (!*int_array)
		return (0);
	node = *a;
	i = 0;
	while (node)
	{
		(*int_array)[i] = node->value;
		node = node->next;
		i++;
	}
	return (1);
}

void	sort_int_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	temp;

	if (!tab)
		return ;
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[j] < tab[i])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	symplify(t_stack_node **a, int *int_array, int stack_len)
{
	t_stack_node	*node;
	int				i;

	node = *a;
	while (node)
	{
		i = 0;
		while (i < stack_len)
		{
			if (node->value == int_array[i])
				node->value = i;
			i++;
		}
		node = node->next;
	}
}

int	symplify_stack(t_stack_node **a, int **int_array)
{
	int	stack_len;

	if(!stack_array(a, int_array, &stack_len))
		return (0);
	sort_int_tab(*int_array, stack_len);
	symplify(a, *int_array, stack_len);
	return (1);
}
