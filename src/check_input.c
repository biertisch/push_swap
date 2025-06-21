/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:41:47 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/21 10:41:47 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_nbr(char	*s)
{
	int	i;
	
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_dup(long n, char **input)
{
	int	i;
	
	i = 1;
	while (input[i])
	{
		if (n == ft_atoi(input[i]))
			return (0);
		i++;
	}
	return (1);
}

void	validate_input(char **input, t_data *data)
{
	int		i;
	long	n;

	i = 0;
	while (input[i])
	{
		if (!check_nbr(input[i]))
			error_msg("Error", data);
		n = ft_atoi(input[i]);
		if (n < INT_MIN || n > INT_MAX)
			error_msg("Error", data);
		if (!check_dup(tmp, input + i))
			error_msg("Error", data);
		i++;
	}
}
