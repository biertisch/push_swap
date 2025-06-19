/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:11:52 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/16 19:11:52 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/include/libft.h"
# include <stdlib.h>

typedef struct s_double_list
{
	int						value;
	int						index;
	struct s_double_list	*prev;
	struct s_double_list	*next;	
}							t_double_list;

typedef struct s_data
{
	t_double_list	*stack_a;
	t_double_list	*stack_b;
	unsigned int	size_a;
	unsigned int	size_b;
	t_list			*instr;
	char			**input;
}					t_data;

t_double_list	*create_node(int n);
void			add_node_back(t_double_list **stack, t_double_list *new);
void			add_node_front(t_double_list **stack, t_double_list *new);
void			delete_node(t_double_list **head);
t_double_list	*get_last_node(t_double_list *stack);
int				get_stack_size(t_double_list *stack);
void			error(char *s, int n, t_data *data);
void			print_instr(t_list *instr);
void			add_instr(t_list **instr, char *op, t_data *data);
int				optimize_last_intr(t_list **instr, char *op, t_data *data);
int				cancelling_ops(char *last_op, char *op);
char			*combine_ops(char *last_op, char *op);
int				main(int argc, char **argv);
void			free_data(t_data *data);
void			free_stack(t_double_list **stack);
void			free_instr(t_list **instr);
void			free_input(char **input);
void			rev_rotate(char id, t_data *data);
void			rotate(char id, t_data *data);
void			swap(char id, t_data *data);
void			push(char id, t_data *data);
int				push_setup(char id, t_data *data, t_double_list **from,
					t_double_list **to);
t_double_list	*general_setup(char id, t_data *data, char *op_a, char *op_b);
void			initiate(char **raw_input, t_data *data);
void			parser(t_data *data);
void			duplicate_check(t_double_list *stack, t_data *data);
void			delete_last_node(t_list **head);
void			sort(t_data *data);
void			sort_two(char id, t_data *data);
void			sort_three(char id, t_data *data);
void			sort_four_to_five(char id, t_data *data);
t_double_list	**get_stack(char id, t_data *data);
void			min_to_top(char id, t_data *data);
int				get_min_index(t_double_list *stack);
void			radix(t_data *data);
void			normalize_stack(t_double_list *stack, t_data *data);
void			bubble_sort(int *array, int size);
void			stack_to_arr(t_double_list *stack, int *array, int size);
void			arr_to_stack(t_double_list *stack, int *array, int size);
void			int_swap(int *a, int *b);

#endif