# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 20:09:09 by gbertet           #+#    #+#              #
#    Updated: 2023/06/15 15:01:34 by gbertet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_strlen.c \
	ft_memset.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_bzero.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_atoi.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_realloc.c \
	get_next_line.c \
	ft_printf.c \
	ft_putnbr_base.c \
	ft_putstuff.c

SRCBONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

ifdef BONUS
	SRC += ${SRCBONUS}
endif

OBJ = $(notdir $(SRC:.c=.o))

OBJBONUS = $(notdir $(SRCBONUS:.c=.o))

CFLAGS = -Werror -Wall -Wextra
CC = clang
all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

bonus :
	@make BONUS=1

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $^

clean :
	rm -rf $(OBJ) $(OBJBONUS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(OBJBONUS)

.PHONY: all clean fclean re
