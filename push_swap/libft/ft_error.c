/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:11:14 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/11 15:40:11 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int			ft_error(char *s, char *s2)
{
	if (s)
	{
		ft_setbgcolor(9);
		ft_setfgcolor(0);
		write(1, ">>", 2);
		ft_resetcolor();
		ft_setfgcolor(9);
		write(1, " [", 2);
		write(1, s, ft_strlen(s));
		write(1, "] : :", 5);
		if (s2)
			write(1, s2, ft_strlen(s2));
		ft_resetcolor();
		write (1, "\n", 1);
	}
	return (0);
}
