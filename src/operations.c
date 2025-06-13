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

//3 - implement with a way to apply and log operations: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
//4 - optimize (no repeated/redundant operations)

void	swap(char c, t_data *data)
{
	int				temp;
	t_double_list	*stack;
	
	if (c == 'a')
	{
		stack = data->stack_a;
		add_instr(&(data->instr), "sa");
	}
	else if (c == 'b')
	{
		stack = data->stack_b;
		add_instr(&(data->instr), "sb");
	}
	else if (c == 's')
	{
		swap(a, stacks);
		swap(b, stacks);
	}
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
}
