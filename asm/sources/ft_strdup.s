# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/09 18:47:28 by rpinet            #+#    #+#              #
#    Updated: 2015/03/09 18:47:30 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global _ft_strdup
	extern _ft_strlen
	extern _malloc

_ft_strdup:
	cmp			rdi, 0
	je			exit
	push		rdi
	call		_ft_strlen
	mov			rdi, rax
	inc			rdi
	mov			rcx, rax
	push		rcx
	call		_malloc
	cmp			rax, 0
	je			exit
	pop			rcx
	pop			rsi
	mov			rdi, rax
	rep			movsb
# faire pour memcpy pour tester #
	mov			byte [rdi + rcx], 0
	
exit:
	ret
