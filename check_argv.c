/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:08:54 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/15 16:17:44 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     str_len(char *str)
{
    return (1);
}

int     check_only_num(char **argv)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (argv[i])
    {
        while(argv[i][j])
        {
            if (argv[i][j] > '0' || argv[i][j] < '9')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}