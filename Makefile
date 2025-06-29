SRC_DIR = src/
OBJ_DIR = obj/
LIB_DIR = libft/

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -Iinclude -I$(LIB_DIR)include
RM = rm -rf

LIB = $(LIB_DIR)libft.a

NAME = push_swap

SRC = $(SRC_DIR)instr.c\
		$(SRC_DIR)linked_list.c\
		$(SRC_DIR)main.c\
		$(SRC_DIR)mem.c\
		$(SRC_DIR)ops_utils.c\
		$(SRC_DIR)ops.c\
		$(SRC_DIR)parser.c\
		$(SRC_DIR)quick_sort_a.c\
		$(SRC_DIR)quick_sort_b.c\
		$(SRC_DIR)radix_sort.c\
		$(SRC_DIR)sort_small.c\
		$(SRC_DIR)sort.c		

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

test:
	curl -L -o test.sh https://raw.githubusercontent.com/biertisch/42_push_swap/refs/heads/main/test.sh
	chmod +x test.sh

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all test clean fclean re