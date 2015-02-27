# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_islower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 13:26:29 by rpinet            #+#    #+#              #
#    Updated: 2015/02/27 13:26:30 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_islower

section .text

_ft_islower:
	cmp			rdi, 97
	jl			setfalse
	cmp			rdi, 122
	jg			setfalse
	mov			rax, 1
	ret

setfalse:
	mov			rax, 0
	ret
