# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memset.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/09 16:40:19 by rpinet            #+#    #+#              #
#    Updated: 2015/03/09 16:40:22 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global _ft_memset
	section .text

_ft_memset:
	mov		rcx, rdx

loop:
	cmp		rcx, 0
	jle		exit
	dec		rcx
	mov		byte [rdi + rcx], sil
	jmp		loop

exit:
	ret
