/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:01:12 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/12 16:01:12 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	delete_node(t_double_list **node, t_double_list **stack_head)
{
	if (!node || !*node || !stack_head)
		return ;
	if (*stack_head == *node)
		*stack_head = (*node)->next;
	if ((*node)->prev)
		(*node)->prev->next = (*node)->next;
	if ((*node)->next)
		(*node)->next->prev = (*node)->prev;
	free(*node);
	*node = NULL;
}

void	add_node_front(t_double_list **stack, t_double_list *new)
{
	if (!stack || !new)
		return ;
	if (*stack)
		(*stack)->prev = new;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}

void	add_node_back(t_double_list **stack, t_double_list *new)
{
	t_double_list	*tail;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_last_node(*stack);
	tail->next = new;
	new->prev = tail;
}

t_double_list	*create_node(int n)
{
	t_double_list	*new;

	new = malloc(sizeof(t_double_list));
	if (!new)
		return (NULL);
	new->value = n;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
