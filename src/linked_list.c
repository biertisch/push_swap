/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:01:12 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/12 16:01:12 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	clear_stack(t_node **stack)
{
	if (!stack || !*stack)
		return ;
	while((*stack)->next)
		clear_stack(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

int	get_stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (stack);
}

t_node	*get_last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	add_node_back(t_node **stack, t_node *new)
{
	t_node	*tail;
	
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

t_node	*create_node(int n)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = n;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
