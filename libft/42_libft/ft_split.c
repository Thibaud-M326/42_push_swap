/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-12 09:35:59 by thmaitre          #+#    #+#             */
/*   Updated: 2024-11-12 09:35:59 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_splits_count(char const *s, char c)
{
	int	i;
	int	splits_count;

	i = 1;
	splits_count = 0;
	while (s[i])
	{
		if (i && (s[i] != c) && (s[i - 1] == c || i - 1 == 0))
			splits_count++;
		i++;
	}
	return (splits_count);
}

static char	*ft_split_push(char *split_k, char const *s, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		split_k[i] = s[start];
		start++;
		i++;
	}
	split_k[i] = '\0';
	return (split_k);
}

void	*free_char_tab(char **split, int k)
{
	while (k >= 0)
	{
		free(split[k]);
		k--;
	}
	free(split);
	return (NULL);
}

static char	**ft_alloc_and_populate(char **split, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		if (s[i] && j != 0)
		{
			split[k] = malloc(sizeof(**split) * ((j - i) + 1));
			if (!split[k])
				return (free_char_tab(split, k));
			split[k] = ft_split_push(split[k], s, i, j);
			k++;
		}
		i = j;
	}
	split[ft_splits_count(s, c)] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (s[0] == '\0')
	{
		split = malloc(sizeof (*split));
		if (!split)
			return (NULL);
		split[0] = NULL;
		return (split);
	}
	split = malloc(sizeof (*split) * (ft_splits_count(s, c) + 1));
	if (!split)
		return (NULL);
	split = ft_alloc_and_populate(split, s, c);
	return (split);
}
