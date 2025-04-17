/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:51:19 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/17 09:05:13 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_stack(t_stack_node **a)
{
    t_stack_node    *temp;
    if (!a || !*a)
        return ;
    while(*a)
    {
        temp = (*a)->next;
        free(*a);
        *a = temp;
    }
    printf("stack freed\n");
}

void    print_stack(t_stack_node **a)
{
    t_stack_node    *current;
    current = *a;
    while(current != NULL)
    {
        printf("a->value = : %d\n", current->value);
        current = current->next;
    }
    if (current == NULL)
        printf("a->value = : NULL\n");
}

void    print_stack_memory(t_stack_node **a)
{
    t_stack_node    *current;
    current = *a;
    while(current != NULL)
    {
        printf("a->next = : %p\n", current->next);
        current = current->next;
    }
    if (current == NULL)
        printf("a->next = : NULL\n");
}

void    print_both(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *current_a;
    t_stack_node    *current_b;
    
    current_a = *a;
    current_b = *b;
    while(current_a != NULL)
    {
        printf("a->value %d\n", current_a->value);
        current_a = current_a->next;
    }
    if (current_a == NULL)
        printf("a->value NULL\n\n");
    while(current_b != NULL)
    {
        printf("b->value %d\n", current_b->value);
        current_b = current_b->next;
    }
    if (current_b == NULL)
        printf("b->value NULL\n");
        printf("-------------\n");
}

t_stack_node    *get_last_node(t_stack_node **a)
{
    t_stack_node    *current;

    current = *a;
    if (*a == NULL || (*a)->next == NULL)
        return (NULL);
    while (current->next)
        current = current->next;
    return (current);
}

t_stack_node    *get_second_last_node(t_stack_node **a)
{
    t_stack_node    *current;

    if (*a == NULL || (*a)->next == NULL)
        return (NULL);
    current = *a;
    while (current->next && current->next->next)
        current = current->next;
    return (current);
}

int     get_stack_len(t_stack_node **a)
{
    t_stack_node    *current;
    int stack_len;

    if (!a || !*a)
        return (0);
    current = *a;
    stack_len = 1;
    while (current->next)
    {
        current = current->next;
        stack_len++;
    }
    return (stack_len);
}
