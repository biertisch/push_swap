/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 06:36:03 by beatde-a          #+#    #+#             */
/*   Updated: 2025/09/19 19:05:29 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	normalize_stack(t_stack *head, t_data *data)
{
	t_stack	*tmp;
	t_stack	*min;
	int		i;

	i = 0;
	while (i < data->size_a)
	{
		min = NULL;
		tmp = head;
		while (tmp)
		{
			if (tmp->index < 0 && (min == NULL || min->value > tmp->value))
				min = tmp;
			tmp = tmp->next;
		}
		if (min)
			min->index = i;
		i++;
	}
}

static int	check_nbr(char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (0);
	while (*s)
		if (!ft_isdigit(*s++))
			return (0);
	return (1);
}

static int	validate_input(char *input, t_stack *stack)
{
	long	n;

	if (!check_nbr(input))
		return (0);
	n = ft_atol(input);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	while (stack)
	{
		if (stack->value == n)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	parser(char **argv, t_data *data)
{
	t_stack	*new;
	char	**split;
	int		i;

	while (*argv)
	{
		split = ft_split(*argv, ' ');
		if (!split || !*split)
			error_msg("Error", data, split);
		i = 0;
		while (split[i])
		{
			if (!validate_input(split[i], data->stack_a))
				error_msg("Error", data, split);
			new = create_node(ft_atoi(split[i]), -1);
			if (!new)
				error_msg("Error: memory allocation failed", data, split);
			add_node_back(&data->stack_a, new);
			data->size_a++;
			i++;
		}
		free_string_array(split);
		argv++;
	}
	normalize_stack(data->stack_a, data);
}
