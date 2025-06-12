/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beatde-a <beatde-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:26:08 by beatde-a          #+#    #+#             */
/*   Updated: 2025/06/12 14:26:08 by beatde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error(char *s, int n)
{
	ft_printf("Error: %s\n", s);
	exit(n);
}

void	mem_check(t_node *node, t_data *stacks)
{
	if (!node)
	{
		clear_stack(&(stacks->stack_a));
		clear_stack(&(stacks->stack_b));
		error("memory allocation failed", 2);
	}
}

void	duplicate_check(t_node *stack)
{
	t_node	*current;
	t_node	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				error("invalid input", 1);
			checker = checker->next;
		}
		current = current->next;
	}
}

void	initiate(char **input, t_data *stacks)
{
	t_node	*new;
	int		i; 
	int		j;

	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->size_a = 0;
	stacks->size_b = 0;
	i = 0;
	while (input[i])
	{
		new = create_node(ft_atoi(input[i]));
		mem_check(new, stacks);
		add_node_back(&stacks->stack_a, new);
		stacks->size_a++;
		j = 0;
		while (input[i][j])
		{
			if (!ft_isdigit(input[i][j]) && input[i][j] != ' ')
				error("invalid input", 1);
			j++;
		}
		i++;
	}
	duplicate_check(stacks->stack_a);
}

int	main(int argc, char **argv)
{
	char	**input;
	t_data	stacks;

	if (argc < 2)
		error("invalid input", 1);
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		if (!input)
			error("memory allocation failed", 2);
	}
	else
		input = argv + 1;
	initiate(input, &stacks);

	//free input
	//free stacks
	return (0);
}

//4 - hardcode optimal solutions 2 to 5 elements (use logic trees)
//5 - implement a scalable sorting algorithm

