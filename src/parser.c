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

static void	normalize_stack(t_stack *head, t_data *data)
{
	t_stack	*tmp;
	t_stack	*min;
	int		i;

	i = 0;
	while (i < data->size)
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

static void	split_dup(char **src, char **dest, t_data *data)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	while (*src)
	{
		tmp = ft_split(*src, ' ');
		if (!tmp)
			error_msg("Error: memory allocation failed", data);
		j = 0;
		while (tmp[j])
		{
			dest[i] = ft_strdup(tmp[j]);
			if (!dest[i])
				error_msg("Error: memory allocation failed", data);
			i++;
			j++;
		}
		free_split(tmp);
		src++;
	}
	dest[i] = NULL;
}

static int	split_count(char **split, t_data *data)
{
	char	**tmp;
	int		i;
	int		j;
	int		count;

	count = 0;
	i = 0;
	while (split[i])
	{
		tmp = ft_split(split[i], ' ');
		if (!tmp)
			error_msg("Error: memory allocation failed", data);
		j = 0;
		while (tmp[j])
			j++;
		count += j;
		free_split(tmp);
		i++;
	}
	return (count);
}

static void	format_input(char **raw, t_data *data)
{
	int	count;

	count = split_count(raw, data);
	data->input = malloc(sizeof(char *) * (count + 1));
	if (!data->input)
		error_msg("Error: memory allocation failed", data);
	split_dup(raw, data->input, data);
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
		new = create_node(ft_atoi(data->input[i]), -1);
		if (!new)
			error_msg("Error: memory allocation failed", data);
		add_node_back(&data->stack_a, new);
		i++;
	}
	data->size = i;
	normalize_stack(data->stack_a, data);
}
