/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:01:19 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/17 16:01:19 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	int_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp; 
}

t_double_list	*general_setup(char id, t_data *data, char *op_a, char *op_b)
{
	if (id == 'a')
	{
		add_instr(&(data->instr), op_a, data);
		return (data->stack_a);
	}
	else if (id == 'b')
	{
		add_instr(&(data->instr), op_b, data);
		return (data->stack_b);
	}
	return (NULL);
}

int	push_setup(char id, t_data *data, t_double_list **from, t_double_list **to)
{
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
