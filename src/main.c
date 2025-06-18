/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 06:36:10 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/13 06:36:10 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		error("invalid input", 1, NULL);
	initiate(argv + 1, &data);
	sort(&data);
	print_instr(data.instr);
	free_data(&data);
	return (0);
}
