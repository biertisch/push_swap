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

void	arr_to_stack(t_double_list *stack, int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (array[j] == stack->value)
			{
				stack->index = j;
				break ;
			}
			j++;
		}
		stack = stack->next;
		i++;
	}
}

void	stack_to_arr(t_double_list *stack, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size && stack)
	{
		array[i] = stack->value;
		i++;
		stack = stack->next;
	}
}

void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int swapped;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		swapped = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				int_swap(&array[j], &array[j + 1]);
				swapped = 1;
			}			
			j++;
		}
		i++;
		if (!swapped)
			break;
	}
}

void	normalize_stack(t_double_list *stack, t_data *data)
{
	int				*tmp;
	int				size;

	size = get_stack_size(stack);
	tmp = malloc(size * sizeof(int));
	if (!tmp)
		error("memory allocation failed", 2, data);
	stack_to_arr(stack, tmp, size);
	bubble_sort(tmp, size);
	arr_to_stack(stack, tmp, size);
	free (tmp);
}

void	radix(t_data *data)
{
	normalize_stack(data->stack_a, data);
}