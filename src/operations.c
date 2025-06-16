/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:39:03 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/12 16:39:03 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_double_list	*filter_and_log(char c, t_data *data, char *op_a, char *op_b)
{
	if (c == 'a')
	{
		add_instr(&(data->instr), op_a);
		return (data->stack_a);
	}
	else if (c == 'b')
	{
		add_instr(&(data->instr), op_b);
		return (data->stack_b);
	}
}

void	swap(char c, t_data *data)
{
	int				tmp;
	t_double_list	*stack;

	if (c == 's')
	{
		swap('a', data);
		swap('b', data);
		return ;
	}
	stack = filter_and_log(c, data, "sa", "sb");
	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

//update size in data
void	push(char c, t_data *data)
{
	t_double_list	*new;
	t_double_list	*from;
	t_double_list	*to;

	if (c == 'a')
	{
		if (!data->stack_b)
			return ;
		from = &data->stack_a;
		to = &data->stack_b;
		add_instr(&(data->instr), "pa");
	}
	else if (c == 'b')
	{
		if (!data->stack_a)
			return ;
		from = &data->stack_b;
		to = &data->stack_a;
		add_instr(&(data->instr), "pb");
	}
	new = create_node((*from)->value);
	mem_check(new, data);
	add_node_front(to, new);
	delete_node(from, from);
}

void	rotate(char c, t_data *data)
{
	t_double_list	*stack;
	int				tmp;

	if (c == 's')
	{
		rotate('a', data);
		rotate('b', data);
		return ;
	}
	stack = filter_and_log(c, data, "ra", "rb");
	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	while (stack->next)
	{
		stack->value = stack->next->value;
		stack = stack->next;
	}
	stack->value = tmp;
}

void	rev_rotate(char c, t_data *data)
{
	t_double_list	*stack;
	int				tmp;

	if (c == 's')
	{
		rev_rotate('a', data);
		rev_rotate('b', data);
		return ;
	}
	stack = filter_and_log(c, data, "rra", "rrb");
	if (!stack || !stack->next)
		return ;
	stack = get_last_node(stack);
	tmp = stack->value;
	while (stack->previous)
	{
		stack->value = stack->previous->value;
		stack = stack->previous;
	}
	stack->value = tmp;
}
