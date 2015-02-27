# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isdigit.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 13:30:29 by rpinet            #+#    #+#              #
#    Updated: 2015/02/27 13:30:33 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isdigit

section .text

_ft_isdigit:
	cmp		rdi, '0'
	jl		setfalse
	cmp		rdi, '9'
	jg		setfalse

settrue:
	mov		rax, 1
	ret

setfalse:
	mov		rax, 0
	ret
