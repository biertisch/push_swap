/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:21:19 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/21 22:21:19 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_indexes(t_stack *head)
{
	int		tmp;

	if (!head)
		return ;
	tmp = head->index;
	while (head->next)
	{
		head->index = head->next->index;
		head = head->next;
	}
	head->index = tmp;
}

static void	rotate_values(t_stack *head)
{
	int		tmp;

	if (!head)
		return ;
	tmp = head->value;
	while (head->next)
	{
		head->value = head->next->value;
		head = head->next;
	}
	head->value = tmp;
}

void	rotate(char id, t_data *data)
{
	t_stack	*stack;

	if (id == 's')
	{
		rotate('a', data);
		rotate('b', data);
		return ;
	}
	stack = general_setup(id, data, "ra", "rb");
	if (!stack || !stack->next)
		return ;
	rotate_values(stack);
	rotate_indexes(stack);
}
