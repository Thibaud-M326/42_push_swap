/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:58:15 by thibaud           #+#    #+#             */
/*   Updated: 2025/04/20 16:02:28 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define DEBUG_MODE 1
# define DEBUG_PRINT(x) if (DEBUG_MODE) { printf x; }

# include <unistd.h>
# include <stdlib.h>

	# include <stdio.h>

typedef struct s_atoi_check
{
	int			sign;
	int			nb;
	int			error;
}	t_atoi_check;

typedef struct s_stack_node
{
	int					value;
	int					simplified;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

// push_swap.c
void			push_swap(t_stack_node **a, t_stack_node **b);

// atol_overflow.c
t_atoi_check	atol_overflow(const char *nptr);

// stack_init.c
int				push_back_stack(t_stack_node **a, int value);
int				stack_init(t_stack_node **a, char **argv);

// stack_sort.c
int				stack_sorted(t_stack_node **a);
void			stack_sort_three(t_stack_node **a);

// stack_swap.c
void			swap_a(t_stack_node **a);
void			swap_b(t_stack_node **b);
void			swap_swap(t_stack_node **a, t_stack_node **b);

// stack_rotate.c
void			rotate_a(t_stack_node **a);
void			rotate_b(t_stack_node **b);
void			rotate_rotate(t_stack_node **a, t_stack_node **b);

// stack_reverse_rotate.c
void			reverse_rotate_a(t_stack_node **a);
void			reverse_rotate_b(t_stack_node **a);
void			reverse_rotate_rotate(t_stack_node **a, t_stack_node **b);

//stack_push.c
void			push_a(t_stack_node **a, t_stack_node **b);
void			push_b(t_stack_node **a, t_stack_node **b);

// stack_utils.c
t_stack_node	*get_last_node(t_stack_node **a);
t_stack_node	*get_second_last_node(t_stack_node **a);
int				get_stack_len(t_stack_node **a);
int				is_stack_empty(t_stack_node **b);
int				get_stack_top_value(t_stack_node **a);

// stack_print.c
void			print_stack(t_stack_node **a);
void			print_both(t_stack_node **a, t_stack_node **b);

// free_utils.c
void			free_stack(t_stack_node **a);
void			free_split(char **split);

// symplify_stack.c
void			stack_array(t_stack_node **a, int **int_array, int *stack_len);
void			sort_int_tab(int *tab, int len);
void			symplify(t_stack_node **a, int *int_array, int stack_len);
void			symplify_stack(t_stack_node **a, int **int_array);
#endif
