/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-25 08:22:37 by thmaitre          #+#    #+#             */
/*   Updated: 2024-11-25 08:22:37 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_put_address(unsigned long long addr, int *printf_len);
void	ft_putnbr(int n, int *printf_len);
void	ft_putnbr_unsigned(unsigned int n, int *printf_len);
void	ft_putnbr_hex(unsigned int n, int *print_len, char is_upper);
void	ft_putnbr_addr(unsigned long long n, int *printf_len);

#endif
