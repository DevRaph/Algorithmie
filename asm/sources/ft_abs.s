# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_abs.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/05 16:51:54 by rpinet            #+#    #+#              #
#    Updated: 2015/03/05 16:51:57 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_abs

section .text

_ft_abs:
	cmp		edi, 0
	jl		exit
	mov		eax, edi
	ret

exit:
	mov		eax, edi
	neg		eax
	ret