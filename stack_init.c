/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:35:12 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/15 18:20:12 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_back_stack(t_stack_node **a, int value)
{
    t_stack_node    *new_node;
    t_stack_node    *current;

    new_node = malloc(sizeof(t_stack_node));
    if(!new_node)
        return ;
    new_node->value = value;
    new_node->next = NULL;
    if (*a == NULL)
    {
        *a = new_node;
        return ;
    }
    current = *a;
    while (current->next != NULL)
        current = current->next;
    current->next = new_node;
    current->prev = current;
}

int stack_init(t_stack_node **a, char **argv)
{
    int i;
	t_atoi_check check;

    i = 0;
    while (argv[i])
    {
        check = atol_overflow(argv[i]);
        if (check.overflow == 1)
        {
            printf("atoi overflow free_stack");
            free_stack(a);
            return (0);
        }
        push_back_stack(a, check.nb);
        i++;
    }
    // if (is_duplicate_num_in_stack(a))
    // {
    //     free_stack(a);
    //     return ;
    // }
    return (1);
}