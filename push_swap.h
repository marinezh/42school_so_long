/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:20:43 by mzhivoto          #+#    #+#             */
/*   Updated: 2025/03/09 15:40:47 by mzhivoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ctype.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

// typedef struct s_node
// {
// 	int				num;
// 	int				index;
// 	int				flag;
// 	struct s_node	*next;
// 	struct s_node	*prev;
// } t_node;

// typedef struct s_all
// {
// 	t_node	*stack_a;
// 	t_node	*stack_b;
// 	int		mib_a;
// 	int 	med;
// 	int 	len_a;
// 	int 	len_b;
// }

typedef struct s_stack
{
	int				*arr;
	int				size;
}					t_stack;

typedef struct s_chunk
{
	int				chunks;
	int				chunk_size;
	int				temp_chunk_size;
}					t_chunk;

int					is_valid_number(char *str);
long long			safe_atoi(char *str, int *num);
int					has_duplicates(int *arr, int size);
int					count_words(char *str);
int					*parse_input(int ac, char **av, int *size);

void				free_args(char **args);
void				free_stacks(t_stack *stack_a, t_stack *stack_b);

int					*sorted_array(int *arr, int size);
void				rank_numbers(int *arr, int size);

int					find_max_index(t_stack *stack_a);
int					find_min_index(t_stack *stack_a);
int					is_sorted(t_stack *stack_a);
void				move_to_top_a(t_stack *stack, int index);
void				move_to_top_b(t_stack *stack, int index);
int					cost_to_top(t_stack *stack, int index);
int					push_to_b_cost(t_stack *stack_a, int limit);
void				push_all_to_a(t_stack *stack_a, t_stack *stack_b);
void				sort_two(t_stack *stack_a);
void				sort_three(t_stack *stack_a);
void				sort_four_five(t_stack *stack_a, t_stack *stack_b);
void				chunk_sort(t_stack *stack_a, t_stack *stack_b);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);

void first_move_500(t_stack *stack_a, t_stack *stack_b);
void chunk_sort_100(t_stack *stack_a, t_stack *stack_b);
void chunk_sort_500(t_stack *stack_a, t_stack *stack_b);

void print_stack_a(t_stack *stack);
void print_stack_b(t_stack *stack);
void print_array(int *arr, int size);

#endif
