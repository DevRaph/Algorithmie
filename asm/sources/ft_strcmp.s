# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/09 19:35:58 by rpinet            #+#    #+#              #
#    Updated: 2015/03/09 19:54:10 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global _ft_strcmp
	section .text

_ft_strcmp:
	xor		rax, rax
	mov		rcx, -1

loop:
	inc		rcx
	cmp		byte [rdi + rcx], 0
	je		exit
	cmp		byte [rsi + rcx], 0
	je		exit
	mov		dl, byte [rsi + rcx]
	cmp		byte [rdi + rcx], dl
	je		loop

exit:
	mov		dl, byte [rsi + rcx]
	mov		al, byte [rdi + rcx]
	sub 	al, dl
	jl		exit2
	ret

exit2:
	mov		rax, -1
	ret
