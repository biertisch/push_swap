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

int	get_min_index(t_double_list *stack)
{
	int	i;
	int	min;
	int	index;

	min = stack->value;
	index = 0;
	while (stack)
	{
		if (min > stack->value)
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

t_double_list	**get_stack(char id, t_data *data)
{
	if (id == 'a')
		return (&data->stack_a);
	else
		return (&data->stack_b);
}

void	sort_four_to_five(char id, t_data *data)
{
	char			other;
	unsigned int	count;
	
	count = get_stack_size(*get_stack(id, data)) - 3;
	if (id == 'a')
		other = 'b';
	else
		other = 'a';
	while (count--)
	{
		min_to_top(id, data);
		push(other, data);
	}
	sort_three(id, data);
	while(++count < 3)
		push(id, data);
}

void	sort_three(char id, t_data *data)
{
	t_double_list	**stack;
	int				a;
	int				b;
	int				c;

	stack = get_stack(id, data);
	while (1)
	{
		a = (*stack)->value;
		b = (*stack)->next->value;
		c = (*stack)->next->next->value;
		if (a > b && a < c)
			swap(id, data);
		else if (a > b && a > c)
			rotate(id, data);
		else if (a < b && b > c)
			rev_rotate(id, data);
		else
			break ;
	}
}

void	sort_two(char id, t_data *data)
{
	t_double_list	**stack;

	stack = get_stack(id, data);
	if ((*stack)->value > (*stack)->next->value)
		swap(id, data);
}

void	sort(t_data *data)
{
	if (data->size_a <= 1)
		return ;
	else if (data->size_a == 2)
		sort_two('a', data);
	else if (data->size_a == 3)
		sort_three('a', data);
	else if (data->size_a <= 5)
		sort_four_to_five('a', data);
	//else
		//scalable sorting algorithm
}
