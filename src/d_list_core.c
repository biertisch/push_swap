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

void	delete_node(t_double_list **head)
{
	t_double_list	*tmp;
	
	if (!head || !*head)
		return ;
	tmp = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	free(tmp);
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
