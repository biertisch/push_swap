/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:01:12 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/12 16:01:12 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	delete_last_node(t_list **head)
{
	t_list	*last;
	t_list	*prev;

	if (!head || !*head)
		return ;
	last = *head;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	free(last);
	if (prev)
		prev->next = NULL;
	else
		*head = NULL;
}

t_stack	*get_last_node(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head && head->next)
		head = head->next;
	return (head);
}

void	delete_first_node(t_stack **head)
{
	t_stack	*tmp;

	if (!head || !*head)
		return ;
	tmp = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	free(tmp);
}

void	add_node_back(t_stack **head, t_stack *new)
{
	t_stack	*tail;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	tail = get_last_node(*head);
	tail->next = new;
	new->prev = tail;
}

t_stack	*create_node(int value, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = index;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
