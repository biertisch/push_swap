/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 06:36:03 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/13 06:36:03 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	duplicate_check(t_double_list *stack, t_data *data)
{
	t_double_list	*current;
	t_double_list	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				error("invalid input", 1, data);
			checker = checker->next;
		}
		current = current->next;
	}
}

void	parser(t_data *data)
{
	t_double_list	*new;
	int				i;
	int				j;

	i = 0;
	while (data->input[i])
	{
		new = create_node(ft_atoi(data->input[i]));
		if (!new)
			error("memory allocation failed", 2, data);
		add_node_back(&data->stack_a, new);
		data->size_a++;
		j = 0;
		while (data->input[i][j])
		{
			if (!ft_isdigit(data->input[i][j]) && data->input[i][j] != ' '
				&& data->input[i][j] != '+' && data->input[i][j] != '-')
				error("invalid input", 1, data);
			j++;
		}
		i++;
	}
}

void	initiate(char **raw_input, t_data *data)
{
	if (!raw_input[1])
	{
		data->input = ft_split(raw_input[0], ' ');
		if (!data->input)
			error("memory allocation failed", 2, data);
	}
	else
		data->input = raw_input;
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	data->instr = NULL;
	parser(data);
	duplicate_check(data->stack_a, data);
}
