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

void	normalize_stack(t_stack **head)
{

}


void	parser(char **argv, t_data *data)
{
	t_stack	*new;
	int		i;
	
	format_input(argv, data);
	validate_input(data->input, data);
	i = 0;
	while (data->input[i])
	{
		new = create_node(ft_atoi(data->input[i]));
		if (!new)
			error_msg("Error: memory allocation failed", data);
		add_node_back(&data->stack_a, new);
		i++;
	}
}
