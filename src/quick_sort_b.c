/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:56:03 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/24 15:56:03 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_max_above(t_stack *stack, int pivot, int max_idx)
{
	int	max;
	
	max = -1; 
	while (stack)
	{
		if (stack->index > max && stack->index >= pivot && stack->index <= max_idx)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

static int	push_above_pivot(t_data *data, int pivot, int max_idx)
{
	int	size;
	int	max;
	int	max_position;
	int	rotations;

	if (!data->stack_b)
		return (0);
	size = get_stack_size(data->stack_b);
	max = find_max_above(data->stack_b, pivot, max_idx);
	if (max < 0)
		return (0);
	max_position = find_position(data->stack_b, max);
	rotations = 0;
	if (max_position <= size / 2)
	{
		while (max_position--)
		{	
			rotate('b', data);
			rotations++;
		}
	}
	else
		while(max_position++ < size)
			rev_rotate('b', data);
	push('a', data);
	return (rotations);
}

static int	count_above_pivot(t_data *data, int pivot)
{
	t_stack	*stack;
	int		count;

	stack = data->stack_b;
	count = 0;
	while (stack)
	{
		if (stack->index >= pivot)
			count++;
		stack = stack->next;
	}
	return (count);
}

void	quick_sort_b(t_data *data, int min_idx, int max_idx)
{
	int	pivot;
	int	count;
	int	rotations;
	
	if (!data->stack_b || min_idx > max_idx)
		return ;
	if (get_stack_size(data->stack_b) <= 3)
	{
		sort_three_b(data);
		while (data->stack_b)
			push('a', data);
		return ;
	}
	pivot = (min_idx + max_idx) / 2;
	count = count_above_pivot(data, pivot);
	if (!count)
		return ;
	rotations = 0;
	while (count--)
		rotations += push_above_pivot(data, pivot, max_idx);
	while (!sorted(data->stack_a) && rotations--)
		rev_rotate('b', data);
	quick_sort_a(data, pivot, max_idx);
	quick_sort_b(data, min_idx, pivot - 1);
}
