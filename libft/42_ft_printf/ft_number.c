/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-25 09:31:36 by thmaitre          #+#    #+#             */
/*   Updated: 2024-11-25 09:31:36 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, int *printf_len)
{
	long	n;

	n = (long)nbr;
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		(*printf_len)++;
	}
	if (n > 9)
		ft_putnbr(n / 10, printf_len);
	write(1, &"0123456789"[n % 10], 1);
	(*printf_len)++;
}

void	ft_putnbr_unsigned(unsigned int n, int *printf_len)
{
	if (n > 9)
		ft_putnbr_unsigned(n / 10, printf_len);
	write(1, &"0123456789"[n % 10], 1);
	(*printf_len)++;
}

void	ft_putnbr_hex(unsigned int n, int *printf_len, char is_upper)
{
	if (n >= 16)
		ft_putnbr_hex(n / 16, printf_len, is_upper);
	if (is_upper)
		write(1, &"0123456789ABCDEF"[n % 16], 1);
	else
		write(1, &"0123456789abcdef"[n % 16], 1);
	(*printf_len)++;
}

void	ft_putnbr_addr(unsigned long long n, int *printf_len)
{
	if (n >= 16)
		ft_putnbr_addr(n / 16, printf_len);
	write(1, &"0123456789abcdef"[n % 16], 1);
	(*printf_len)++;
}
