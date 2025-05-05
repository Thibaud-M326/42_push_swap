/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niroched <niroched@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:35:59 by thmaitre          #+#    #+#             */
/*   Updated: 2025/04/30 11:12:20 by niroched         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	free_char_tab(char **split, int k)
{
	while (k >= 0)
	{
		free(split[k]);
		k--;
	}
	free(split);
	return (0);
}

int	ft_count_words(char *str)
{
	int	is_word;
	int	count;
	int	i;

	is_word = 0;
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != ' ' && str[i] != '\f' && str[i] != '\t'
			&& str[i] != '\n' && str[i] != '\r' && str[i] != '\v'
			&& str[i] != '\0')
		{
			if (is_word == 0)
			{
				is_word = 1;
				count++;
			}
			i++;
		}
		if (str[i] != '\0')
			i++;
		is_word = 0;
	}
	return (count);
}

char	*ft_strndup(char *str, int n)
{
	char	*dup;
	int		i;

	dup = malloc((n + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i != n)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	assign_split(char *str, char **split)
{
	int	end;
	int	beg;
	int	word;

	end = 0;
	beg = 0;
	word = 0;
	while (str[end])
	{
		while ((ft_is_white_space(str[beg])) && str[beg] != '\0')
			beg++;
		end = beg;
		while (!ft_is_white_space(str[end]) && str[end] != '\0')
			end++;
		if (end > beg)
		{
			split[word] = ft_strndup(&str[beg], end - beg);
			if (!split[word])
				return (free_char_tab(split, word));
			word++;
		}
		beg = end;
	}
	return (1);
}

char	**ft_split(char *str)
{
	int		count_words;
	char	**split;

	count_words = ft_count_words(str);
	split = malloc(sizeof(char *) * (count_words + 1));
	if (!split)
		return (NULL);
	if (!assign_split(str, split))
		return (NULL);
	split[count_words] = NULL;
	return (split);
}
