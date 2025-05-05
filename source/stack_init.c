/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-30 10:25:44 by thmaitre          #+#    #+#             */
/*   Updated: 2025-04-30 10:25:44 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	stack_init_support(t_stack_node **a, char **argv)
{
	char	**splited_argv;
	int		i;

	i = 0;
	while (argv[i])
	{
		splited_argv = ft_split(argv[i]);
		if (!splited_argv)
		{
			free_stack(a);
			return (0);
		}
		if (!push_split_stack(a, splited_argv))
		{
			free_split(splited_argv);
			free_stack(a);
			return (0);
		}
		if (splited_argv)
			free_split(splited_argv);
		i++;
	}
	return (1);
}

int	stack_init(t_stack_node **a, char **argv)
{
	if (is_empty_argv(argv))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	if (!stack_init_support(a, argv))
		return (0);
	return (1);
}
