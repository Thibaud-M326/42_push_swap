################# MAKEFILE LIBFT #################

NAME	:= libft.a
HDRS    := libft.h
MAKEFILE:= Makefile

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

SRCS		:= 	\
	ft_atoi.c			\
	ft_bzero.c			\
	ft_calloc.c			\
	ft_isalnum.c		\
	ft_isalpha.c		\
	ft_isascii.c		\
	ft_isdigit.c		\
	ft_isprint.c		\
	ft_itoa.c			\
	ft_memchr.c			\
	ft_memcmp.c			\
	ft_memcpy.c			\
	ft_memmove.c		\
	ft_memset.c			\
	ft_putchar_fd.c		\
	ft_putendl_fd.c		\
	ft_putnbr_fd.c		\
	ft_putstr_fd.c		\
	ft_split.c			\
	ft_strchr.c			\
	ft_strdup.c			\
	ft_striteri.c		\
	ft_strjoin.c		\
	ft_strlcat.c		\
	ft_strlcpy.c		\
	ft_strlen.c			\
	ft_strmapi.c		\
	ft_strncmp.c		\
	ft_strnstr.c		\
	ft_strrchr.c		\
	ft_strtrim.c		\
	ft_substr.c			\
	ft_tolower.c		\
	ft_toupper.c

SRCS_BONUS	:=	\
	ft_lstnew_bonus.c			\
	ft_lstadd_front_bonus.c		\
	ft_lstsize_bonus.c			\
	ft_lstlast_bonus.c			\
	ft_lstadd_back_bonus.c		\
	ft_lstdelone_bonus.c		\
	ft_lstclear_bonus.c 		\
	ft_lstiter_bonus.c 			\
	ft_lstmap_bonus.c

# BUILD_DIR	:= .build
# OBJS		:= $(SRCS:%.c=$(BUILD_DIR)/%.o)
OBJS		:= $(SRCS:%.c=%.o)

# OBJS_BONUS	:= $(SRCS_BONUS:%.c=$(BUILD_DIR)/%.o)
OBJS_BONUS	:= $(SRCS_BONUS:%.c=%.o)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
AR			:= ar
ARFLAGS 	:= -r -c -s

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#

RM              := rm -f
# RM_DIR          := rm -rf
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

bonus: $(OBJS) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJS_BONUS) $(TOUCH)

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
