/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:02:07 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/18 21:02:07 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_first_below(t_stack *stack, int pivot)
{
	int	first;

	first = 0;
	while (stack)
	{
		if (stack->index < pivot)
			return (first);
		first++;
		stack = stack->next;
	}
	return (-1);
}

static int	find_last_below(t_stack *stack, int pivot)
{
	t_stack	*tail;
	int		last;

	tail = get_last_node(stack);
	last = 0;
	while (tail)
	{
		if (tail->index < pivot)
			return (last);
		last++;
		tail = tail->prev;
	}
	return (-1);
}

static void	push_below_pivot(t_data *data, int pivot)
{
	int	first;
	int	last;

	if (!data->stack_a)
		return ;
	first = find_first_below(data->stack_a, pivot);
	last = find_last_below(data->stack_a, pivot);
	if (first == -1 && last == -1)
		return ;
	if (first <= last)
		while (first--)
			rotate('a', data);
	else
		while (last-- >= 0)
			rev_rotate('a', data);
	push('b', data);
}

static int	count_below_pivot(t_data *data, int pivot)
{
	t_stack	*stack;
	int		count;

	stack = data->stack_a;
	count = 0;
	while (stack)
	{
		if (stack->index < pivot)
			count++;
		stack = stack->next;
	}
	return (count);
}

void	quick_sort_a(t_data *data, int min_idx, int max_idx)
{
	int	pivot;
	int	count;

	if (!data->stack_a || min_idx >= max_idx || sorted(data->stack_a))
		return ;
	if (data->size_a <= 3)
	{
		sort_three(data);
		return ;
	}
	pivot = (min_idx + max_idx) / 2;
	count = count_below_pivot(data, pivot);
	if (!count)
		return ;
	while (count--)
		push_below_pivot(data, pivot);
	quick_sort_a(data, pivot, max_idx);
	quick_sort_b(data, min_idx, pivot - 1);
}
