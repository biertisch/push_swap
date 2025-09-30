/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 06:36:10 by beatde-a          #+#    #+#             */
/*   Updated: 2025/09/19 19:05:05 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error_msg(char *msg, t_data *data, char **split)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	free_string_array(split);
	free_data(data);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (1);
	ft_bzero(&data, sizeof(t_data));
	parser(argv + 1, &data);
	sort(&data);
	print_instr(data.instr);
	free_data(&data);
	return (0);
}
