/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:07:53 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/24 16:07:53 by beatde-a         ###   ########.fr       */
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
	int	max_bits;
	int	bit;
	int	i;
	int	full_size;

	if (!data || !data->stack_a)
		return ;
	max_bits = find_bits(data->size_a - 1);
	bit = 0;
	full_size = data->size_a;
	while (bit < max_bits)
	{
		i = 0;
		while (i++ < full_size)
		{
			if (((data->stack_a->index >> bit) & 1) == 0)
				push('b', data);
			else
				rotate('a', data);
		}
		while (data->stack_b)
			push('a', data);
		bit++;
	}
}
