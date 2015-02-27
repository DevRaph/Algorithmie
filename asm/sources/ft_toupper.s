# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_toupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 14:51:27 by rpinet            #+#    #+#              #
#    Updated: 2015/02/27 14:53:49 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_toupper
extern _ft_islower

_ft_toupper:
	call		_ft_islower
	cmp			rax, 1
	je			exit
	mov			rax, rdi - 32
	ret

exit:
	mov			rax, rdi
	ret
