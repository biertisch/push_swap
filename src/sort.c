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

int	find_position(t_stack *stack, int idx)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->index == idx)
			return (count);
		count++;
		stack = stack->next;
	}
	return (-1);
}

int	find_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (-1);
	max = stack->index;
	while (stack)
	{
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (-1);
	min = stack->index;
	while (stack)
	{
		if (min > stack->index)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

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
	if (!data || !data->stack_a || data->size_a == 1 || sorted(data->stack_a))
		return ;
	if (data->size_a <= 3)
		sort_three(data);
	else if (data->size_a <= 5)
		sort_five(data);
	else if (data->size_a <= 150)
		quick_sort_a(data, 0, data->size_a - 1);
	else
		radix_sort(data);
}
