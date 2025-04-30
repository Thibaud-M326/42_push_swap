/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol_overflow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-30 10:24:50 by thmaitre          #+#    #+#             */
/*   Updated: 2025-04-30 10:24:50 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

int	has_invalid_char(char *nptr)
{
	int	i;

	i = 0;
	if ((!nptr) || ((nptr[0] == '-' || nptr[0] == '+')
			&& !(nptr[1] >= '0' && nptr[1] <= '9')))
		return (1);
	while (nptr[i])
	{
		if ((nptr[i] < '0' || nptr[i] > '9')
			&& nptr[i] != '-' && nptr[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

t_atoi_check	get_atoi_sign(int *i, char *nptr, t_atoi_check check)
{
	if (check.error == 1)
		return (check);
	while ((nptr[*i] >= 9 && nptr[*i] <= 13) || nptr[*i] == 32)
		(*i)++;
	while (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i + 1] == '-' || nptr[*i + 1] == '+')
		{
			check.error = 1;
			return (check);
		}
		else if (nptr[*i] == '-')
			check.sign *= -1;
		(*i)++;
	}
	return (check);
}

t_atoi_check	get_l_value(int *i, long *l_nb, char *nptr, t_atoi_check check)
{
	while (nptr[*i] >= '0' && nptr[*i] <= '9' && check.error == 0)
	{
		*l_nb = *l_nb * 10 + (nptr[*i] - '0');
		if ((check.sign == 1 && *l_nb > 2147483647)
			|| (check.sign == -1 && *l_nb > 2147483648))
		{
			check.error = 1;
			return (check);
		}
		(*i)++;
	}
	return (check);
}

t_atoi_check	no_sign_after_number(int *i, char *nptr, t_atoi_check check)
{
	while (nptr[*i])
	{
		if (nptr[*i] == '-' || nptr[*i] == '+')
		{
			check.error = 1;
			return (check);
		}
		(*i)++;
	}
	return (check);
}

t_atoi_check	atol_overflow(char *nptr)
{
	t_atoi_check	check;
	long			l_nb;
	int				i;

	check.error = 0;
	check.sign = 1;
	check.nb = 0;
	l_nb = 0;
	i = 0;
	check.error = has_invalid_char(nptr);
	check = get_atoi_sign(&i, nptr, check);
	check = get_l_value(&i, &l_nb, nptr, check);
	check = no_sign_after_number(&i, nptr, check);
	if (check.error)
	{
		ft_putendl_fd("Error", 2);
		return (check);
	}
	check.nb = (int)l_nb;
	check.nb *= check.sign;
	return (check);
}
