/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:01:51 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/18 21:01:51 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_min(t_stack *stack)
{
	int	i;
	int	min;
	int	min_position;

	if (!stack)
		return (0);
	i = 0;
	min = stack->index;
	min_position = 0;
	while (stack)
	{
		if (stack->index < min)
		{
			min = stack->index;
			min_position = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_position);
}

static void	bring_min(t_data *data)
{
	int		size;
	int		min_position;

	size = get_stack_size(data->stack_a);
	min_position = find_min(data->stack_a);
	if (min_position < size - min_position)
		while (min_position--)
			rotate('a', data);
	else
		while (min_position++ < size)
			rev_rotate('a', data);
}

void	sort_five(t_data *data)
{
	int		count;
	int		i;

	if (!data || !data->stack_a)
		return ;
	i = 0;
	count = get_stack_size(data->stack_a) - 3;
	while (i++ < count)
	{
		bring_min(data);
		push('b', data);
	}
	sort_three(data);
	while (count--)
		push('a', data);
}

void	sort_three(t_data *data)
{
	if (!data || !data->stack_a)
		return ;
	if (data->stack_a->index == data->size - 1)
		rotate('a', data);
	else if (data->stack_a->next->index == data->size - 1)
		rev_rotate('a', data);
	if (data->stack_a->index > data->stack_a->next->index)
		swap('a', data);
}
