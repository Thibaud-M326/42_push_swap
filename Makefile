# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./header -I./libft/42_libft -I./libft/42_ft_printf
LIBFT = ./libft/42_libft/libft.a
LIBFTPRINTF = ./libft/42_ft_printf/libftprintf.a
OBJ_DIR = ./obj
SRC_DIR = ./source
HEADER_DIR = ./header
HEADER = $(HEADER_DIR)/push_swap.h

# Directories
SRC = $(shell find $(SRC_DIR) -name '*.c')
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Targets
NAME = push_swap
CHECKER = checker_Mac

# Default Target
all: lib lib_printf $(NAME)

lib:
	$(MAKE) -C ./libft/42_libft

lib_printf:
	$(MAKE) -C ./libft/42_ft_printf

# Create Object Folder
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compiler and Linker Rules
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(LIBFTPRINTF) Makefile
	$(CC) $(OBJ) $(LIBFT) $(LIBFTPRINTF) -o $(NAME)

# Clean Objects and Binaries
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C ./libft/42_libft
	$(MAKE) clean -C ./libft/42_ft_printf

# Remove compiled files
fclean: clean
	rm -f push_swap
	rm -rf $(LIBFT)
	rm -rf $(LIBFTPRINTF)

# Rebuild Everything
re: fclean all

.PHONY: all clean fclean re
