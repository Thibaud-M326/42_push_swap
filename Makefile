CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -I./header -I./libft/42_libft -I./libft/42_ft_printf
LIBFT = ./libft/42_libft
LIBFTPRINTF = ./libft/42_ft_printf
LIBFT_A = ./libft/42_libft/libft.a
LIBFTPRINTF_A = ./libft/42_ft_printf/libftprintf.a
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
	$(SRC_DIR)/stack_push.c				\
	$(SRC_DIR)/stack_reverse_rotate.c	\
	$(SRC_DIR)/stack_rotate.c			\
	$(SRC_DIR)/stack_sort.c				\
	$(SRC_DIR)/stack_swap.c				\
	$(SRC_DIR)/stack_utils.c			\
	$(SRC_DIR)/symplify_stack.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.d)

NAME = push_swap

all: lib lib_printf $(NAME)

lib:
	$(MAKE) -C $(LIBFT)

lib_printf:
	$(MAKE) -C $(LIBFTPRINTF)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT_A) $(LIBFTPRINTF_A)
	$(CC) $(OBJ) $(LIBFT_A) $(LIBFTPRINTF_A) -o $(NAME)

-include $(DEP)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C ./libft/42_libft
	$(MAKE) clean -C ./libft/42_ft_printf

fclean: clean
	rm -f push_swap
	rm -rf $(LIBFT_A)
	rm -rf $(LIBFTPRINTF_A)

re: fclean all

.PHONY: all clean fclean re
