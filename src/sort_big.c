/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:02:07 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/18 21:02:07 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


static int	find_first(t_stack *stack, int pivot)
{
	int count;

	count = 0;
	while (stack)
	{
		if (stack->index < pivot)
			return (count);
		count++;
		stack = stack->next;
	}
	return (-1);
}

static int	find_last(t_stack *stack, int pivot)
{
	int count;
	t_stack *tail; 

	tail = get_last_node(stack);
	count = 0;
	while (tail)
	{
		if (tail->index < pivot)
			return (count);
		count++;
		tail = tail->prev;
	}
	return (-1);
}


static void	greedy_rotate(t_data *data, t_stack *stack, char id, int pivot)
{
	int		first;
	int		last;

	first = find_first(stack, pivot);
	last = find_last(stack, pivot);
	if (first == -1 && last == -1)
		return ;
	if (last == -1 || first <= last)
		while (first--)
			rotate(id, data);
	else
		while(last--)
			rev_rotate(id, data);
}

void	quick_sort_a(t_data *data, int min_idx, int max_idx)
{
	int	pivot;
	int	count;

	if (max_idx - min_idx <= 2)
	{
		sort_three('a', data);
		return ;
	}
	pivot = (min_idx + max_idx) / 2;
	count = pivot - min_idx +1;
	while (count)
	{
		if (data->stack_a->index < pivot)
		{
			push('b', data);
			count--;
		}
		else
			greedy_rotate(data, data->stack_a, 'a', pivot);
	}
	quick_sort_a(data, pivot, max_idx);
	quick_sort_b(data, min_idx, pivot - 1);
	while (data->stack_b)
		push_back(data);
}

void	quick_sort_b(t_data *data, int min_idx, int max_idx)
{
	int	pivot;
	int	count;
	
	if (max_idx - min_idx <= 2)
	{
		sort_three('b', data);
		while (data->stack_b)
			push('a', data);
		return ;
	}
	pivot = (min_idx + max_idx) / 2;
	count = max_idx - pivot;
	while (count)
	{
		if (data->stack_b->index >= pivot)
		{
			push('a', data);
			count--;
		}
		else
			greedy_rotate(data, data->stack_b, 'b', pivot);
	}
	quick_sort_a(data, pivot, max_idx);
	quick_sort_b(data, min_idx, pivot - 1);
	while (data->stack_b)
		push('a', data);
}

//RADIX SORT
static int	find_bits(int n)
{
	int	max_bits;

	max_bits = 0;
	while (n)
	{
		n >>= 1;
		max_bits++;
	}
	return (max_bits);
}

void	radix_sort(t_data *data)
{
	int		max_bits;
	int		bit;
	int		i;
	int		size;

	if (!data || !data->stack_a)
		return ;
	max_bits = find_bits(data->size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		size = get_stack_size(data->stack_a);
		i = 0;
		while (i++ < size)
		{
			if (((data->stack_a->index >> bit) & 1) == 0)
				push('b', data);
			else
				rotate('a', data);
		}
		while (data->stack_b)
			push('a', data);
		bit++;
	}
}
