/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:58:08 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/17 15:58:08 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_input(char **input)
{
	int	i;

	i = 0;
	if (!input || *input)
		return ;
	while (input[i])
		free(input[i++]);
	free(input);
}

void	free_instr(t_list **instr)
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

void	free_stack(t_double_list **stack)
{
	t_double_list	*tmp;
	
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
	free_instr(&data->instr);
	free_input(data->input);
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->instr = NULL;
	data->input = NULL;
	data->size_a = 0;
	data->size_b = 0;
}
