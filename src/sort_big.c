/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:02:07 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/18 21:02:07 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_bits(int n)
{
	int	max_bits;

	max_bits = 0;
	while (n)
	{
		n >>= 1;
		max_bits++;
	}
	return (max_bits);
}

void	radix_sort(t_data *data)
{
	int		max_bits;
	int		size;
	int		i;
	int		j;

	if (!data || !data->stack_a)
		return ;
	max_bits = find_bits(data->size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = get_stack_size(data->stack_a);
		while (j < size)
		{
			if ((data->stack_a->index >> i) & 1)
				rotate('a', data);
			else
				push('b', data);
			j++;
		}
		while (data->stack_b)
			push('a', data);
		i++;
	}
}
