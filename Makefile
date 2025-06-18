SRC_DIR = src/
OBJ_DIR = obj/
LIB_DIR = lib/

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude -I$(LIB_DIR)include
RM = rm -rf

LIB = $(LIB_DIR)libft.a

NAME = push_swap

SRC = $(SRC_DIR)d_list_core.c\
		$(SRC_DIR)d_list_utils.c\
		$(SRC_DIR)error.c\
		$(SRC_DIR)instr.c\
		$(SRC_DIR)main.c\
		$(SRC_DIR)mem_free.c\
		$(SRC_DIR)ops_core.c\
		$(SRC_DIR)ops_utils.c\
		$(SRC_DIR)parser.c\
		$(SRC_DIR)s_list.c\
		$(SRC_DIR)sort.c\

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

all: $(NAME)

$(NAME): $(LIB) obj $(OBJ) 
	$(CC) $(OBJ) -o $@ $(LIB)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

obj:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re