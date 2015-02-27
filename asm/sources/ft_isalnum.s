# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalnum.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 14:46:16 by rpinet            #+#    #+#              #
#    Updated: 2015/02/27 14:46:19 by rpinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isalnum
extern _isdigit
extern _isalpha

_ft_isalnum:
	call		_isdigit
	cmp			rax, 1
	je			exit
	call		_isalpha

exit:
	ret
