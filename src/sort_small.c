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

static void	bring_min(char id, t_stack *stack, t_data *data)
{
	int		size;
	int		min_position;

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
	t_stack	**stack;
	int		count;
	int		i;

	stack = get_stack(id, data);	
	count = get_stack_size(*stack) - 3;
	i = 0;
	while (i++ < count)
	{
		bring_min(id, *stack, data);
		push(get_other_id(id), data);
	}
	sort_three(id, data);
	while (count--)
		push(id, data);
}

void	sort_three(char id, t_data *data)
{
	t_stack	**stack;
	int		size;
	
	stack = get_stack(id, data);
	size = get_stack_size(*stack);
	if ((*stack)->index == size - 1)
		rotate(id, data);
	else if ((*stack)->next->index == size - 1)
		rev_rotate(id, data);
	if ((*stack)->index > (*stack)->next->index)
		swap(id, data);
}
