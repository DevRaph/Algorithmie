# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_putchar_fd.s                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/09 10:46:32 by rpinet            #+#    #+#              #
#    Updated: 2015/03/09 10:46:34 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global _ft_putchar_fd
	extern _ft_putstr_fd

_ft_putchar_fd:
	lea		rcx, [rel char]
	mov		[rcx], dil
	mov		rdi, rcx
	call	_ft_putstr_fd
	ret

section .bss
	char	resb 0x1

