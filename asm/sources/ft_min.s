# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_min.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/05 16:51:25 by rpinet            #+#    #+#              #
#    Updated: 2015/03/05 16:51:27 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_min

section .text

_ft_min:
	cmp		edi, esi
	jl		exit
	mov		eax, esi
	ret

exit:
	mov		eax, edi
	ret
