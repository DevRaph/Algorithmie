# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/09 17:26:25 by rpinet            #+#    #+#              #
#    Updated: 2015/03/09 17:28:29 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global _ft_memcpy
	section .text

_ft_memcpy:
	mov		rcx, rdx

loop:
	cmp		rcx, 0
	jle		exit
	dec		rcx
	mov		al, byte [rsi + rcx]
	mov		byte [rdi + rcx], al
	jmp		loop

exit:
	mov		rax, rdi
	ret
