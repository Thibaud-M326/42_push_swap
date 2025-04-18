/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:33:39 by thmaitre          #+#    #+#             */
/*   Updated: 2024/11/05 13:12:03 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//retourne la len de s
size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}
