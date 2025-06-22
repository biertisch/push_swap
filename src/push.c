/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:19:27 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/21 22:19:27 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	push_setup(char id, t_data *data, t_stack **from, t_stack **to)
{
	if (!data || !from || !*from || !to || !*to)
		return (0);
	if (id == 'a')
	{
		if (!data->stack_b)
			return (0);
		*from = data->stack_b;
		*to = data->stack_a;
		add_instr(&(data->instr), "pa", data);
	}
	else if (id == 'b')
	{
		if (!data->stack_a)
			return (0);
		*from = data->stack_a;
		*to = data->stack_b;
		add_instr(&(data->instr), "pb", data);
	}
	return (1);
}

void	push(char id, t_data *data)
{
	t_stack	*new;
	t_stack	*from;
	t_stack	*to;

	if (!push_setup(id, data, &from, &to))
		return ;
	new = create_node(from->value, from->index);
	if (!new)
		error_msg("Error: memory allocation failed", data);
	add_node_front(&to, new);
	delete_first_node(&from);
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
