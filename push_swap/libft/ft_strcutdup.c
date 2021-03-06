/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcutdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 12:34:46 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/04 19:26:38 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcutdup(const char *s, size_t cut)
{
	size_t	i;
	size_t	len;
	char	*cpy;

	len = ft_strlen(s);
	if (cut >= len || !s)
		return (NULL);
	else if (cut == 0)
		return (ft_strdup(s));
	if (!(cpy = ft_memalloc(sizeof(char) * (len - cut) + 1)))
		return (NULL);
	i = 0;
	while (s[cut + i] != '\0')
	{
		cpy[i] = s[cut + i];
		i++;
	}
	return (cpy);
}
