# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcat.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/09 15:13:53 by rpinet            #+#    #+#              #
#    Updated: 2015/03/09 15:13:56 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global _ft_strcat
	extern _ft_strlen

_ft_strcat:
	mov			rax, rdi
	mov			cl, [rax]
	cmp			cl, 0
	jz			start

go_end_s1:
	inc			rax
	mov			cl, [rax]
	cmp			cl, 0
	jnz			go_end_s1

start:
	sub			rax, rdi
	xor			rcx, rcx

loop:
	cmp			byte[rsi + rcx], 0
	jle			exit
	mov			rdx, [rsi + rcx]
	mov			[rdi + rax], rdx
	inc			rax
	inc			rcx
	jmp			loop

exit:
	mov			rdx, 0
	mov			[rdi + rax], rdx
	mov			rax, rdi
	ret