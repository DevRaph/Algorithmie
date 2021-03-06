/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:14:17 by rpinet            #+#    #+#             */
/*   Updated: 2015/01/06 15:14:29 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_base(int n)
{
	int		i;
	char	*s;

	i = ~(!n);
	s = ft_strnew(n + 1);
	while (++i < n)
		*(s + i) = (i < 10) ? ('0' + i) : ('A' + (i - 10));
	return (s);
}
