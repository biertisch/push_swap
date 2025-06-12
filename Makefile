SRC_DIR = src/
OBJ_DIR = obj/
LIB_DIR = lib/

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude -I$(LIB_DIR)include
RM = rm -rf

LIB = $(LIB_DIR)libft.a

NAME = push_swap
SRC = 
OBJ = 

NAME_BONUS = push_swap_bonus
SRC_BONUS = 
OBJ_BONUS = 

all: obj $(LIB) $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LIB)

bonus: obj $(LIB) $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -o $@ $(LIB)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re