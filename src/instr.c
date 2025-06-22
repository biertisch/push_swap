/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 07:48:45 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/13 07:48:45 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	*combine_ops(char *last_op, char *op)
{
	if ((ft_strncmp(last_op, "sa", 3) == 0 && ft_strncmp(op, "sb", 3) == 0)
		|| (ft_strncmp(last_op, "sb", 3) == 0 && ft_strncmp(op, "sa", 3) == 0))
		return ("ss");
	if ((ft_strncmp(last_op, "ra", 3) == 0 && ft_strncmp(op, "rb", 3) == 0)
		|| (ft_strncmp(last_op, "rb", 3) == 0 && ft_strncmp(op, "ra", 3) == 0))
		return ("rr");
	if ((ft_strncmp(last_op, "rra", 3) == 0 && ft_strncmp(op, "rrb", 3) == 0)
		|| (ft_strncmp(last_op, "rrb", 3) == 0
			&& ft_strncmp(op, "rra", 3) == 0))
		return ("rrr");
	return (NULL);
}

static int	cancelling_ops(char *last_op, char *op)
{
	return ((ft_strncmp(last_op, "pa", 3) == 0 && ft_strncmp(op, "pb", 3) == 0)
		|| (ft_strncmp(last_op, "pb", 3) == 0 && ft_strncmp(op, "pa", 3) == 0)
		|| (ft_strncmp(last_op, "ra", 3) == 0 && ft_strncmp(op, "rra", 3) == 0)
		|| (ft_strncmp(last_op, "rra", 3) == 0 && ft_strncmp(op, "ra", 3) == 0)
		|| (ft_strncmp(last_op, "rb", 3) == 0 && ft_strncmp(op, "rrb", 3) == 0)
		|| (ft_strncmp(last_op, "rrb", 3) == 0 && ft_strncmp(op, "rb", 3) == 0)
		|| (ft_strncmp(last_op, "sa", 3) == 0 && ft_strncmp(op, "sa", 3) == 0)
		|| (ft_strncmp(last_op, "sb", 3) == 0 && ft_strncmp(op, "sb", 3) == 0)
		|| (ft_strncmp(last_op, "ss", 3) == 0 && ft_strncmp(op, "ss", 3) == 0));
}

static int	optimize_instr(t_list **instr, char *op, t_data *data)
{
	t_list	*tail;
	char	*last_op;
	char	*combo;

	if (!instr || !*instr || !op || !data)
		return (0);
	tail = ft_lstlast(*instr);
	last_op = tail->content;
	if (cancelling_ops(last_op, op))
	{
		delete_last_node(instr);
		return (1);
	}
	combo = combine_ops(last_op, op);
	if (combo)
	{
		free(tail->content);
		tail->content = ft_strdup(combo);
		free(combo);
		if (!tail->content)
			error_msg("Error: memory allocation failed", data);
		return (1);
	}
	return (0);
}

void	add_instr(t_list **instr, char *op, t_data *data)
{
	t_list	*new;
	char	*dup_op;

	if (!instr || !op || !data || optimize_instr(instr, op, data))
		return ;
	dup_op = ft_strdup(op);
	if (!dup_op)
		error_msg("Error: memory allocation failed", data);
	new = ft_lstnew(dup_op);
	if (!new)
		error_msg("Error: memory allocation failed", data);
	ft_lstadd_back(instr, new);
}

void	print_instr(t_list *instr)
{
	if (!instr)
		return ;
	while (instr && instr->content)
	{
		ft_printf("%s\n", instr->content);
		instr = instr->next;
	}
}
