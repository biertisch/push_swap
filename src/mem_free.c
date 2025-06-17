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

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
	split = NULL;
}

//check libft- lstclear
void	free_instr(t_list **instr)
{

}

void	free_stack(t_double_list **stack)
{
	if (!stack || !*stack)
		return ;
	while ((*stack)->next)
		free_stack(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

void	free_data(t_data *data)
{

}
