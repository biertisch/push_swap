/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:19:27 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/21 22:19:27 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	get_other_id(char id)
{
	if (id == 'a')
		return ('b');
	return ('a');
}

int	do_both(char id, void (*op)(char, t_data *), t_data *data)
{
	if (id == 's')
	{
		op('a', data);
		op('b', data);
		return (1);
	}
	return (0);
}

t_stack	**get_stack(char id, t_data *data)
{
	if (id == 'a')
		return (&data->stack_a);
	return (&data->stack_b);
}

void	log_instr(char id, t_data *data, char *instr_a, char *instr_b)
{
	if (id == 'a')
		add_instr(&(data->instr), instr_a, data);
	else
		add_instr(&(data->instr), instr_b, data);
}
