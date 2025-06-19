/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:01:16 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/17 16:01:16 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(char id, t_data *data)
{
	t_double_list	*new;
	t_double_list	*from;
	t_double_list	*to;

	if (!push_setup(id, data, &from, &to))
		return ;
	new = create_node(from->value);
	if (!new)
		error("memory allocation failed", 2, data);
	add_node_front(&to, new);
	delete_node(&from);
	if (id == 'a')
	{
		data->stack_a = to;
		data->stack_b = from;
	}
	else
	{
		data->stack_a = from;
		data->stack_b = to;
	}
}

void	swap(char id, t_data *data)
{
	int				tmp;
	t_double_list	*stack;

	if (id == 's')
	{
		swap('a', data);
		swap('b', data);
		return ;
	}
	stack = general_setup(id, data, "sa", "sb");
	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	rotate(char id, t_data *data)
{
	t_double_list	*stack;
	int				tmp;

	if (id == 's')
	{
		rotate('a', data);
		rotate('b', data);
		return ;
	}
	stack = general_setup(id, data, "ra", "rb");
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

void	rev_rotate(char id, t_data *data)
{
	t_double_list	*stack;
	int				tmp;

	if (id == 's')
	{
		rev_rotate('a', data);
		rev_rotate('b', data);
		return ;
	}
	stack = general_setup(id, data, "rra", "rrb");
	if (!stack || !stack->next)
		return ;
	stack = get_last_node(stack);
	tmp = stack->value;
	while (stack->prev)
	{
		stack->value = stack->prev->value;
		stack = stack->prev;
	}
	stack->value = tmp;
}
