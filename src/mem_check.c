/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:57:16 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/17 15:57:16 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
