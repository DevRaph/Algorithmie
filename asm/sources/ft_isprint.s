# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isprint.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 13:26:59 by rpinet            #+#    #+#              #
#    Updated: 2015/02/27 13:27:02 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isprint

section .text

_ft_isprint:
	cmp				rdi, 32
	jl				setfalse
	cmp				rdi, 126
	jg				setfalse
	mov				rax, 1
	ret

setfalse:
	mov				rax, 0
	ret
