/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:01:24 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/15 18:25:24 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_atoi_sign(int *i, const char *nptr)
{
	int sign;
	
	sign = 1;
	while ((nptr[*i] >= 9 && nptr[*i] <= 13) || nptr[*i] == 32)
		(*i)++;
	while (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i + 1] == '-' || nptr[*i + 1] == '+')
			return (0);
		else if (nptr[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

t_atoi_check	atol_overflow(const char *nptr)
{
	t_atoi_check check;
	long	long_nb;
	int		sign;
	int		i;

	check.error = 0;
	long_nb = 0;
	i = 0;
	sign = get_atoi_sign(&i, nptr);
	while (nptr[i] >= '0' && nptr[i] <= '9' && check.error == 0)
	{
		long_nb = long_nb * 10 + (nptr[i] - 48);
        if (long_nb > 2147483647 || long_nb < -2147483648)
		{
			check.error = 1;
			return (check);
		}
		i++;
	}
	check.nb = (int)long_nb;
	check.nb *= sign;
	return (check);
}