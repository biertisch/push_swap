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
	t_stack	*tail;

	if (do_both(id, rev_rotate, data))
		return ;
	stack = get_stack(id, data);
	if (!stack || !*stack || !(*stack)->next)
		return ;
	log_instr(id, data, "rra", "rrb");
	tail = get_last_node(*stack);
	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = *stack;
	(*stack)->prev = tail;
	*stack = tail;
}

void	rotate(char id, t_data *data)
{
	t_stack	**stack;
	t_stack	*head;
	t_stack	*tail;

	if (do_both(id, rotate, data))
		return ;
	stack = get_stack(id, data);
	if (!stack || !*stack || !(*stack)->next)
		return ;
	log_instr(id, data, "ra", "rb");
	head = *stack;
	tail = get_last_node(*stack);
	*stack = head->next;
	head->next->prev = NULL;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
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
	t_stack	**src;
	t_stack	**dest;
	t_stack	*node;

	src = get_stack(get_other_id(id), data);
	dest = get_stack(id, data);
	if (!src || !*src || !dest)
		return ;
	log_instr(id, data, "pa", "pb");
	node = *src;
	*src = node->next;
	if (*src)
		(*src)->prev = NULL;
	node->next = *dest;
	if (*dest)
		(*dest)->prev = node;
	node->prev = NULL;
	*dest = node;
}
