# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppatel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/06 16:10:52 by ppatel            #+#    #+#              #
#    Updated: 2017/02/16 14:19:37 by ppatel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = push_swap_project

NAME1 = checker

NAME2 = push_swap

FLAGS = -Wall -Wextra -Werror

SDIR = srcs

ODIR = objs

SRC1 = $(SDIR)/checker.c

SRC2 = $(SDIR)/push_swap.c\
	   $(SDIR)/sort_large.c\
	   $(SDIR)/sort_small.c

SRC3 = $(SDIR)/swap_push_move.c\
	   $(SDIR)/rotate.c\
	   $(SDIR)/rrotate.c\
	   $(SDIR)/func.c\
	   $(SDIR)/create.c\
	   $(SDIR)/check.c

OBJ1 = $(SRC1:$(SDIR)/%.c=$(ODIR)/%.o)

OBJ2 = $(SRC2:$(SDIR)/%.c=$(ODIR)/%.o)

OBJ3 = $(SRC3:$(SDIR)/%.c=$(ODIR)/%.o)

HDRS = -I./includes

LIBFT = libft/libft.a

LIBS = -L./libft/ -lft

all : $(NAME)

$(NAME): $(ODIR) $(LIBFT) $(OBJ1) $(OBJ2) $(OBJ3) $(NAME1) $(NAME2)

$(NAME1):
	@$(CC) $(FLAGS) $(LIBS) -o $@ $(OBJ1) $(OBJ3)
	@echo "Executable $(NAME1) created."

$(NAME2):
	@$(CC) $(FLAGS) $(LIBS) -o $@ $(OBJ2) $(OBJ3)
	@echo "Executable $(NAME2) created."

$(ODIR):
	@mkdir objs

$(ODIR)/%.o: $(SDIR)/%.c
	@$(CC) $(FLAGS) -c $< $(HDRS) -o $@
	@echo "Object created."

$(LIBFT):
	@make -C libft/

clean:
	@rm -rf $(ODIR)
	@echo "Objects deleted."

fclean: clean
	@rm -rf $(NAME1) $(NAME2)
	@make fclean -C libft/
	@echo "Executables deleted."

re: fclean all

.PHONY: all clean fclean re
