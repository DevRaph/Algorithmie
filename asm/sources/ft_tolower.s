# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_tolower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 14:54:35 by rpinet            #+#    #+#              #
#    Updated: 2015/02/27 14:54:36 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_tolower
extern _ft_isupper

_ft_tolower:
	call		_ft_isupper
	cmp			rax, 1
	je			exit
	mov			rax, rdi + 32
	ret

exit:
	mov			rax, rdi
	ret

