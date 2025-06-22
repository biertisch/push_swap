/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:58:08 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/17 15:58:08 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr || !*arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_list(t_list **instr)
{
	t_list	*tmp;

	if (!instr || !*instr)
		return ;
	while (*instr)
	{
		tmp = (*instr)->next;
		free((*instr)->content);
		free(*instr);
		*instr = tmp;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_stack(&data->stack_a);
	free_stack(&data->stack_b);
	free_list(&data->instr);
	free_split(data->input);
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->size = 0;
	data->instr = NULL;
	data->input = NULL;
}
