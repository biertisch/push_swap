/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:41:38 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/21 10:41:38 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
		free_input(tmp);
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
		free_input(tmp);
		i++;
	}
	return (count);
}


void	format_input(char **raw, t_data *data)
{
	int	count;
	
	count = split_count(raw, data);
	data->input = malloc(sizeof(char *) * (count + 1));
	if (!data->input)
		error_msg("Error: memory allocation failed", data);
	split_dup(raw, data->input, data);
}