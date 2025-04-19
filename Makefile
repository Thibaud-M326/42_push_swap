# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./header -I./libft/42_libft -I./libft/42_ft_printf
LIBFT = ./libft/42_libft/libft.a
LIBFTPRINTF = ./libft/42_ft_printf/libftprintf.a
OBJ_DIR = ./obj
SRC_DIR = ./source
HEADER_DIR = ./header
BIN_DIR = ./bin

# Directories
SRC = $(shell find $(SRC_DIR) -name '*.c')
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Targets
NAME = push_swap
CHECKER = checker_Mac

# Default Target
all: $(NAME)

# Create Object Folder
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Create Binary Folder
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Compiler and Linker Rules
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(LIBFTPRINTF) | $(BIN_DIR)
	$(CC) $(OBJ) $(LIBFT) $(LIBFTPRINTF) -o $(BIN_DIR)/$(NAME)

# Make checker executable
$(CHECKER): $(OBJ) $(LIBFT) $(LIBFTPRINTF) | $(BIN_DIR)
	$(CC) $(OBJ) $(LIBFT) $(LIBFTPRINTF) -o $(BIN_DIR)/$(CHECKER)

# Build libft and libftprintf
$(LIBFT):
	$(MAKE) -C ./libft/42_libft

$(LIBFTPRINTF):
	$(MAKE) -C ./libft/42_ft_printf

# Clean Objects and Binaries
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)/$(NAME)
	rm -rf $(BIN_DIR)/$(CHECKER)
	$(MAKE) clean -C ./libft/42_libft
	$(MAKE) clean -C ./libft/42_ft_printf

# Remove compiled files
fclean: clean
	rm -rf $(LIBFT)
	rm -rf $(LIBFTPRINTF)

# Rebuild Everything
re: fclean all

.PHONY: all clean fclean re
