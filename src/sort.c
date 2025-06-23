/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 08:07:06 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/13 08:07:06 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sorted(t_stack *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort(t_data *data)
{
	if (!data || !data->stack_a || data->size == 1 || sorted(data->stack_a))
		return ;
	if (data->size <= 3)
		sort_three(data);
	else if (data->size <= 5)
		sort_five(data);
	else
		radix_sort(data);
}
