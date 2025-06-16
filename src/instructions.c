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

//move to memory.c
void	free_instr(t_list *instr)
{

}
char	*combine_ops(char *last_op, char *op)
{
	if ((ft_strncmp(last_op, "sa", 2) == 0 && ft_strncmp(op, "sb", 2) == 0)
		|| (ft_strncmp(last_op, "sb", 2) == 0 && ft_strncmp(op, "sa", 2) == 0))
		return ("ss");
	if ((ft_strncmp(last_op, "ra", 2) == 0 && ft_strncmp(op, "rb", 2) == 0)
		|| (ft_strncmp(last_op, "rb", 2) == 0 && ft_strncmp(op, "ra", 2) == 0))
		return ("rr");
	if ((ft_strncmp(last_op, "rra", 3) == 0 && ft_strncmp(op, "rrb", 3) == 0)
		|| (ft_strncmp(last_op, "rrb", 3) == 0 && ft_strncmp(op, "rra", 3) == 0))
		return ("rrr");
	return (NULL);
}

int	cancelling_ops(char *last_op, char *op)
{
	return ((ft_strncmp(last_op, "pa", 2) == 0 && ft_strncmp(op, "pb", 2) == 0)
		|| (ft_strncmp(last_op, "pb", 2) == 0 && ft_strncmp(op, "pa", 2) == 0)
		|| (ft_strncmp(last_op, "ra", 2) == 0 && ft_strncmp(op, "rra", 3) == 0)
		|| (ft_strncmp(last_op, "rra", 3) == 0 && ft_strncmp(op, "ra", 2) == 0)
		|| (ft_strncmp(last_op, "rb", 2) == 0 && ft_strncmp(op, "rrb", 3) == 0)
		|| (ft_strncmp(last_op, "rrb", 3) == 0 && ft_strncmp(op, "rb", 3) == 0)
		|| (ft_strncmp(last_op, "sa", 2) == 0 && ft_strncmp(op, "sa", 2) == 0)
		|| (ft_strncmp(last_op, "sb", 2) == 0 && ft_strncmp(op, "sb", 2) == 0)
		|| (ft_strncmp(last_op, "ss", 2) == 0 && ft_strncmp(op, "ss", 2) == 0))
}

int	optimize_last_intr(t_list **instr, char *op)
{
	t_list	*last;
	char	*last_op;
	char	*combo;
	
	if (!instr || !*instr || !op)
		return (0);
	last = ft_lstlast(*instr);
	last_op = last->content;
	if (cancelling_ops(last_op, op))
	{
		delete_last_node(instr);
		return (1);
	}
	combo = combine_ops(last_op, op);
	if (combo)
	{
		free(last->content);
		last->content = ft_strdup(combo);
		return (1);
	}
	return (0);
}

void	add_instr(t_list **instr, char *op)
{
	t_list	*new;

	if (optimize_last_intr(instr, op))
		return ;
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
	if (!instr)
		return ;	
	while (instr)
	{
		ft_printf("%s\n", instr->content);
		instr = instr->next;
	}
}
