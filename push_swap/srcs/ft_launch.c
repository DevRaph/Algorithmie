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
	j = -1;
	while (s && s[i] != '\0')
	{
		if ((!ft_isdigit(s[i])) || (s[i] > tab[j++] && ((ft_strlen(s) - a) == 10)))
			return (0);
		i++;
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
	while (i++ < size)
	{
		if (m >= 1 && tab[val] < tab[i])
			val = i;
		if (m <= 0 && tab[val] > tab[i])
			val = i;
	}
	return (val);
}

static void			ft_exec(t_stack pa, t_stack pb)
{
	int				i;

	ft_print_stack(pa);
	ft_print_stack(pb);
	ft_putstr("\nl'index de la valeur max de la pile a est : ");
	i = ft_maxmin(pa.tab, pa.size, 1);
	ft_putnbr(i);
	if (i < (pa.nb / 2))
		ft_putstr(" partie basse");
	else
		ft_putstr(" partie haute");
	ft_putstr("\nl'index de la valeur min de la pile a est : ");
	i = ft_maxmin(pa.tab, pa.size, 0);	
	ft_putnbr(i);
	if (i < (pa.nb / 2))
		ft_putstr(" partie basse");
	else
		ft_putstr(" partie haute");
	ft_putstr("\nl'index de milieu de la pile est : ");
	ft_putnbr(pa.nb / 2);
	ft_putstr("\nLa pile a est ");
	i = 1;
	if (ft_issort(pa, i))
		ft_putstr("triée ");
	else
		ft_putstr("non triée ");
	if (i >= 1)
		ft_putstr("dans l'ordre croissant");
	else
		ft_putstr("dans l'ordre decroissant");
	ft_putstr("\n\n");
	ft_swaps(pa, '1');
	ft_putstr("\n\n");
	ft_print_stack(pa);
	ft_print_stack(pb);
	ft_putstr("\n\n");
	ft_push_stack(&pa, &pb, 'b');
	ft_push_stack(&pa, &pb, 'b');
	ft_push_stack(&pa, &pb, 'b');
	ft_putstr("\n\n");	
	ft_print_stack(pa);
	ft_print_stack(pb);
	ft_putstr("\n\n");
}

static int			ft_check(char **av, int ac)
{
	int				i;

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

void				ft_launch(char **av, int ac)
{
	t_stack			*pa;
	t_stack			*pb;

	if (ft_check(av, ac))
	{  
		//	ft_putendl("good check");
		pa = ft_create_stack(av, ac, "pile a");
		pb = ft_create_stack(NULL, ac, "pile b");
		ft_exec(*pa, *pb);
	}
	else
		ft_putendl("Error");
}
