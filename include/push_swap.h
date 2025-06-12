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

#endif