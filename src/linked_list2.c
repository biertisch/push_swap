/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:59:30 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/17 15:59:30 by beatde-a         ###   ########.fr       */
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
	free(last->content);
	free(last);
	if (prev)
		prev->next = NULL;
	else
		*head = NULL;
}

int	get_stack_size(t_stack *head)
{
	int	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}
