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

void	sort_three_b(t_data *data)
{
	int	min;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	min = find_min(data->stack_b);
	if (data->stack_b->index == min)
		rotate('b', data);
	else if (data->stack_b->next->index == min)
		rev_rotate('b', data);
	if (data->stack_b->index < data->stack_b->next->index)
		swap('b', data);
}

static void	push_min(t_data *data)
{
	int	min_position;

	min_position = find_position(data->stack_a, find_min(data->stack_a));
	if (min_position <= data->size_a / 2)
		while (min_position--)
			rotate('a', data);
	else
		while (min_position++ < data->size_a)
			rev_rotate('a', data);
	push('b', data);
}

void	sort_five(t_data *data)
{
	int	count;
	int	i;

	if (!data->stack_a || sorted(data->stack_a))
		return ;
	count = data->size_a - 3;
	i = 0;
	while (i++ < count)
		push_min(data);
	sort_three(data);
	while (count--)
		push('a', data);
}

void	sort_three(t_data *data)
{
	int	max;

	if (!data->stack_a || !data->stack_a->next || sorted(data->stack_a))
		return ;
	max = find_max(data->stack_a);
	if (data->stack_a->index == max)
		rotate('a', data);
	else if (data->stack_a->next->index == max)
		rev_rotate('a', data);
	if (data->stack_a->index > data->stack_a->next->index)
		swap('a', data);
}
