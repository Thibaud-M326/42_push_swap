################# MAKEFILE LIBFT #################

NAME	:= libftprintf.a
HDRS    := ft_printf.h
MAKEFILE:= Makefile

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

SRCS		:=			\
	ft_printf.c			\
	ft_text.c			\
	ft_number.c			\

OBJS		:= $(SRCS:%.c=%.o)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
AR			:= ar
ARFLAGS 	:= -r -c -s

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#

RM              := rm -f
MAKEFLAGS       += --no-print-directory
TOUCH			:= && touch bonus
BONUS			:= bonus

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $(NAME))

%.o: %.c $(HDRS) $(MAKEFILE)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@ WITH $<)

# bonus: $(OBJS) $(OBJS_BONUS)
# 	$(MAKE) $(NAME) SRCS="%(SRCS) $(BONUS)"

clean:
	$(RM) $(BONUS) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#

.PHONY: all clean fclean re