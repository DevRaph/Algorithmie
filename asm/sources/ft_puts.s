# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_puts.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/09 16:09:38 by rpinet            #+#    #+#              #
#    Updated: 2015/03/09 16:09:40 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global _ft_puts
	extern _ft_putstr
	extern _ft_putchar

	section .text

_ft_puts:
	cmp			rdi, 0
	je			if_null
	call		_ft_putstr
	mov			rdi, 10
	call		_ft_putchar
	ret

if_null:
	mov			rdi, 1
	lea			rsi, [rel my_null]
	mov			rdx, 7
	mov			rax, 0x2000004
	syscall
	jc			my_null	
	ret

error:
	mov			rax, -1
	ret

section	.data
	my_null		db "(null)", 10