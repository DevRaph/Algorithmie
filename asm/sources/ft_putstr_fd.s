# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_putstr_fd.s                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/09 10:46:22 by rpinet            #+#    #+#              #
#    Updated: 2015/03/09 10:46:24 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global _ft_putstr_fd
	extern _ft_strlen

_ft_putstr_fd:
	mov			rdx, rdi
	call		_ft_strlen
	mov			rdi, rsi
	mov			rsi, rdx
	mov			rdx, rax
	mov			rax, 0x2000004
	syscall
	jc			exit
	ret

exit:
	mov			rax, 0
	ret
