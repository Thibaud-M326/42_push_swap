/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 07:00:41 by thmaitre          #+#    #+#             */
/*   Updated: 2025/04/18 23:05:45 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_support(const char *format, va_list arg)
{
	int		printf_len;
	int		i;

	printf_len = 0;
	i = 0;
	if (format[i] == 'c')
		printf_len = ft_putchar(va_arg(arg, int));
	if (format[i] == 's')
		printf_len = ft_putstr(va_arg(arg, char *));
	if (format[i] == 'p')
		ft_put_address(va_arg(arg, unsigned long long), &printf_len);
	if (format[i] == 'd')
		ft_putnbr(va_arg(arg, int), &printf_len);
	if (format[i] == 'i')
		ft_putnbr(va_arg(arg, int), &printf_len);
	if (format[i] == 'u')
		ft_putnbr_unsigned(va_arg(arg, unsigned int), &printf_len);
	if (format[i] == 'x' || format[i] == 'X')
		ft_putnbr_hex(va_arg(arg, unsigned int), &printf_len, format[i] == 'X');
	if (format[i] == '%')
		printf_len = write(1, &"%", 1);
	return (printf_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		printf_len;

	if (!format)
		return (-1);
	i = 0;
	printf_len = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			printf_len += ft_printf_support(&format[i + 1], arg);
			i += 1;
		}
		else
		{
			write(1, &format[i], 1);
			printf_len++;
		}
		i++;
	}
	va_end(arg);
	return (printf_len);
}

// 	#include <stdio.h>

// int	main(void)
// {
// 	char	*a;
// 	int		ft_printf_len;
// 	int		printf_len;

// 	a = "bonjour";
// 	ft_printf_len = ft_printf("%s\n", a);
// 	printf_len = printf("%s\n", a);

// 	printf("mine %d\n", ft_printf_len);
// 	printf("true %d\n", printf_len);
// 	return (0);
// }
