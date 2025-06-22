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

int		main(int argc, char **argv);
void	error_msg(char *msg, t_data *data);

//mem
void	free_split(char **arr);
void	free_list(t_list **instr);
void	free_stack(t_stack **stack);
void	free_data(t_data *data);

//parser
void	parser(char **argv, t_data *data);
void	validate_input(char **input, t_data *data);

//linked_list
t_stack	*create_node(int value, int index);
void	add_node_back(t_stack **head, t_stack *new);
void	add_node_front(t_stack **head, t_stack *new);
void	delete_first_node(t_stack **head);
t_stack	*get_last_node(t_stack *head);
int		get_stack_size(t_stack *head);
void	delete_last_node(t_list **head);

//ops
void	swap(char id, t_data *data);
void	rotate(char id, t_data *data);
void	rev_rotate(char id, t_data *data);
void	push(char id, t_data *data);
t_stack	*general_setup(char id, t_data *data, char *op_a, char *op_b);

//instr
void	print_instr(t_list *instr);
void	add_instr(t_list **instr, char *op, t_data *data);

//sort
void	sort(t_data *data);
int		sorted(t_stack *stack);
t_stack	*get_stack(char id, t_data *data);
void	sort_three(char id, t_data *data);
void	sort_five(char id, t_data *data);

#endif