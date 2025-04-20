/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:04:31 by vscode            #+#    #+#             */
/*   Updated: 2025/04/20 15:07:50 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	free_stack(t_stack_node **a)
{
	t_stack_node	*temp;

	if (!a || !*a)
		return ;
	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	DEBUG_PRINT(("stack freed"));
}

void	free_split_all(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		ft_printf("split[%d] is free : %s\n", i, split[i]);
		free(split[i++]);
	}
	free(split);
}
