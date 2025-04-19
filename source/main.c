/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:03:09 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/19 16:46:33 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// int     main(int argc, char **argv)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;
// 	int				stack_len;

// 	a = NULL;
// 	b = NULL;
// 	if (1 == argc || 2 == argc || !argv[1][0])
// 		return (1);
// 	if(!stack_init(&a, &argv[1]))
// 		return (1);
// 	stack_len = get_stack_len(&a);
// 	if (!stack_sorted(&a))
// 	{
// 		if (stack_len == 2)
// 			rotate_a(&a);
// 		if (stack_len == 3)
// 			stack_sort_three(&a);
// 		if (stack_len > 3)
// 			push_swap(&a, &b);
// 	}
// 	if (a)
// 		free_stack(&a);
// 	return (0);
// }




// #include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int     ft_count_words(char *str)
{
    int is_word;
    int count;
    int i;

    is_word = 0;
    count = 0;
    i = 0;
    while(str[i] != '\0')
    {
        while(str[i] != ' ' && str[i] != '\f' && str[i] != '\t'
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
        is_word = 0;
        i++;
    }
    return (count);
}

char    *ft_strndup(char *str, int n)
{
    char *dup;
    int i;

    dup = malloc(sizeof(char) * n + 1);
    i = 0;
    while(i != n)
    {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

void    assign_split(char *str, char** split)
{
    int end;
    int beg;
    int word;

    end = 0;
    beg = 0;
    word = 0;
    while (str[end])
    {
        while((str[beg] == ' ' || str[beg] == '\f' || str[beg] == '\t'
			|| str[beg] == '\n' || str[beg] == '\r' || str[beg] == '\v') 
				&& str[beg] != '\0')
            beg++;
        end = beg;
        while(str[end] != ' ' && str[end] != '\f' && str[end] != '\t' 
			&& str[end] != '\n' && str[end] != '\r' && str[end] != '\v' 
				&& str[end] != '\0')
            end++;
        split[word] = ft_strndup(&str[beg], end - beg);
        beg = end;
        word++;
    }
}

char    **ft_split(char *str)
{
    int count_words;
    char **split;

    count_words = ft_count_words(str);
    split = malloc(sizeof(char *) * (count_words + 1));
	if (!split)
		return (NULL);
    assign_split(str, split);
    split[count_words] = NULL;
    return (split);
}

int main(int argc, char **argv)
{
	char **split;
	int i;
	int j;

	(void)argc;
	i = 0;
	j = 0;

	while (argv[i])
	{
		split = ft_split(argv[i]);
		j = 0;
		while (split[j])
		{
			printf("split [%d] : %s\n", j, split[j]);
			j++;
		}
		i++;
	}
}