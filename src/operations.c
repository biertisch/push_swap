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

void	swap(int c, t_data *stacks)
{
	int	temp;
	t_node *stack;
	
	if (c == a)
		stack = stacks->stack_a;
	else if (c == b)
		stack = stacks->stack_b;	
	else if (c == s)
	{
		swap(a, stacks);
		swap(b, stacks);
	}
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
}
