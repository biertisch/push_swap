/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ops.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:22:25 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/21 22:22:25 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rev_rotate(char id, t_data *data)
{
	t_stack	**stack;
	t_stack	*last;

	if (do_both(id, rev_rotate, data))
		return ;
	stack = get_stack(id, data);
	if (!stack || !*stack || !(*stack)->next)
		return ;
	log_instr(id, data, "rra", "rrb");
	last = get_last_node(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rotate(char id, t_data *data)
{
	t_stack	**stack;
	t_stack	*first;
	t_stack	*last;

	if (do_both(id, rotate, data))
		return ;
	stack = get_stack(id, data);
	if (!stack || !*stack || !(*stack)->next)
		return ;
	log_instr(id, data, "ra", "rb");
	first = *stack;
	last = get_last_node(*stack);
	*stack = first->next;
	first->next->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	swap(char id, t_data *data)
{
	t_stack	**stack;
	t_stack	*first;
	t_stack	*second;

	if (do_both(id, swap, data))
		return ;
	stack = get_stack(id, data);
	if (!stack || !*stack || !(*stack)->next)
		return ;
	log_instr(id, data, "sa", "sb");
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	push(char id, t_data *data)
{
	t_stack		**from;
	t_stack		**to;
	t_stack		*node;

	if (!data)
		return ;
	from = get_stack(get_other_id(id), data);
	to = get_stack(id, data);
	log_instr(id, data, "pa", "pb");
	if (!from || !*from || !to)
		return ;
	node = *from;
	*from = node->next;
	if (*from)
		(*from)->prev = NULL;
	node->next = *to;
	if (*to)
		(*to)->prev = node;
	node->prev = NULL;
	*to = node;
}
