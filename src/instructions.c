/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 07:48:45 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/13 07:48:45 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_instr(t_list *instr)
{

}

void	add_instr(t_list **instr, char *op)
{
	t_list	*new;

	new = ft_lstnew(op);
	if (!new)
	{
		//free data
		error("memory allocation failed", 2);
	}
	ft_lstadd_back(instr, new);
}

void	print_instr(t_list *instr)
{

}