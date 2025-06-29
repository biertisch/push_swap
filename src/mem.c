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

	if (!arr || !*arr)
		return ;
	i = 0;
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
		tmp = *instr;
		*instr = (*instr)->next;
		free(tmp);
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_stack(&data->stack_a);
	free_stack(&data->stack_b);
	free_list(&data->instr);
	ft_bzero(data, sizeof(t_data));
}
