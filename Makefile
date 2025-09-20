NAME		=	push_swap

SRC_FILES	=	instr linked_list main mem ops_utils ops parser quick_sort_a quick_sort_b\
				radix_sort sort_small sort

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	include/
LIBFT_DIR	=	libft/

LIBFT_URL	=	https://github.com/biertisch/libft.git
LIBFT		=	$(LIBFT_DIR)libft.a

SRC         =	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ         =	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g -I$(INC_DIR) -I$(LIBFT_DIR)$(INC_DIR)
LFLAGS		=	-L$(LIBFT_DIR) -lft
RM			=	rm -rf

SENTINEL	=	$(OBJ_DIR).compiled

ARGS		=	100 100

all: $(NAME)
	@cat banner.txt

$(NAME): $(LIBFT) $(OBJ)
	@echo "Linking executable..."
	@$(CC) $(OBJ) $(LFLAGS) -o $@

$(LIBFT): | $(LIBFT_DIR)
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR) extra > /dev/null

$(LIBFT_DIR):
	@echo "Cloning libft..."
	@git clone --quiet $(LIBFT_URL) $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ): $(SENTINEL)

$(SENTINEL):
	@echo "Compiling object files..."
	@touch $@

clean:
	@echo "Removing object files..."
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null

fclean: clean
	@echo "Removing executable and libraries..."
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
	@$(RM) $(LIBFT_DIR)

re: fclean all

test: $(NAME)
	@./test.sh $(ARGS)

.PHONY: all test clean fclean re test