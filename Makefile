################# MAKEFILE PUSH_SWAP #################

NAME    := push_swap
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -Iheader
RM      := rm -f
RMRF    := rm -rf

SRCS    := source/main.c \
           source/push_swap.c \
           source/stack_init.c \
           source/stack_push.c \
           source/stack_reverse_rotate.c \
           source/stack_rotate.c \
           source/stack_sort.c \
           source/stack_swap.c \
           source/stack_utils.c \
           source/atol_overflow.c

HDRS    := header/push_swap.h
OBJS    := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a libft/libftprintf.a

%.o: source/%.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RMRF) source/*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re