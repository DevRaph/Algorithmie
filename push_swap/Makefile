# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/11 14:59:18 by rpinet            #+#    #+#              #
#    Updated: 2015/03/11 15:48:41 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = main.c
FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ re
	@make -C srcs/ re
	@gcc -o $(NAME) $(SRC) srcs/push_swap.a $(FLAG) -L libft -lft
	@echo "\n\tGO PUSH SWAP\n"

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@make -C srcs/ clean
	@echo "\033[35;1m•   \033[0mRemoving object files in push-swap ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean
	@make -C srcs/ fclean
	@echo "\033[35;1m•   \033[0mRemoving $(NAME) (and all .a)...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re: fclean all
