/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-25 08:30:55 by thmaitre          #+#    #+#             */
/*   Updated: 2024-11-25 08:30:55 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_put_address(unsigned long long addr, int *printf_len)
{
	if (!addr)
		*printf_len += ft_putstr("(nil)");
	else
	{
		*printf_len = ft_putstr("0x");
		ft_putnbr_addr(addr, printf_len);
	}
	return (*printf_len);
}
