# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_bzero.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 13:29:29 by rpinet            #+#    #+#              #
#    Updated: 2015/02/27 13:29:35 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global	_ft_bzero

section .text

_ft_bzero
	mov			rcx, rsi

loop:
	dec			rcx
	cmp			rcx, 0
	jl			exit
	mov			byte[rdi + rcx], 0
	jmp			loop

exit:
	ret