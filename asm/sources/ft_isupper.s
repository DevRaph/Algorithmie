# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 13:26:17 by rpinet            #+#    #+#              #
#    Updated: 2015/02/27 13:26:19 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isupper

section .text

_ft_isupper:
	cmp			rdi, 65
	jl			setfalse
	cmp			rdi, 90
	jg			setfalse
	mov			rax, 1
	ret

setfalse:
	mov			rax, 0
	ret
