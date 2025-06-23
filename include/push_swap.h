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

# include "../libft/include/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;	
}					t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
	t_list	*instr;
	char	**input;
}			t_data;

//main
int		main(int argc, char **argv);
void	error_msg(char *msg, t_data *data);

//mem
void	free_split(char **arr);
void	free_list(t_list **instr);
void	free_stack(t_stack **stack);
void	free_data(t_data *data);

//parser
void	parser(char **argv, t_data *data);

//input_check
void	validate_input(char **input, t_data *data);

//d_list
t_stack	*create_node(int value, int index);
void	add_node_back(t_stack **head, t_stack *new);
void	delete_first_node(t_stack **head);
t_stack	*get_last_node(t_stack *head);
int		get_stack_size(t_stack *head);

//s_list
void	delete_last_node(t_list **head);

//ops
void	push(char id, t_data *data);
void	swap(char id, t_data *data);
void	rotate(char id, t_data *data);
void	rev_rotate(char id, t_data *data);

//ops_utils
void	log_instr(char id, t_data *data, char *instr_a, char *instr_b);
t_stack	**get_stack(char id, t_data *data);
int		do_both(char id, void (*op)(char, t_data *), t_data *data);
char	get_other_id(char id);

//instr
void	print_instr(t_list *instr);
void	add_instr(t_list **instr, char *op, t_data *data);

//sort
void	sort(t_data *data);
int		sorted(t_stack *stack);

//sort_small
void	sort_three(char id, t_data *data);
void	sort_five(char id, t_data *data);

//sort_big
void	radix_sort(t_data *data);
void	quick_sort_b(t_data *data, int min_idx, int max_idx);
void	quick_sort_a(t_data *data, int min_idx, int max_idx);

#endif