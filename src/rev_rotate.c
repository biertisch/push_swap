/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:22:25 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/21 22:22:25 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rev_rotate_indexes(t_stack *tail)
{
	int	tmp;

	if (!tail)
		return ;
	tmp = tail->index;
	while (tail->prev)
	{
		tail->index = tail->prev->index;
		tail = tail->prev;
	}
	tail->index = tmp;
}

static void	rev_rotate_values(t_stack *tail)
{
	int	tmp;

	if (!tail)
		return ;
	tmp = tail->value;
	while (tail->prev)
	{
		tail->value = tail->prev->value;
		tail = tail->prev;
	}
	tail->value = tmp;
}

void	rev_rotate(char id, t_data *data)
{
	t_stack	*stack;
	t_stack	*tail;

	if (id == 's')
	{
		rev_rotate('a', data);
		rev_rotate('b', data);
		return ;
	}
	stack = general_setup(id, data, "rra", "rrb");
	if (!stack || !stack->next)
		return ;
	tail = get_last_node(stack);
	rev_rotate_values(tail);
	rev_rotate_indexes(tail);
}
