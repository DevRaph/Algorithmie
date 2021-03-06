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

section .text

_ft_tolower:
	call		_ft_isupper
	cmp			al, 0
	je			exit
	mov			al, dil
	add			al, 32
	ret

exit:
	mov			al, dil
	ret
