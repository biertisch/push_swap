/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:19:24 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/21 22:19:24 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*general_setup(char id, t_data *data, char *op_a, char *op_b)
{
	if (id == 'a')
	{
		add_instr(&(data->instr), op_a, data);
		return (data->stack_a);
	}
	else
	{
		add_instr(&(data->instr), op_b, data);
		return (data->stack_b);
	}
}

static void	int_swap(int *x, int *y)
{
	int	tmp;

	if (!x || !y)
		return ;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	swap(char id, t_data *data)
{
	t_stack	*stack;

	if (id == 's')
	{
		swap('a', data);
		swap('b', data);
		return ;
	}
	stack = general_setup(id, data, "sa", "sb");
	if (!stack || !stack->next)
		return ;
	int_swap(&stack->value, &stack->next->value);
	int_swap(&stack->index, &stack->next->index);
}
