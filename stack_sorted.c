/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:24:58 by vscode            #+#    #+#             */
/*   Updated: 2025/04/16 20:10:14 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_sorted(t_stack_node **a)
{
    t_stack_node    *node;
    t_stack_node    *node_next;
    
    if(!a || !*a || !(*a)->next)
        return (0);
    node = *a;
    node_next = node->next;
    while (node->next)
    {
        if(node_next->value < node->value)
            return (0);
        node = node->next;
        node_next = node_next->next;
    }
    return (1);
}