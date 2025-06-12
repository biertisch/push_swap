#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;	
}					t_node;

typedef struct s_data
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_a;
	int		size_b;
}			t_data;

# include "../lib/include/libft.h"
# include <stdlib.h>

t_node	*create_node(int n);
void	add_node_back(t_node **stack, t_node *new);
t_node	*get_last_node(t_node *stack);
int		get_stack_size(t_node *stack);
void	clear_stack(t_node **stack);
void	initiate(char **input, t_data *stacks);
void	duplicate_check(t_node *stack);
void	mem_check(t_node *node, t_data *stacks);
void	error(char *s, int n);

#endif