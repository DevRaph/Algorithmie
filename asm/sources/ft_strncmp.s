# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strncmp.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/09 20:27:10 by rpinet            #+#    #+#              #
#    Updated: 2015/03/09 20:27:12 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global _ft_strncmp.s
	section .text

_ft_strncmp:
	xor			rax, rax
	mov			rcx, -1

loop:
	inc			rcx
	cmp			[rdx - 1], rcx
	je			exit
	cmp			byte [rdi + rcx], 0
	je			exit
	cmp			byte [rsi + rcx], 0
	je			exit
	mov			dl, byte [rdi + rcx]
	cmp			byte [rsi + rcx], dl
	je			loop
			
exit:
	mov			al, byte [rdi + rcx]
	mov			cl, byte [rsi + rcx]
	sub			al, cl
	jl			exit_inf
	ret

exit_inf:
	mov			rax, -1
	ret
