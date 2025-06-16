/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 06:36:06 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/13 06:36:06 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error(char *s, int n)
{
	ft_printf("Error: %s\n", s);
	exit(n);
}

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

void	free_data(t_data *data)
{

}

void	mem_check_stack(t_double_list *node, t_data *data)
{
	if (!node)
	{
		//free data
		error("memory allocation failed", 2);
	}
}

void	mem_check_str(char *s, char **split)
{
	int	i;
	
	if (!s && !split)
	{
		//free data
		error("memory allocation failed", 2);
	}
}
