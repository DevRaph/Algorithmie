/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 18:57:50 by rpinet            #+#    #+#             */
/*   Updated: 2015/03/19 14:35:33 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"
#include <stdlib.h>

void			ft_print(t_stack pa, t_stack pb, char *sa, char *sb)
{
	if (pa.opt[VB] == '1')
	{
		ft_putstr("\n");
		ft_print_stack(pa, sa);
		ft_print_stack(pb, sb);
		ft_putstr("\n");
	}
}

static void		ft_print_name(char *s)
{
	ft_setbgcolor(235);
	ft_setfgcolor(245);
	ft_putstr(" ");
	ft_putstr(s);
	ft_putstr(" ");
	ft_resetcolor();
	ft_putstr(": ");
}

void			ft_print_stack(t_stack p, char *s)
{
	int			i;
	int			col;

	col = (p.opt[COL] == '1') ? 1 : 0;
	ft_print_name(p.name);
	if (!ft_strncmp(s, "rr", 2) && col)
		ft_setfgcolor((s[2] == 'b') ? 35 : 36);
	else if (!ft_strncmp(s, "r", 1) && col && (s[1] == 'a' || s[1] == 'b'))
		ft_setfgcolor((s[1] == 'b') ? 75 : 76);
	i = -1;
	while (i++ < (p.nb - 1))
	{
		if (!ft_strncmp(s, "ss", 2) && i >= (p.nb - 2) && col)
			ft_setfgcolor(220);
		else if (!ft_strncmp(s, "s", 1) && i >= (p.nb - 2) && col)
			ft_setfgcolor(220);
		if (!ft_strncmp(s, "p", 1) && i >= (p.nb - 1) && col)
			ft_setfgcolor(202);
		ft_putnbr(p.tab[i]);
		if (i < (p.nb - 1))
			ft_putstr(" > ");
	}
	ft_resetcolor();
	ft_putchar(10);
}

t_stack			*ft_create_stack(char **av, int ac, char *s, char *opt)
{
	t_stack		*p;
	int			i;

	if (!(p = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	p->name = s;
	p->opt = opt;
	if (!(p->tab = (int *)malloc(sizeof(int) * ac)))
		return (NULL);
	p->size = ac;
	p->nb = 0;
	if (av != NULL)
	{
		i = 1;
		while (av && av[i])
			i++;
		while (ac--)
			p->tab[p->nb++] = ft_atoi(av[--i]);
	}
	return (p);
}
