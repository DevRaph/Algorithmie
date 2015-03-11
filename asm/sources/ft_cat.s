# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_cat.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/09 19:22:17 by rpinet            #+#    #+#              #
#    Updated: 2015/03/09 19:22:23 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# gerer le moins de changement de context entre l'user-space et le kernel-space#
# difference entre bss et data #
# test enlever les push pop de rdi #

	global _ft_cat
	section .text


_ft_cat:
	cmp			rdi, 0
	jl			exit
	push		rdi

loop:
	pop			rdi
	lea			rsi, [rel buff]
	mov			rdx, 0x1000
	mov			rax, 0x2000003
	syscall
	jc			exit
	cmp			rax, 0
	je			exit
	push		rdi
	mov			rdi, 1
	mov			rdx, rax
	mov			rax, 0x2000004
	syscall
	jc			exit
	jmp			loop

exit:
	ret

section .bss
	buff:		resb 0x1000