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
	int		size_a;
	int		size_b;
	t_list	*instr;
}			t_data;

//main
int		main(int argc, char **argv);
void	error_msg(char *msg, t_data *data, char **split);

//mem
void	free_split(char **arr);
void	free_list(t_list **instr);
void	free_stack(t_stack **stack);
void	free_data(t_data *data);

//parser
void	parser(char **argv, t_data *data);

//linked_list
t_stack	*create_node(int value, int index);
void	add_node_back(t_stack **head, t_stack *new);
void	delete_first_node(t_stack **head);
t_stack	*get_last_node(t_stack *head);
void	delete_last_node(t_list **head);

//ops
void	push(char id, t_data *data);
void	swap(char id, t_data *data);
void	rotate(char id, t_data *data);
void	rev_rotate(char id, t_data *data);

//ops_utils
void	log_instr(char id, t_data *data, char *instr_a, char *instr_b);
void	update_size(char id, t_data *data);
t_stack	**get_stack(char id, t_data *data);
char	get_other_id(char id);
int		do_both(char id, void (*op)(char, t_data *), t_data *data);

//instr
void	print_instr(t_list *instr);
void	add_instr(t_list **instr, char *op, t_data *data);

//sort
void	sort(t_data *data);
int		sorted(t_stack *stack);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
int		find_position(t_stack *stack, int idx);

//sort_small
void	sort_three(t_data *data);
void	sort_three_b(t_data *data);
void	sort_five(t_data *data);

//quick_sort
void	quick_sort_b(t_data *data, int min_idx, int max_idx);
void	quick_sort_a(t_data *data, int min_idx, int max_idx);

//radix_sort
void	radix_sort(t_data *data);

#endif