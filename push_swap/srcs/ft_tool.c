/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 18:58:20 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/19 15:18:18 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"
#include <stdlib.h>

int					ft_isint(char *s)
{
	int				i;
	char			*tab;
	int				a;
	int				b;

	b = 0;
	while (s[b] == '0' || s[b] == '-' || s[b] == '+')
		b++;
	tab = ft_strdup("2147483647");
	a = b;
	if (((ft_strlen(s) - a) > 10) || (ft_strlen(s) <= 1 && s[0] == '-'))
		return (0);
	if ((ft_strlen(s) - a) == 10 && s[0] == '-')
		tab[9] = (a == 1) ? '8' : '7';
	i = 0 + a;
	while (s && s[i++] != '\0')
	{
		if (!ft_isdigit(s[i - 1]))
			return (0);
		if ((ft_strlen(s) - a) == 10 && (s[i - 1] > tab[i - 1 - a]))
			return (0);
		if ((ft_strlen(s) - a) == 10 && (s[i - 1] < tab[i - 1 - a]))
			return (1);
	}
	return (1);
}

int					ft_isdbl(int s, char **av, int a)
{
	int				i;

	i = 1;
	while (av && av[i] && ((av[i][0] == '-') && ft_isalpha(av[i][1])))
		i++;
	while (av && av[++i])
	{
		if (s == ft_atoi(av[i]) && a != i)
			return (0);
	}
	return (1);
}

int					ft_issort(t_stack p, int m)
{
	int				i;

	i = 0;
	while (i++ < p.size - 1)
	{
		if (m >= 1 && p.tab[i - 1] > p.tab[i])
			return (0);
		if (m <= 0 && p.tab[i - 1] < p.tab[i])
			return (0);
	}
	return (1);
}

int					ft_maxmin(int *tab, int size, int m)
{
	int				i;
	int				val;

	i = 0;
	val = 0;
	while (i < size)
	{
		if (m >= 1 && tab[val] < tab[i])
			val = i;
		if (m <= 0 && tab[val] > tab[i])
			val = i;
		i++;
	}
	return (val);
}

int					ft_issplit(t_stack pa, t_stack pb, int m)
{
	int				a;
	int				b;

	if (m == 1)
	{
		a = ft_maxmin(pa.tab, pa.nb, 0);
		b = ft_maxmin(pb.tab, pb.nb, 1);
		if (pa.tab[a] > pb.tab[b])
			return (1);
		else
			return (0);
	}
	else
	{
		a = ft_maxmin(pa.tab, pa.nb, 1);
		b = ft_maxmin(pb.tab, pb.nb, 0);
		if (pa.tab[a] < pb.tab[b])
			return (1);
		else
			return (0);
	}
}
