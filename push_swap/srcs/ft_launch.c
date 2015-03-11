/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:17:14 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/11 18:26:36 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"
#include <stdlib.h>

static int			ft_isint(char *s)
{
	int		i;
	int		j;
	char	*tab;
	int		a;

	tab = ft_strdup("2147483647");
	i = 0;
	a = 0;
	if (s && s[0] == '-' && !a++)
	{
		i++;
		tab[9] = '8';	
	}
	if ((ft_strlen(s) - i) > 10)
		return (0);
	j = 0;
	while (s && s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			return (0);
		if (s[i] > tab[j] && ((ft_strlen(s) - a) == 10))
			return (0);
		i++;
		j++;
	}
	free (tab);
	return (1);
}

static int 			ft_isdbl(char *s, char **av, int a)
{
	int				i;

	i = 0;
	while (av && av[++i])
	{
		if (!ft_strcmp(s, av[i]) && a != i)
			return (0);
	}
	return (1);
}

static int		ft_check(char **av, int ac)
{
	int			i;

	i = 0;
	while (av && av[++i])
	{
		if (!ft_isint(av[i]))
			return (0);
		if (!ft_isdbl(av[i], av, i))
			return (0);
	}
	(void)ac;
	return (1);
}

void			ft_launch(char **av, int ac)
{
	if (ft_check(av, ac))
		ft_putendl("good check");
	else
		ft_putendl("Error");

	(void)ac;
	(void)av;
}
