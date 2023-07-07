# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatta <amatta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 11:52:32 by amatta            #+#    #+#              #
#    Updated: 2023/07/04 12:02:01 by amatta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = GCC

OBJS = pipex.o utils.o

LIBFT = ./libft/libft.a

FLAGS = -Wall -Werror -Wextra

#COLORS
RED = \033[1;31m

GREEN = \033[1;32m

YELLOW = \033[1;33m

DEFAULT = \033[0m

all : $(NAME)

%.o : %.c
	@cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	@cc $(OBJS) ${LIBFT} -o $(NAME)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@make clean -C libft
	@rm -f $(OBJS)
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "$(RED)all deleted!$(DEFAULT)"

re: clean fclean all

.PHONY: all, clean, fclean, re
