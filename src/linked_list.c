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

t_stack	*get_last_node(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
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

void	add_node_front(t_stack **head, t_stack *new)
{
	if (!head || !new)
		return ;
	if (*head)
		(*head)->prev = new;
	new->next = *head;
	*head = new;
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

t_stack	*create_node(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = n;
	new->index = -1;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
