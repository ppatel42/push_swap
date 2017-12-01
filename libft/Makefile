# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppatel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/19 15:45:03 by ppatel            #+#    #+#              #
#    Updated: 2017/01/20 18:52:04 by ppatel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_lstsize.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_min.c \
	  ft_max.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putwchar.c \
	  ft_putwchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putnbrbase.c \
	  ft_putnbrbase_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_putnstr.c \
	  ft_putnstr_fd.c \
	  ft_putwstr.c \
	  ft_putwstr_fd.c \
	  ft_putnwstr.c \
	  ft_putnwstr_fd.c \
	  ft_sort_wordtab.c \
	  ft_split_whitespaces.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclen.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strnlen.c \
	  ft_strltrim.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strparts.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  get_next_line.c

OBJ = $(SRC:.c=.o)

HDRS = -I./get_next_line.h \
	   -I./libft.h

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) -c $(SRC) $(HDRS)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
