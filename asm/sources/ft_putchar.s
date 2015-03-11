# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_putchar.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/09 15:14:16 by rpinet            #+#    #+#              #
#    Updated: 2015/03/09 15:14:23 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global	_ft_putchar
	extern	_ft_putstr

_ft_putchar:
	lea		rcx, [rel char]
	mov		[rcx], dil
	mov		rdi, rcx
	call	_ft_putstr
	ret

section .bss
	char	resb 0x1
