# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_putstr.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/09 10:45:59 by rpinet            #+#    #+#              #
#    Updated: 2015/03/09 10:46:01 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global _ft_putstr
	extern _ft_strlen

_ft_putstr:
	mov			rsi, rdi
	call		_ft_strlen
	mov			rdi, 1
	mov			rdx, rax
	mov			rax, 0x2000004
	syscall
	jc			exit
	ret

exit:
	mov			rax, 0
	ret