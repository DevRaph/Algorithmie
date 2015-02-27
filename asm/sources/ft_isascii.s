# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isascii.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 13:59:31 by rpinet            #+#    #+#              #
#    Updated: 2015/02/27 13:59:35 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isascii

section .text

_ft_isascii:
	cmp			rdi, 0
	jl			setfalse
	cmp			rdi, 127
	jg			setfalse
	mov			rax, 1
	ret

setfalse:
	mov		rax, 0
	ret
