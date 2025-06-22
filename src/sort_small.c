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
	int min_position;

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

static void	bring_min(char id, t_data *data)
{
	t_stack	*stack;
	int		size;
	int		min_position;

	stack = get_stack(id, data);
	size = get_stack_size(stack);
	min_position = find_min(stack);
	if (min_position < size - min_position)
		while (min_position--)
			rotate(id, data);
	else
		while (min_position++ < size)
			rev_rotate(id, data);
}

void	sort_five(char id, t_data *data)
{
	char	other;
	int		count;
	int		i;

	i = 0;
	count = get_stack_size(get_stack(id, data)) - 3;
	if (id == 'a')
		other = 'b';
	else
		other = 'a';
	while (i++ < count)
	{
		bring_min(id, data);
		push(other, data);
	}
	sort_three(id, data);
	while (count--)
		push(id, data);
}

void	sort_three(char id, t_data *data)
{
	t_stack	*stack;

	stack = get_stack(id, data);
	if (!stack || !stack->next)
		return ;
	if (stack->index == data->size - 1)
		rotate(id, data);
	else if (stack->next->index == data->size - 1)
		rev_rotate(id, data);
	if (stack->index > stack->next->index)
		swap(id, data);
}
