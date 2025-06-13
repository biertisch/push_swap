#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_double_list
{
	int						value;
	struct s_double_list	*prev;
	struct s_double_list	*next;	
}							t_double_list;

typedef struct s_data
{
	t_double_list	*stack_a;
	t_double_list	*stack_b;
	int				size_a;
	int				size_b;
	t_list			*instr;
	char			**input;
}					t_data;

# include "../lib/include/libft.h"
# include <stdlib.h>

//add prototypes

#endif