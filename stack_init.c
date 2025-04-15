/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:35:12 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/15 17:04:13 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_front_stack(t_stack_node **a, int value)
{
    t_stack_node    *new_node;

    new_node = malloc(sizeof(t_stack_node));
    if(!new_node)
        return ;
    new_node->value = value;
    new_node->prev = *a;
    *a = new_node;
}

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

void    stack_init(t_stack_node **a, char **argv)
{
    int i;
    int value;

    i = 0;
    // if (!check_only_num(argv))
    //     return ;
    while (argv[i])
    {
        value = ft_atoi(argv[i]);
        // if (value > 2147483647 || value < -2147483648)
        // {
        //     free_stack(a);
        //     return ;
        // }
        push_back_stack(a, value);
        i++;
    }
    // if (is_duplicate_num_in_stack(a))
    // {
    //     free_stack(a);
    //     return ;
    // }
}