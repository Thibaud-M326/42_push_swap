/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:58:15 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/15 17:02:31 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

    #include <stdio.h>

# include <unistd.h>
# include <stdlib.h>

typedef struct  s_stack_node
{
    int                 value;
    struct s_stack_node *prev;
    struct s_stack_node *next;
}               t_stack_node;

// atoi.c
int             ft_atoi(const char *nptr);

// stack_init.c
void            push_stack(t_stack_node **a, int value);
void            stack_init(t_stack_node **a, char **argv);

// stack_swap.c
void            swap_a(t_stack_node **a);
void            swap_b(t_stack_node **b);
void            swap_swap(t_stack_node **a, t_stack_node **b);

// stack_rotate.c
void            rotate_a(t_stack_node **a);
void            rotate_b(t_stack_node **b);
void            rotate_rotate(t_stack_node **a, t_stack_node **b);

// stack_reverse_rotate.c
void            reverse_rotate_a(t_stack_node **a);
void            reverse_rotate_b(t_stack_node **a);
void            reverse_rotate_rotate(t_stack_node **a, t_stack_node **b);

//stack_push.c
void            push_a(t_stack_node **a, t_stack_node **b);
void            push_b(t_stack_node **a, t_stack_node **b);

// stack_utils.c
void            print_stack(t_stack_node **a);
void            print_both(t_stack_node **a, t_stack_node **b);
t_stack_node    *get_last_node(t_stack_node **a);
t_stack_node    *get_second_last_node(t_stack_node **a);
int             stack_len(t_stack_node **a);

// check_argv.c
int     check_only_num(char **argv);

#endif
