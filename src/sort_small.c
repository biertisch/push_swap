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

int	get_min_index(t_double_list *stack)
{
	int	i;
	int	min;
	int	index;

	if (!stack)
		return (0);
	i = 0;
	min = stack->value;
	index = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			index = i;
		}			
		stack = stack->next;
		i++;
	}
	return (index);
}

void	min_to_top(char id, t_data *data)
{
	t_double_list	**stack;
	int				index;
	int				size;

	stack = get_stack(id, data);
	index = get_min_index(*stack);
	size = get_stack_size(*stack);
	if (index <= size / 2)
		while (index--)
			rotate(id, data);
	else
		while(index++ < size)
			rev_rotate(id, data);
}

void	sort_four_to_five(char id, t_data *data)
{
	char			other;
	unsigned int	count;
	unsigned int	i;

	i = 0;	
	count = get_stack_size(*get_stack(id, data)) - 3;
	if (id == 'a')
		other = 'b';
	else
		other = 'a';
	while (i++ < count)
	{
		min_to_top(id, data);
		push(other, data);
	}
	sort_three(id, data);
	while(count--)
		push(id, data);
}

void	sort_three(char id, t_data *data)
{
	t_double_list	**stack;
	int				a;
	int				b;
	int				c;

	stack = get_stack(id, data);
	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b < c && a < c)
		swap(id, data);
	else if (a > b && b > c)
	{
		swap(id, data);
		rev_rotate(id, data);
	}
	else if (a > b && b < c && a > c)
		rotate(id, data);
	else if (a < b && b > c && a < c)
	{
		swap(id, data);
		rotate(id, data);
	}
	else if (a < b && b > c && a > c)
		rev_rotate(id, data);
}

void	sort_two(char id, t_data *data)
{
	t_double_list	**stack;

	stack = get_stack(id, data);
	if ((*stack)->value > (*stack)->next->value)
		swap(id, data);
}
