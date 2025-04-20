/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol_overflow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:01:24 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/20 00:07:39 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_invalid_char(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i])
	{
		if ((nptr[i] < '0' || nptr[i] > '9')
			&& nptr[i] != '-' && nptr[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

static t_atoi_check	get_atoi_sign(int *i, const char *nptr, t_atoi_check check)
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

static	t_atoi_check	get_long_value(int *i, long *long_nb, const char *nptr, t_atoi_check check)
{
	while (nptr[*i] >= '0' && nptr[*i] <= '9' && check.error == 0)
	{
		*long_nb = *long_nb * 10 + (nptr[*i] - '0');
		if ((check.sign == 1 && *long_nb > 2147483647)
			|| (check.sign == -1 && *long_nb > 2147483648))
		{
			check.error = 1;
			return (check);
		}
		(*i)++;
	}
	return (check);
}

static t_atoi_check	no_sign_after_number(int *i, const char *nptr, t_atoi_check check)
{
	while (nptr[*i])
	{
		DEBUG_PRINT(("DEBUG : nptr[%d] : %c\n", *i, nptr[*i]));
		if (nptr[*i] == '-' || nptr[*i] == '+')
		{
			printf("Error\n");
			check.error = 1;
			return (check);
		}
		(*i)++;
	}
	return (check);
}

t_atoi_check	atol_overflow(const char *nptr)
{
	t_atoi_check	check;
	long			long_nb;
	int				i;

	printf("nptr in atol : %s\n", nptr);

	if ((!nptr || nptr[0] == '\0')
		|| ((nptr[0] == '-' || nptr[0] == '+')
			&& !(nptr[1] >= '0' && nptr[1] <= '9')))
	{
		//pas d'erreur pour le nptr[0] on sort juste
		DEBUG_PRINT(("DEBUG : empty string or sign alone\n"));
		printf("Error\n");
		check.error = 1;
		return (check);
	}
	check.sign = 1;
	check.error = 0;
	check.nb = 0;
	long_nb = 0;
	i = 0;
	check.error = has_invalid_char(nptr);
	if (check.error)
	{
		DEBUG_PRINT(("DEBUG : invalid char\n"));
		printf("Error\n");
		return (check);
	}
	check = get_atoi_sign(&i, nptr, check);
	if (check.error)
	{
		DEBUG_PRINT(("DEBUG : invalid atol\n"));
		printf("Error\n");
		return (check);
	}
	check = get_long_value(&i, &long_nb, nptr, check);
	if (check.error)
	{
		DEBUG_PRINT(("DEBUG : input_overflowed int\n"));
		printf("Error\n");
		return (check);
	}
	check = no_sign_after_number(&i, nptr, check);
	if (check.error)
	{
		DEBUG_PRINT(("DEBUG : there is a sign after number\n"));
		printf("Error\n");
		return (check);
	}
	check.nb = (int)long_nb;
	check.nb *= check.sign;
	return (check);
}
