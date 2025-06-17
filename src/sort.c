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

t_double_list	**get_stack(char id, t_data *data)
{
	if (id == 'a')
		return (&data->stack_a);
	else
		return (&data->stack_b);
}

void	sort_four_to_five(char id, t_data *data)
{
	t_double_list	**stack;
	char			other;
	unsigned int	size;
	unsigned int	i;

	stack = get_stack(id, data);
	size = get_stack_size(*stack);
	if (id == 'a')
		other = 'b';
	else
		other = 'a';
	i = 0;
	while (i < size - 3)
	{
		if (is_smallest((*stack)->value, *stack))
		{
			push(other, data);
			i++;
		}
		else
			rotate(id, data);
	}
	sort_three(id, data);
	while (i--)
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
	else
		//scalable sorting algorithm
}
