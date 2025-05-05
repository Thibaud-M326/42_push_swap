CC = cc
CFLAGS = -Wall -Wextra -Werror -I./header -I./libft/42_libft -I./libft/42_ft_printf
LIBFT = ./libft/42_libft/libft.a
LIBFTPRINTF = ./libft/42_ft_printf/libftprintf.a
OBJ_DIR = ./obj
SRC_DIR = ./source
HEADER_DIR = ./header
HEADER = $(HEADER_DIR)/push_swap.h
LIBFTPRINTF_HEADER = $(HEADER_DIR)/ft_printf.h
LIBFT_HEADER = $(HEADER_DIR)/libft.h
HDRS = $(HEADER) $(LIBFTPRINTF_HEADER) $(LIBFT_HEADER)

SRC =									\
	$(SRC_DIR)/atol_overflow.c			\
	$(SRC_DIR)/free_utils.c				\
	$(SRC_DIR)/main.c					\
	$(SRC_DIR)/push_swap.c				\
	$(SRC_DIR)/stack_init_support.c		\
	$(SRC_DIR)/stack_init.c				\
	$(SRC_DIR)/stack_print.c			\
	$(SRC_DIR)/stack_push.c				\
	$(SRC_DIR)/stack_reverse_rotate.c	\
	$(SRC_DIR)/stack_rotate.c			\
	$(SRC_DIR)/stack_sort.c				\
	$(SRC_DIR)/stack_swap.c				\
	$(SRC_DIR)/stack_utils.c			\
	$(SRC_DIR)/symplify_stack.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = push_swap
CHECKER = checker_Mac

all: lib lib_printf $(NAME)

lib:
	$(MAKE) -C ./libft/42_libft

lib_printf:
	$(MAKE) -C ./libft/42_ft_printf

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDRS) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(LIBFTPRINTF)
	$(CC) $(OBJ) $(LIBFT) $(LIBFTPRINTF) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C ./libft/42_libft
	$(MAKE) clean -C ./libft/42_ft_printf

fclean: clean
	rm -f push_swap
	rm -rf $(LIBFT)
	rm -rf $(LIBFTPRINTF)

re: fclean all

.PHONY: all clean fclean re
