# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/19 20:16:12 by rpinet            #+#    #+#              #
#    Updated: 2015/03/11 17:02:16 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

FLAG = -Wall -Wextra -Werror

SRC = ft_launch.c \
		ft_stack.c \
		ft_swap_stack.c \
		ft_push.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
