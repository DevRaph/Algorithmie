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

section .text

_ft_toupper:
	call		_ft_islower
	cmp			al, 0
	je			exit
	mov			al, dil
	sub			al, 32
	ret

exit:
	mov			al, dil
	ret
